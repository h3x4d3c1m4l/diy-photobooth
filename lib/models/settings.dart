import 'dart:io';

import 'package:fluent_ui/fluent_ui.dart';
import 'package:freezed_annotation/freezed_annotation.dart';
import 'package:path/path.dart';
import 'package:toml/toml.dart';

part 'settings.freezed.dart';
part 'settings.g.dart';
part 'settings.enums.dart';

// ///////////// //
// Root settings //
// ///////////// //

@freezed
class Settings with _$Settings implements TomlEncodableValue {
  
  const Settings._();

  const factory Settings({
    @Default(5) int captureDelaySeconds,
    @Default(1.5) double collageAspectRatio,
    @Default(0) double collagePadding,
    @Default(true) bool displayConfetti,
    @Default(true) bool singlePhotoIsCollage,
    @Default("") String templatesFolder,
    @Default(HardwareSettings()) HardwareSettings hardware,
    @Default(OutputSettings()) OutputSettings output,
  }) = _Settings;

  factory Settings.withDefaults() {
    return Settings(
      templatesFolder: _getHome(),
      hardware: HardwareSettings.withDefaults(),
      output: OutputSettings.withDefaults(),
    );
  }

  factory Settings.fromJson(Map<String, Object?> json) => _$SettingsFromJson(json);
  
  @override
  Map<String, dynamic> toTomlValue() => toJson();

}

// ///////////////// //
// Hardware Settings //
// ///////////////// //

@freezed
class HardwareSettings with _$HardwareSettings implements TomlEncodableValue {

  const HardwareSettings._();

  const factory HardwareSettings({
    @Default(LiveViewMethod.webcam) LiveViewMethod liveViewMethod,
    @Default("") String liveViewWebcamId,
    @Default(Flip.horizontally) Flip liveViewFlipImage,
    @Default(CaptureMethod.liveViewSource) CaptureMethod captureMethod,
    @Default(200) int captureDelaySony,
    @Default("") String captureLocation,
    @Default("") String printerName,
    @Default(148) double pageHeight,
    @Default(100) double pageWidth,
    @Default(true) bool usePrinterSettings,
    @Default(0) double printerMarginTop,
    @Default(0) double printerMarginRight,
    @Default(0) double printerMarginBottom,
    @Default(0) double printerMarginLeft,
  }) = _HardwareSettings;

  factory HardwareSettings.withDefaults() {
    return HardwareSettings(
      captureLocation: _getHome(),
    );
  }

  factory HardwareSettings.fromJson(Map<String, Object?> json) => _$HardwareSettingsFromJson(json);
  
  @override
  Map<String, dynamic> toTomlValue() => toJson();

}

// /////////////// //
// Output Settings //
// /////////////// //

@freezed
class OutputSettings with _$OutputSettings implements TomlEncodableValue {

  const OutputSettings._();

  const factory OutputSettings({
    @Default("") String localFolder,
    @Default(80)  int jpgQuality,
    @Default(4.0)  double resolutionMultiplier,
    @Default(ExportFormat.jpgFormat)  ExportFormat exportFormat,
    @Default("https://send.vis.ee/")  String firefoxSendServerUrl,
  }) = _OutputSettings;

  factory OutputSettings.withDefaults() {
    return OutputSettings(
      localFolder: join(_getHome(), "Pictures"),
    );
  }

  factory OutputSettings.fromJson(Map<String, Object?> json) => _$OutputSettingsFromJson(json);

  @override
  Map<String, dynamic> toTomlValue() => toJson();

}

String _getHome() {
  Map<String, String> envVars = Platform.environment;
  if (Platform.isMacOS || Platform.isLinux) {
    return envVars['HOME']!;
  } else if (Platform.isWindows) {
    return envVars['UserProfile']!;
  }
  throw 'Could not find the user\'s home folder: Platform unsupported';
}
