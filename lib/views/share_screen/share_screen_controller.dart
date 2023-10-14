import 'dart:io';

import 'package:loggy/loggy.dart';
import 'package:momento_booth/managers/photos_manager.dart';
import 'package:momento_booth/managers/settings_manager.dart';
import 'package:momento_booth/managers/sfx_manager.dart';
import 'package:momento_booth/managers/stats_manager.dart';
import 'package:momento_booth/rust_bridge/library_bridge.dart';
import 'package:momento_booth/utils/hardware.dart';
import 'package:momento_booth/views/base/screen_controller_base.dart';
import 'package:momento_booth/views/capture_screen/capture_screen.dart';
import 'package:momento_booth/views/collage_maker_screen/collage_maker_screen.dart';
import 'package:momento_booth/views/share_screen/share_screen_view_model.dart';
import 'package:momento_booth/views/start_screen/start_screen.dart';

class ShareScreenController extends ScreenControllerBase<ShareScreenViewModel> with UiLoggy {

  // Initialization/Deinitialization

  ShareScreenController({
    required super.viewModel,
    required super.contextAccessor,
  }) {
    SfxManager.instance.playShareScreenSound();
  }

  void onClickNext() {
    router.go(StartScreen.defaultRoute);
  }
  
  void onClickPrev() {
    loggy.debug("Clicked prev");
    if (PhotosManager.instance.captureMode == CaptureMode.single) {
      PhotosManager.instance.reset(advance: false);
      StatsManager.instance.addRetake();
      router.go(CaptureScreen.defaultRoute);
    } else {
      router.go(CollageMakerScreen.defaultRoute);
    }
  }

  String get ffSendUrl => SettingsManager.instance.settings.output.firefoxSendServerUrl;

  void onClickCloseQR() {
    viewModel.qrShown = false;
    viewModel.sliderKey.currentState!.animateBackward();
  }
  
  Future<void> onClickGetQR() async {
     if (viewModel.qrUrl != null) {
      viewModel.qrShown = true;
      viewModel.sliderKey.currentState!.animateForward();
      return;
    } else if (viewModel.uploadProgress != null) {
      return;
    }

    File file = await PhotosManager.instance.getOutputImageAsTempFile();
    final ext = SettingsManager.instance.settings.output.exportFormat.name.toLowerCase();

    loggy.debug("Uploading ${file.path}");
    var stream = rustLibraryApi.ffsendUploadFile(filePath: file.path, hostUrl: ffSendUrl, downloadFilename: "MomentoBooth image.$ext");

    viewModel
      ..uploadProgress = 0.0
      ..uploadFailed = false;

    stream.listen((event) {
      if (event.isFinished) {
        loggy.debug("Upload complete: ${event.downloadUrl}");

        viewModel
          ..uploadProgress = null
          ..qrUrl = event.downloadUrl
          ..qrShown = true
          ..sliderKey.currentState!.animateForward();

        StatsManager.instance.addUploadedPhoto();
      } else {
        loggy.debug("Uploading: ${event.transferredBytes}/${event.totalBytes} bytes");
        viewModel.uploadProgress = event.transferredBytes / (event.totalBytes ?? 0);
      }
    }).onError((x) {
      loggy.error("Upload failed, file path: ${file.path}", x);
      viewModel
        ..uploadProgress = null
        ..uploadFailed = true;
    });
  }

  int successfulPrints = 0;
  static const _printTextDuration = Duration(seconds: 4);

  void resetPrint() {
    viewModel
      ..printText = successfulPrints > 0 ? "${localizations.genericPrintButton} +1" : localizations.genericPrintButton
      ..printEnabled = true;
  }

  Future<void> onClickPrint() async {
    if (!viewModel.printEnabled) return;

    loggy.debug("Printing photo");

    viewModel
      ..printEnabled = false
      ..printText = localizations.shareScreenPrinting;
    
    // Get photo and print it.
    final pdfData = await PhotosManager.instance.getOutputPDF();
    final bool success = await printPDF(pdfData);

    viewModel.printText = success ? localizations.shareScreenPrinting : localizations.shareScreenPrintUnsuccesful;
    successfulPrints += success ? 1 : 0;
    Future.delayed(_printTextDuration, resetPrint);
  }

}
