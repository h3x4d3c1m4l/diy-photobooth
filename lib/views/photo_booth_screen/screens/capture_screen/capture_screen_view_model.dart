import 'dart:async';
import 'dart:io';

import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:mobx/mobx.dart';
import 'package:momento_booth/hardware_control/gphoto2_camera.dart';
import 'package:momento_booth/hardware_control/photo_capturing/live_view_stream_snapshot_capturer.dart';
import 'package:momento_booth/hardware_control/photo_capturing/photo_capture_method.dart';
import 'package:momento_booth/hardware_control/photo_capturing/sony_remote_photo_capture.dart';
import 'package:momento_booth/main.dart';
import 'package:momento_booth/managers/live_view_manager.dart';
import 'package:momento_booth/managers/mqtt_manager.dart';
import 'package:momento_booth/managers/photos_manager.dart';
import 'package:momento_booth/managers/project_manager.dart';
import 'package:momento_booth/managers/settings_manager.dart';
import 'package:momento_booth/managers/stats_manager.dart';
import 'package:momento_booth/models/capture_state.dart';
import 'package:momento_booth/models/maker_note_data.dart';
import 'package:momento_booth/models/settings.dart';
import 'package:momento_booth/views/base/screen_view_model_base.dart';
import 'package:momento_booth/views/components/imaging/photo_collage.dart';
import 'package:momento_booth/views/photo_booth_screen/screens/share_screen/share_screen.dart';

part 'capture_screen_view_model.g.dart';

class CaptureScreenViewModel = CaptureScreenViewModelBase with _$CaptureScreenViewModel;

abstract class CaptureScreenViewModelBase extends ScreenViewModelBase with Store {

  late final PhotoCaptureMethod capturer;
  bool flashComplete = false;
  bool captureComplete = false;
  static const flashStartDuration = Duration(milliseconds: 50);
  static const flashEndDuration = Duration(milliseconds: 2500);
  static const minimumContinueWait = Duration(milliseconds: 1500);

  int get counterStart => getIt<SettingsManager>().settings.captureDelaySeconds;
  int get autoFocusMsBeforeCapture => getIt<SettingsManager>().settings.hardware.gPhoto2AutoFocusMsBeforeCapture;

  double get collageAspectRatio => getIt<SettingsManager>().settings.collageAspectRatio;
  double get collagePadding => getIt<SettingsManager>().settings.collagePadding;

  @computed
  Duration get photoDelay => Duration(seconds: counterStart) - capturer.captureDelay + flashStartDuration;

  @computed
  Duration get autoFocusDelay => photoDelay - Duration(milliseconds: autoFocusMsBeforeCapture);

  @observable
  bool showCounter = true;

  @observable
  bool showFlash = false;

  @observable
  bool showSpinner = false;

  @computed
  double get opacity => showFlash ? 1.0 : 0.0;

  @computed
  Curve get flashAnimationCurve => Curves.easeOutQuart;

  @computed
  Duration get flashAnimationDuration => showFlash ? flashStartDuration : flashEndDuration;

  /// Global key for controlling the slider widget.
  final GlobalKey<PhotoCollageState> collageKey = GlobalKey<PhotoCollageState>();

  final Completer<void> completer = Completer<void>();

  void collageReady() {
    completer.complete();
  }

  Future<File?> captureCollage() async {
    getIt<PhotosManager>().chosen.clear();
    getIt<PhotosManager>().chosen.add(0);
    final stopwatch = Stopwatch()..start();
    final pixelRatio = getIt<SettingsManager>().settings.output.resolutionMultiplier;
    final format = getIt<SettingsManager>().settings.output.exportFormat;
    final jpgQuality = getIt<SettingsManager>().settings.output.jpgQuality;
    await completer.future;
    getIt<PhotosManager>().outputImage = await collageKey.currentState!.getCollageImage(
      createdByMode: CreatedByMode.single,
      pixelRatio: pixelRatio,
      format: format,
      jpgQuality: jpgQuality,
    );
    logDebug('captureCollage took ${stopwatch.elapsed}');

    return await getIt<PhotosManager>().writeOutput();
  }

  CaptureScreenViewModelBase({
    required super.contextAccessor,
  }) {
    capturer = switch (getIt<SettingsManager>().settings.hardware.captureMethod) {
      CaptureMethod.sonyImagingEdgeDesktop => SonyRemotePhotoCapture(getIt<SettingsManager>().settings.hardware.captureLocation),
      CaptureMethod.liveViewSource => LiveViewStreamSnapshotCapturer(),
      CaptureMethod.gPhoto2 => getIt<LiveViewManager>().gPhoto2Camera!,
    };
    capturer.clearPreviousEvents();

    if (autoFocusMsBeforeCapture > 0 && autoFocusDelay > Duration.zero && capturer is GPhoto2Camera) {
      Future.delayed(autoFocusDelay).then((_) => (capturer as GPhoto2Camera).autoFocus());
    }
    Future.delayed(photoDelay).then((_) => captureAndGetPhoto());
    getIt<MqttManager>().publishCaptureState(CaptureState.countdown);
  }

  Future<void> onCounterFinished() async {
    showFlash = true;
    showCounter = false;
    await Future.delayed(flashAnimationDuration);
    showFlash = false;
    showSpinner = true;
    await Future.delayed(minimumContinueWait);
    flashComplete = true; // Flash is now not actually complete, but after this time we do not care about it anymore.
    navigateAfterCapture();
  }

  Future<void> captureAndGetPhoto() async {
    getIt<MqttManager>().publishCaptureState(CaptureState.capturing);

    try {
      final image = await capturer.captureAndGetPhoto();
      getIt<StatsManager>().addCapturedPhoto();
      getIt<PhotosManager>().photos.add(image);
      if (getIt<ProjectManager>().settings.singlePhotoIsCollage) {
        await captureCollage();
      } else {
        getIt<PhotosManager>().outputImage = image.data;
        await getIt<PhotosManager>().writeOutput();
      }
    } catch (error) {
      logWarning(error);
      final ByteData data = await rootBundle.load('assets/bitmap/capture-error.png');
      getIt<PhotosManager>().outputImage = data.buffer.asUint8List();
    } finally {
      captureComplete = true;
      navigateAfterCapture();
      getIt<MqttManager>().publishCaptureState(CaptureState.idle);
    }
  }

  void navigateAfterCapture() {
    if (!flashComplete || !captureComplete) return;
    getIt<StatsManager>().addCreatedSinglePhoto();
    router.go(ShareScreen.defaultRoute);
  }

}
