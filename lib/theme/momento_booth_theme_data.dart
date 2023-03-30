import 'package:flutter/widgets.dart';
import 'package:freezed_annotation/freezed_annotation.dart';

part 'momento_booth_theme_data.freezed.dart';

@freezed
class MomentoBoothThemeData with _$MomentoBoothThemeData {

  const factory MomentoBoothThemeData({
    // App wide
    required Color defaultPageBackgroundColor,
    required Color primaryColor,

    // Title
    required TextStyle titleStyle,

    // Choose Capture Mode page
    required Color chooseCaptureModeButtonIconColor,
    required BoxShadow chooseCaptureModeButtonShadow,
  }) = _MomentoBoothThemeData;

  factory MomentoBoothThemeData.defaults() => const MomentoBoothThemeData(
    // App wide
    defaultPageBackgroundColor: Color(0xFFFFFFFF),
    primaryColor: Color(0xFF00FF00), // Green

    // Title
    titleStyle: TextStyle(
      fontFamily: "Brandon Grotesque",
      fontSize: 120,
      fontWeight: FontWeight.w300,
      shadows: [
        BoxShadow(
          color: Color(0x66000000),
          offset: Offset(0, 3),
          blurRadius: 4,
        ),
      ],
      color: Color(0xFFFFFFFF),
    ),

    // Choose Capture Mode page
    chooseCaptureModeButtonIconColor: Color(0xE6FFFFFF),
    chooseCaptureModeButtonShadow: BoxShadow(
      color: Color(0x42000000),
      offset: Offset(0, 3),
      blurRadius: 8,
    ),
  );

}