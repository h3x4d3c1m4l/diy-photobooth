import 'dart:typed_data';

import 'package:confetti/confetti.dart';
import 'package:flutter/widgets.dart';
import 'package:momento_booth/managers/photos_manager.dart';
import 'package:momento_booth/managers/settings_manager.dart';
import 'package:momento_booth/views/base/screen_view_model_base.dart';
import 'package:momento_booth/views/custom_widgets/wrappers/slider_widget.dart';
import 'package:mobx/mobx.dart';

part 'share_screen_view_model.g.dart';

class ShareScreenViewModel = ShareScreenViewModelBase with _$ShareScreenViewModel;

enum UploadState {
  notStarted,
  uploading,
  errored,
  done
}

abstract class ShareScreenViewModelBase extends ScreenViewModelBase with Store {

  ShareScreenViewModelBase({
    required super.contextAccessor,
  });

  bool get displayConfetti => SettingsManager.instance.settings.displayConfetti;
  late final ConfettiController confettiController = ConfettiController(duration: const Duration(milliseconds: 100))..play();

  Uint8List get outputImage => PhotosManager.instance.outputImage!;

  @observable
  String qrText = "Get QR";

  @observable
  String printText = "Print";

  @observable
  bool printEnabled = true;

  @observable
  UploadState uploadState = UploadState.notStarted;

  @observable
  bool qrShown = false;

  @observable
  String qrUrl = "";

  CaptureMode get captureMode => PhotosManager.instance.captureMode;
  String get backText => captureMode == CaptureMode.single ? "Retake" : "Change";

  /// Global key for controlling the slider widget.
  GlobalKey<SliderWidgetState> sliderKey = GlobalKey<SliderWidgetState>();

}
