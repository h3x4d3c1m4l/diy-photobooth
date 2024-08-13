#ifndef CRDEVICEPROPERTY_H
#define CRDEVICEPROPERTY_H

#include "CrDefines.h"

#if defined(_MSC_VER)
// Windows definitions
#pragma warning (push)
#pragma warning (disable: 4480)	// warning C4480: 'specifying underlying type for enum' are not treated as standard in VS 2010.

	#ifdef CR_SDK_EXPORTS
		#define SCRSDK_API __declspec(dllexport)
	#else
		#define SCRSDK_API __declspec(dllimport)
	#endif
// End Windows definitions
#else
	#if defined(__GNUC__)
		#ifdef CR_SDK_EXPORTS
			#define SCRSDK_API __attribute__ ((visibility ("default")))
		#else
			#define SCRSDK_API
		#endif
	#endif
#endif

namespace SCRSDK
{
enum CrDevicePropertyCode : CrInt32u
{
	CrDeviceProperty_Undefined 			= 0,

	CrDeviceProperty_S1,
	CrDeviceProperty_AEL,
	CrDeviceProperty_FEL,
	CrDeviceProperty_Reserved1,
	CrDeviceProperty_AWBL,

	CrDeviceProperty_FNumber 			= 0x0100,
	CrDeviceProperty_ExposureBiasCompensation,
	CrDeviceProperty_FlashCompensation,
	CrDeviceProperty_ShutterSpeed,
	CrDeviceProperty_IsoSensitivity,
	CrDeviceProperty_ExposureProgramMode,
	CrDeviceProperty_FileType,
	CrDeviceProperty_JpegQuality,  /* Do not use. Will be removed in the next release. */
	CrDeviceProperty_StillImageQuality = CrDeviceProperty_JpegQuality,
	CrDeviceProperty_WhiteBalance,
	CrDeviceProperty_FocusMode,
	CrDeviceProperty_MeteringMode,
	CrDeviceProperty_FlashMode,
	CrDeviceProperty_WirelessFlash,
	CrDeviceProperty_RedEyeReduction,
	CrDeviceProperty_DriveMode,
	CrDeviceProperty_DRO,
	CrDeviceProperty_ImageSize,
	CrDeviceProperty_AspectRatio,
	CrDeviceProperty_PictureEffect,
	CrDeviceProperty_FocusArea,
	CrDeviceProperty_reserved4,
	CrDeviceProperty_Colortemp,
	CrDeviceProperty_ColorTuningAB,
	CrDeviceProperty_ColorTuningGM,

	CrDeviceProperty_LiveViewDisplayEffect,
	CrDeviceProperty_StillImageStoreDestination,
	CrDeviceProperty_PriorityKeySettings,
	CrDeviceProperty_AFTrackingSensitivity,
	CrDeviceProperty_reserved6,
	CrDeviceProperty_Focus_Magnifier_Setting,
	CrDeviceProperty_DateTime_Settings,
	CrDeviceProperty_NearFar,
	CrDeviceProperty_reserved7,
	CrDeviceProperty_AF_Area_Position,
	CrDeviceProperty_reserved8,
	CrDeviceProperty_reserved9,

	CrDeviceProperty_Zoom_Scale,
	CrDeviceProperty_Zoom_Setting,
	CrDeviceProperty_Zoom_Operation,
	CrDeviceProperty_Movie_File_Format,
	CrDeviceProperty_Movie_Recording_Setting,
	CrDeviceProperty_Movie_Recording_FrameRateSetting,
	CrDeviceProperty_CompressionFileFormatStill,
	CrDeviceProperty_MediaSLOT1_FileType,
	CrDeviceProperty_MediaSLOT2_FileType,
	CrDeviceProperty_MediaSLOT1_JpegQuality,  /* Do not use. Will be removed in the next release. */
	CrDeviceProperty_MediaSLOT1_ImageQuality = CrDeviceProperty_MediaSLOT1_JpegQuality,
	CrDeviceProperty_MediaSLOT2_JpegQuality,  /* Do not use. Will be removed in the next release. */
	CrDeviceProperty_MediaSLOT2_ImageQuality = CrDeviceProperty_MediaSLOT2_JpegQuality,
	CrDeviceProperty_MediaSLOT1_ImageSize,
	CrDeviceProperty_MediaSLOT2_ImageSize,
	CrDeviceProperty_RAW_FileCompressionType,
	CrDeviceProperty_MediaSLOT1_RAW_FileCompressionType,
	CrDeviceProperty_MediaSLOT2_RAW_FileCompressionType,
	CrDeviceProperty_ZoomAndFocusPosition_Save,
	CrDeviceProperty_ZoomAndFocusPosition_Load,

	CrDeviceProperty_IrisModeSetting,
	CrDeviceProperty_ShutterModeSetting,
	CrDeviceProperty_GainControlSetting,
	CrDeviceProperty_GainBaseIsoSensitivity,
	CrDeviceProperty_GainBaseSensitivity,
	CrDeviceProperty_ExposureIndex,
	CrDeviceProperty_BaseLookValue,
	CrDeviceProperty_PlaybackMedia,
	CrDeviceProperty_DispModeSetting,
	CrDeviceProperty_DispMode,
	CrDeviceProperty_TouchOperation,
	CrDeviceProperty_SelectFinder,
	CrDeviceProperty_AutoPowerOffTemperature,
	CrDeviceProperty_BodyKeyLock,
	CrDeviceProperty_ImageID_Num_Setting,
	CrDeviceProperty_ImageID_Num,
	CrDeviceProperty_ImageID_String,
	CrDeviceProperty_ExposureCtrlType,
	CrDeviceProperty_MonitorLUTSetting,
	CrDeviceProperty_FocalDistanceInMeter,
	CrDeviceProperty_FocalDistanceInFeet,
	CrDeviceProperty_FocalDistanceUnitSetting,
	CrDeviceProperty_DigitalZoomScale,
	CrDeviceProperty_ZoomDistance,
	CrDeviceProperty_ZoomDistanceUnitSetting,
	CrDeviceProperty_ShutterModeStatus,
	CrDeviceProperty_ShutterSlow,
	CrDeviceProperty_ShutterSlowFrames,
	CrDeviceProperty_Movie_Recording_ResolutionForMain,
	CrDeviceProperty_Movie_Recording_ResolutionForProxy,
	CrDeviceProperty_Movie_Recording_FrameRateProxySetting,
	CrDeviceProperty_BatteryRemainDisplayUnit,
	CrDeviceProperty_PowerSource,
	CrDeviceProperty_MovieShootingMode,
	CrDeviceProperty_MovieShootingModeColorGamut,
	CrDeviceProperty_MovieShootingModeTargetDisplay,
	CrDeviceProperty_DepthOfFieldAdjustmentMode,
	CrDeviceProperty_ColortempStep,
	CrDeviceProperty_WhiteBalanceModeSetting,
	CrDeviceProperty_WhiteBalanceTint,
	CrDeviceProperty_WhiteBalanceTintStep,
	CrDeviceProperty_Focus_Operation,
	CrDeviceProperty_ShutterECSSetting,
	CrDeviceProperty_ShutterECSNumber,
	CrDeviceProperty_ShutterECSNumberStep,
	CrDeviceProperty_ShutterECSFrequency,
	CrDeviceProperty_RecorderControlProxySetting,
	CrDeviceProperty_ButtonAssignmentAssignable1,
	CrDeviceProperty_ButtonAssignmentAssignable2,
	CrDeviceProperty_ButtonAssignmentAssignable3,
	CrDeviceProperty_ButtonAssignmentAssignable4,
	CrDeviceProperty_ButtonAssignmentAssignable5,
	CrDeviceProperty_ButtonAssignmentAssignable6,
	CrDeviceProperty_ButtonAssignmentAssignable7,
	CrDeviceProperty_ButtonAssignmentAssignable8,
	CrDeviceProperty_ButtonAssignmentAssignable9,
	CrDeviceProperty_ButtonAssignmentLensAssignable1,
	CrDeviceProperty_AssignableButton1,
	CrDeviceProperty_AssignableButton2,
	CrDeviceProperty_AssignableButton3,
	CrDeviceProperty_AssignableButton4,
	CrDeviceProperty_AssignableButton5,
	CrDeviceProperty_AssignableButton6,
	CrDeviceProperty_AssignableButton7,
	CrDeviceProperty_AssignableButton8,
	CrDeviceProperty_AssignableButton9,
	CrDeviceProperty_LensAssignableButton1,
	CrDeviceProperty_FocusModeSetting,
	CrDeviceProperty_ShutterAngle,
	CrDeviceProperty_ShutterSetting,
	CrDeviceProperty_ShutterMode,
	CrDeviceProperty_ShutterSpeedValue,
	CrDeviceProperty_NDFilter,
	CrDeviceProperty_NDFilterModeSetting,
	CrDeviceProperty_NDFilterValue,
	CrDeviceProperty_GainUnitSetting,
	CrDeviceProperty_GaindBValue,
	CrDeviceProperty_AWB,
	CrDeviceProperty_SceneFileIndex,
	CrDeviceProperty_MoviePlayButton,
	CrDeviceProperty_MoviePlayPauseButton,
	CrDeviceProperty_MoviePlayStopButton,
	CrDeviceProperty_MovieForwardButton,
	CrDeviceProperty_MovieRewindButton,
	CrDeviceProperty_MovieNextButton,
	CrDeviceProperty_MoviePrevButton,
	CrDeviceProperty_MovieRecReviewButton,
	CrDeviceProperty_FaceEyeDetectionAF,                         /* Do not use. Will be removed in the next release. */
	CrDeviceProperty_SubjectRecognitionAF = CrDeviceProperty_FaceEyeDetectionAF,
	CrDeviceProperty_AFTransitionSpeed,
	CrDeviceProperty_AFSubjShiftSens,
	CrDeviceProperty_AFAssist,
	CrDeviceProperty_NDPresetOrVariableSwitchingSetting,         /* Do not use. Will be removed in the next release. */
	CrDeviceProperty_NDFilterSwitchingSetting = CrDeviceProperty_NDPresetOrVariableSwitchingSetting,
	CrDeviceProperty_FunctionOfRemoteTouchOperation,
	CrDeviceProperty_RemoteTouchOperation,
	CrDeviceProperty_FollowFocusPositionSetting,
	CrDeviceProperty_FocusBracketShotNumber,
	CrDeviceProperty_FocusBracketFocusRange,

	CrDeviceProperty_ExtendedInterfaceMode,
	CrDeviceProperty_SQRecordingFrameRateSetting,
	CrDeviceProperty_SQFrameRate,
	CrDeviceProperty_SQRecordingSetting,
	CrDeviceProperty_AudioRecording,
	CrDeviceProperty_AudioInputMasterLevel,
	CrDeviceProperty_TimeCodePreset,
	CrDeviceProperty_TimeCodeFormat,
	CrDeviceProperty_TimeCodeRun,
	CrDeviceProperty_TimeCodeMake,
	CrDeviceProperty_UserBitPreset,
	CrDeviceProperty_UserBitTimeRec,
	CrDeviceProperty_ImageStabilizationSteadyShot,
	CrDeviceProperty_Movie_ImageStabilizationSteadyShot,
	CrDeviceProperty_SilentMode,
	CrDeviceProperty_SilentModeApertureDriveInAF,
	CrDeviceProperty_SilentModeShutterWhenPowerOff,
	CrDeviceProperty_SilentModeAutoPixelMapping,
	CrDeviceProperty_ShutterType,
	CrDeviceProperty_PictureProfile,
	CrDeviceProperty_PictureProfile_BlackLevel,
	CrDeviceProperty_PictureProfile_Gamma,
	CrDeviceProperty_PictureProfile_BlackGammaRange,
	CrDeviceProperty_PictureProfile_BlackGammaLevel,
	CrDeviceProperty_PictureProfile_KneeMode,
	CrDeviceProperty_PictureProfile_KneeAutoSet_MaxPoint,
	CrDeviceProperty_PictureProfile_KneeAutoSet_Sensitivity,
	CrDeviceProperty_PictureProfile_KneeManualSet_Point,
	CrDeviceProperty_PictureProfile_KneeManualSet_Slope,
	CrDeviceProperty_PictureProfile_ColorMode,
	CrDeviceProperty_PictureProfile_Saturation,
	CrDeviceProperty_PictureProfile_ColorPhase,
	CrDeviceProperty_PictureProfile_ColorDepthRed,
	CrDeviceProperty_PictureProfile_ColorDepthGreen,
	CrDeviceProperty_PictureProfile_ColorDepthBlue,
	CrDeviceProperty_PictureProfile_ColorDepthCyan,
	CrDeviceProperty_PictureProfile_ColorDepthMagenta,
	CrDeviceProperty_PictureProfile_ColorDepthYellow,
	CrDeviceProperty_PictureProfile_DetailLevel,
	CrDeviceProperty_PictureProfile_DetailAdjustMode,
	CrDeviceProperty_PictureProfile_DetailAdjustVHBalance,       //Picture Profile Detail Adjust V/H Balance
	CrDeviceProperty_PictureProfile_DetailAdjustBWBalance,       //Picture Profile Detail Adjust B/W Balance
	CrDeviceProperty_PictureProfile_DetailAdjustLimit,
	CrDeviceProperty_PictureProfile_DetailAdjustCrispening,
	CrDeviceProperty_PictureProfile_DetailAdjustHiLightDetail,   //Picture Profile Detail Adjust Hi-Light Detail
	CrDeviceProperty_PictureProfile_Copy,
	CrDeviceProperty_CreativeLook,
	CrDeviceProperty_CreativeLook_Contrast,
	CrDeviceProperty_CreativeLook_Highlights,
	CrDeviceProperty_CreativeLook_Shadows,
	CrDeviceProperty_CreativeLook_Fade,
	CrDeviceProperty_CreativeLook_Saturation,
	CrDeviceProperty_CreativeLook_Sharpness,
	CrDeviceProperty_CreativeLook_SharpnessRange,
	CrDeviceProperty_CreativeLook_Clarity,
	CrDeviceProperty_CreativeLook_CustomLook,
	CrDeviceProperty_Movie_ProxyFileFormat,
	CrDeviceProperty_ProxyRecordingSetting,
	CrDeviceProperty_FunctionOfTouchOperation,

	CrDeviceProperty_HighResolutionShutterSpeedSetting,
	CrDeviceProperty_DeleteUserBaseLook,
	CrDeviceProperty_SelectUserBaseLookToEdit,
	CrDeviceProperty_SelectUserBaseLookToSetInPPLUT,
	CrDeviceProperty_UserBaseLookInput,
	CrDeviceProperty_UserBaseLookAELevelOffset,
	CrDeviceProperty_BaseISOSwitchEI,
	CrDeviceProperty_FlickerLessShooting,
	CrDeviceProperty_AudioLevelDisplay,
	CrDeviceProperty_PlaybackVolumeSettings,
	CrDeviceProperty_AutoReview,
	CrDeviceProperty_AudioSignals,
	CrDeviceProperty_HDMIResolutionStillPlay,
	CrDeviceProperty_Movie_HDMIOutputRecMedia,
	CrDeviceProperty_Movie_HDMIOutputResolution,
	CrDeviceProperty_Movie_HDMIOutput4KSetting,
	CrDeviceProperty_Movie_HDMIOutputRAW,
	CrDeviceProperty_Movie_HDMIOutputRawSetting,
	CrDeviceProperty_Movie_HDMIOutputColorGamutForRAWOut,
	CrDeviceProperty_Movie_HDMIOutputTimeCode,
	CrDeviceProperty_Movie_HDMIOutputRecControl,
	CrDeviceProperty_reserved56,
	CrDeviceProperty_MonitoringOutputDisplayHDMI,
	CrDeviceProperty_Movie_HDMIOutputAudioCH,
	CrDeviceProperty_Movie_IntervalRec_IntervalTime,
	CrDeviceProperty_Movie_IntervalRec_FrameRateSetting,
	CrDeviceProperty_Movie_IntervalRec_RecordingSetting,
	CrDeviceProperty_EframingScaleAuto,
	CrDeviceProperty_EframingSpeedAuto,
	CrDeviceProperty_EframingModeAuto,
	CrDeviceProperty_EframingRecordingImageCrop,
	CrDeviceProperty_EframingHDMICrop,
	CrDeviceProperty_CameraEframing,
	CrDeviceProperty_USBPowerSupply,
	CrDeviceProperty_LongExposureNR,
	CrDeviceProperty_HighIsoNR,
	CrDeviceProperty_HLGStillImage,
	CrDeviceProperty_ColorSpace,
	CrDeviceProperty_BracketOrder,
	CrDeviceProperty_FocusBracketOrder,
	CrDeviceProperty_FocusBracketExposureLock1stImg,
	CrDeviceProperty_FocusBracketIntervalUntilNextShot,
	CrDeviceProperty_IntervalRec_ShootingStartTime,
	CrDeviceProperty_IntervalRec_ShootingInterval,
	CrDeviceProperty_IntervalRec_ShootIntervalPriority,
	CrDeviceProperty_IntervalRec_NumberOfShots,
	CrDeviceProperty_IntervalRec_AETrackingSensitivity,
	CrDeviceProperty_IntervalRec_ShutterType,
	CrDeviceProperty_ElectricFrontCurtainShutter,
	CrDeviceProperty_WindNoiseReduct,
	CrDeviceProperty_RecordingSelfTimer,
	CrDeviceProperty_RecordingSelfTimerCountTime,
	CrDeviceProperty_RecordingSelfTimerContinuous,
	CrDeviceProperty_RecordingSelfTimerStatus,
	CrDeviceProperty_BulbTimerSetting,
	CrDeviceProperty_BulbExposureTimeSetting,
	CrDeviceProperty_AutoSlowShutter,
	CrDeviceProperty_IsoAutoMinShutterSpeedMode,
	CrDeviceProperty_IsoAutoMinShutterSpeedManual,
	CrDeviceProperty_IsoAutoMinShutterSpeedPreset,
	CrDeviceProperty_FocusPositionSetting,
	CrDeviceProperty_SoftSkinEffect,
	CrDeviceProperty_PrioritySetInAF_S,
	CrDeviceProperty_PrioritySetInAF_C,
	CrDeviceProperty_FocusMagnificationTime,
	CrDeviceProperty_SubjectRecognitionInAF,
	CrDeviceProperty_RecognitionTarget,
	CrDeviceProperty_RightLeftEyeSelect,
	CrDeviceProperty_SelectFTPServer,
	CrDeviceProperty_SelectFTPServerID,
	CrDeviceProperty_FTP_Function,
	CrDeviceProperty_FTP_AutoTransfer,
	CrDeviceProperty_FTP_AutoTransferTarget,
	CrDeviceProperty_Movie_FTP_AutoTransferTarget,
	CrDeviceProperty_FTP_TransferTarget,
	CrDeviceProperty_Movie_FTP_TransferTarget,
	CrDeviceProperty_FTP_PowerSave,

	CrDeviceProperty_ButtonAssignmentAssignable10,
	CrDeviceProperty_ButtonAssignmentAssignable11,
	CrDeviceProperty_reserved14,
	CrDeviceProperty_reserved15,
	CrDeviceProperty_reserved16,
	CrDeviceProperty_reserved17,
	CrDeviceProperty_AssignableButton10,
	CrDeviceProperty_AssignableButton11,
	CrDeviceProperty_reserved37,
	CrDeviceProperty_reserved38,
	CrDeviceProperty_reserved39,
	CrDeviceProperty_reserved40,
	CrDeviceProperty_NDFilterUnitSetting,
	CrDeviceProperty_NDFilterOpticalDensityValue,
	CrDeviceProperty_TNumber,
	CrDeviceProperty_IrisDisplayUnit,
	CrDeviceProperty_Movie_ImageStabilizationLevel,
	CrDeviceProperty_ImageStabilizationSteadyShotAdjust,
	CrDeviceProperty_ImageStabilizationSteadyShotFocalLength,

	CrDeviceProperty_ExtendedShutterSpeed,
	CrDeviceProperty_CameraButtonFunction,
	CrDeviceProperty_CameraButtonFunctionMulti,
	CrDeviceProperty_CameraDialFunction,

	CrDeviceProperty_SynchroterminalForcedOutput,
	CrDeviceProperty_ShutterReleaseTimeLagControl,
	CrDeviceProperty_ContinuousShootingSpotBoostFrameSpeed,
	CrDeviceProperty_TimeShiftShooting,
	CrDeviceProperty_TimeShiftTriggerSetting,
	CrDeviceProperty_TimeShiftPreShootingTimeSetting,
	CrDeviceProperty_EmbedLUTFile,
	CrDeviceProperty_APS_C_S35,
	CrDeviceProperty_LensCompensationShading,
	CrDeviceProperty_LensCompensationChromaticAberration,
	CrDeviceProperty_LensCompensationDistortion,
	CrDeviceProperty_LensCompensationBreathing,
	CrDeviceProperty_RecordingMedia,
	CrDeviceProperty_Movie_RecordingMedia,
	CrDeviceProperty_AutoSwitchMedia,
	CrDeviceProperty_RecordingFileNumber,
	CrDeviceProperty_Movie_RecordingFileNumber,
	CrDeviceProperty_RecordingSettingFileName,
	CrDeviceProperty_RecordingFolderFormat,
	CrDeviceProperty_CreateNewFolder,
	CrDeviceProperty_SelectIPTCMetadata,
	CrDeviceProperty_WriteCopyrightInfo,
	CrDeviceProperty_SetPhotographer,
	CrDeviceProperty_SetCopyright,
	CrDeviceProperty_FileSettingsTitleNameSettings,
	CrDeviceProperty_FocusBracketRecordingFolder,
	CrDeviceProperty_ReleaseWithoutLens,
	CrDeviceProperty_ReleaseWithoutCard,
	CrDeviceProperty_GridLineDisplay,
	CrDeviceProperty_ContinuousShootingSpeedInElectricShutterHiPlus,
	CrDeviceProperty_ContinuousShootingSpeedInElectricShutterHi,
	CrDeviceProperty_ContinuousShootingSpeedInElectricShutterMid,
	CrDeviceProperty_ContinuousShootingSpeedInElectricShutterLo,
	CrDeviceProperty_IsoAutoRangeLimitMin,
	CrDeviceProperty_IsoAutoRangeLimitMax,
	CrDeviceProperty_FacePriorityInMultiMetering,
	CrDeviceProperty_PrioritySetInAWB,
	CrDeviceProperty_CustomWB_Size_Setting,
	CrDeviceProperty_AFIlluminator,
	CrDeviceProperty_ApertureDriveInAF,
	CrDeviceProperty_AFWithShutter,
	CrDeviceProperty_FullTimeDMF,
	CrDeviceProperty_PreAF,
	CrDeviceProperty_SubjectRecognitionPersonTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionAnimalBirdPriority,
	CrDeviceProperty_SubjectRecognitionAnimalBirdDetectionParts,
	CrDeviceProperty_SubjectRecognitionAnimalTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionAnimalTrackingSensitivity,
	CrDeviceProperty_SubjectRecognitionAnimalDetectionSensitivity,
	CrDeviceProperty_SubjectRecognitionAnimalDetectionParts,
	CrDeviceProperty_SubjectRecognitionBirdTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionBirdTrackingSensitivity,
	CrDeviceProperty_SubjectRecognitionBirdDetectionSensitivity,
	CrDeviceProperty_SubjectRecognitionBirdDetectionParts,
	CrDeviceProperty_SubjectRecognitionInsectTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionInsectTrackingSensitivity,
	CrDeviceProperty_SubjectRecognitionInsectDetectionSensitivity,
	CrDeviceProperty_SubjectRecognitionCarTrainTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionCarTrainTrackingSensitivity,
	CrDeviceProperty_SubjectRecognitionCarTrainDetectionSensitivity,
	CrDeviceProperty_SubjectRecognitionPlaneTrackingSubjectShiftRange,
	CrDeviceProperty_SubjectRecognitionPlaneTrackingSensitivity,
	CrDeviceProperty_SubjectRecognitionPlaneDetectionSensitivity,
	CrDeviceProperty_SubjectRecognitionPriorityOnRegisteredFace,
	CrDeviceProperty_FaceEyeFrameDisplay,
	CrDeviceProperty_FocusMap,
	CrDeviceProperty_InitialFocusMagnifier,
	CrDeviceProperty_AFInFocusMagnifier,
	CrDeviceProperty_AFTrackForSpeedChange,
	CrDeviceProperty_AFFreeSizeAndPositionSetting,
	CrDeviceProperty_ZoomAndFocusPresetZoomOnly_Set,
	CrDeviceProperty_PlaySetOfMultiMedia,
	CrDeviceProperty_RemoteSaveImageSize,
	CrDeviceProperty_FTP_TransferStillImageQualitySize,
	CrDeviceProperty_FTP_AutoTransferTarget_StillImage,
	CrDeviceProperty_ProtectImageInFTPTransfer,
	CrDeviceProperty_MonitorBrightnessType,
	CrDeviceProperty_MonitorBrightnessManual,
	CrDeviceProperty_DisplayQualityFinder,
	CrDeviceProperty_TCUBDisplaySetting,
	CrDeviceProperty_GammaDisplayAssist,
	CrDeviceProperty_GammaDisplayAssistType,
	CrDeviceProperty_AudioSignalsStartEnd,
	CrDeviceProperty_AudioSignalsVolume,
	CrDeviceProperty_ControlForHDMI,
	CrDeviceProperty_AntidustShutterWhenPowerOff,
	CrDeviceProperty_WakeOnLAN,

	CrDeviceProperty_S2 = 0x0500,
	CrDeviceProperty_reserved10,
	CrDeviceProperty_reserved11,
	CrDeviceProperty_reserved12,
	CrDeviceProperty_reserved13,
	CrDeviceProperty_Interval_Rec_Mode,
	CrDeviceProperty_Still_Image_Trans_Size,
	CrDeviceProperty_RAW_J_PC_Save_Image,
	CrDeviceProperty_LiveView_Image_Quality,
	CrDeviceProperty_CustomWB_Capture_Standby,
	CrDeviceProperty_CustomWB_Capture_Standby_Cancel,
	CrDeviceProperty_CustomWB_Capture,
	CrDeviceProperty_Remocon_Zoom_Speed_Type,

	CrDeviceProperty_GetOnly = 0x0700,

	CrDeviceProperty_SnapshotInfo,
	CrDeviceProperty_BatteryRemain,
	CrDeviceProperty_BatteryLevel,
	CrDeviceProperty_EstimatePictureSize,
	CrDeviceProperty_RecordingState,
	CrDeviceProperty_LiveViewStatus,
	CrDeviceProperty_FocusIndication,
	CrDeviceProperty_MediaSLOT1_Status,
	CrDeviceProperty_MediaSLOT1_RemainingNumber,
	CrDeviceProperty_MediaSLOT1_RemainingTime,
	CrDeviceProperty_MediaSLOT1_FormatEnableStatus,
	CrDeviceProperty_reserved20,
	CrDeviceProperty_MediaSLOT2_Status,
	CrDeviceProperty_MediaSLOT2_FormatEnableStatus,
	CrDeviceProperty_MediaSLOT2_RemainingNumber,
	CrDeviceProperty_MediaSLOT2_RemainingTime,
	CrDeviceProperty_reserved22,
	CrDeviceProperty_Media_FormatProgressRate,
	CrDeviceProperty_FTP_ConnectionStatus,
	CrDeviceProperty_FTP_ConnectionErrorInfo,
	CrDeviceProperty_LiveView_Area,
	CrDeviceProperty_reserved26,
	CrDeviceProperty_reserved27,
	CrDeviceProperty_Interval_Rec_Status,
	CrDeviceProperty_CustomWB_Execution_State,
	CrDeviceProperty_CustomWB_Capturable_Area,
	CrDeviceProperty_CustomWB_Capture_Frame_Size,
	CrDeviceProperty_CustomWB_Capture_Operation,
	CrDeviceProperty_reserved32,
	CrDeviceProperty_Zoom_Operation_Status,
	CrDeviceProperty_Zoom_Bar_Information,
	CrDeviceProperty_Zoom_Type_Status,
	CrDeviceProperty_MediaSLOT1_QuickFormatEnableStatus,
	CrDeviceProperty_MediaSLOT2_QuickFormatEnableStatus,
	CrDeviceProperty_Cancel_Media_FormatEnableStatus,
	CrDeviceProperty_Zoom_Speed_Range,

	CrDeviceProperty_SdkControlMode,
	CrDeviceProperty_ContentsTransferStatus,
	CrDeviceProperty_ContentsTransferCancelEnableStatus,
	CrDeviceProperty_ContentsTransferProgress,

	CrDeviceProperty_IsoCurrentSensitivity,
	CrDeviceProperty_CameraSetting_SaveOperationEnableStatus,
	CrDeviceProperty_CameraSetting_ReadOperationEnableStatus,
	CrDeviceProperty_CameraSetting_SaveRead_State,
	CrDeviceProperty_CameraSettingsResetEnableStatus,
	CrDeviceProperty_APS_C_or_Full_SwitchingSetting,
	CrDeviceProperty_APS_C_or_Full_SwitchingEnableStatus,
	CrDeviceProperty_DispModeCandidate,
	CrDeviceProperty_ShutterSpeedCurrentValue,
	CrDeviceProperty_Focus_Speed_Range,
	CrDeviceProperty_NDFilterMode,
	CrDeviceProperty_MoviePlayingSpeed,
	CrDeviceProperty_MediaSLOT1Player,
	CrDeviceProperty_MediaSLOT2Player,
	CrDeviceProperty_BatteryRemainingInMinutes,
	CrDeviceProperty_BatteryRemainingInVoltage,
	CrDeviceProperty_DCVoltage,
	CrDeviceProperty_MoviePlayingState,
	CrDeviceProperty_FocusTouchSpotStatus,
	CrDeviceProperty_FocusTrackingStatus,
	CrDeviceProperty_DepthOfFieldAdjustmentInterlockingMode,
	CrDeviceProperty_RecorderClipName,
	CrDeviceProperty_RecorderControlMainSetting,
	CrDeviceProperty_RecorderStartMain,
	CrDeviceProperty_RecorderStartProxy,
	CrDeviceProperty_RecorderMainStatus,
	CrDeviceProperty_RecorderProxyStatus,
	CrDeviceProperty_RecorderExtRawStatus,
	CrDeviceProperty_RecorderSaveDestination,
	CrDeviceProperty_AssignableButtonIndicator1,
	CrDeviceProperty_AssignableButtonIndicator2,
	CrDeviceProperty_AssignableButtonIndicator3,
	CrDeviceProperty_AssignableButtonIndicator4,
	CrDeviceProperty_AssignableButtonIndicator5,
	CrDeviceProperty_AssignableButtonIndicator6,
	CrDeviceProperty_AssignableButtonIndicator7,
	CrDeviceProperty_AssignableButtonIndicator8,
	CrDeviceProperty_AssignableButtonIndicator9,
	CrDeviceProperty_LensAssignableButtonIndicator1,
	CrDeviceProperty_GaindBCurrentValue,
	CrDeviceProperty_SoftwareVersion,
	CrDeviceProperty_CurrentSceneFileEdited,
	CrDeviceProperty_MovieRecButtonToggleEnableStatus,
	CrDeviceProperty_RemoteTouchOperationEnableStatus,
	CrDeviceProperty_CancelRemoteTouchOperationEnableStatus,
	CrDeviceProperty_LensInformationEnableStatus,
	CrDeviceProperty_FollowFocusPositionCurrentValue,
	CrDeviceProperty_FocusBracketShootingStatus,

	CrDeviceProperty_PixelMappingEnableStatus,
	CrDeviceProperty_TimeCodePresetResetEnableStatus,
	CrDeviceProperty_UserBitPresetResetEnableStatus,
	CrDeviceProperty_SensorCleaningEnableStatus,
	CrDeviceProperty_PictureProfileResetEnableStatus,
	CrDeviceProperty_CreativeLookResetEnableStatus,
	CrDeviceProperty_LensVersionNumber,
	CrDeviceProperty_DeviceOverheatingState,
	CrDeviceProperty_Movie_IntervalRec_CountDownIntervalTime,
	CrDeviceProperty_Movie_IntervalRec_RecordingDuration,

	CrDeviceProperty_HighResolutionShutterSpeed,
	CrDeviceProperty_BaseLookImportOperationEnableStatus,
	CrDeviceProperty_LensModelName,
	CrDeviceProperty_FocusPositionCurrentValue,
	CrDeviceProperty_FocusDrivingStatus,
	CrDeviceProperty_FlickerScanStatus,
	CrDeviceProperty_FlickerScanEnableStatus,
	CrDeviceProperty_FTPServerSettingVersion,
	CrDeviceProperty_FTPServerSettingOperationEnableStatus,
	CrDeviceProperty_FTPTransferSetting_SaveOperationEnableStatus,
	CrDeviceProperty_FTPTransferSetting_ReadOperationEnableStatus,
	CrDeviceProperty_FTPTransferSetting_SaveRead_State,
	CrDeviceProperty_FTPJobListDataVersion,
	CrDeviceProperty_CameraShakeStatus,
	CrDeviceProperty_UpdateBodyStatus,
	CrDeviceProperty_reserved35,
	CrDeviceProperty_MediaSLOT1_WritingState,
	CrDeviceProperty_MediaSLOT2_WritingState,
	CrDeviceProperty_reserved36,
	CrDeviceProperty_MediaSLOT1_RecordingAvailableType,
	CrDeviceProperty_MediaSLOT2_RecordingAvailableType,
	
	CrDeviceProperty_MediaSLOT3_RecordingAvailableType,
	CrDeviceProperty_CameraOperatingMode,
	CrDeviceProperty_PlaybackViewMode,
	CrDeviceProperty_AssignableButtonIndicator10,
	CrDeviceProperty_AssignableButtonIndicator11,
	CrDeviceProperty_reserved41,
	CrDeviceProperty_reserved42,
	CrDeviceProperty_reserved43,
	CrDeviceProperty_reserved44,
	CrDeviceProperty_MediaSLOT3_Status,
	CrDeviceProperty_reserved45,
	CrDeviceProperty_MediaSLOT3_RemainingTime,
	CrDeviceProperty_reserved46,
	CrDeviceProperty_reserved47,
	CrDeviceProperty_MonitoringDeliveringStatus,
	CrDeviceProperty_MonitoringIsDelivering,
	CrDeviceProperty_MonitoringSettingVersion,
	CrDeviceProperty_MonitoringDeliveryTypeSupportInfo,
	CrDeviceProperty_MonitoringReserved,

	CrDeviceProperty_CameraErrorCautionStatus,
	CrDeviceProperty_SystemErrorCautionStatus,
	CrDeviceProperty_CameraButtonFunctionStatus,
	CrDeviceProperty_FlickerLessShootingStatus,
	CrDeviceProperty_ContinuousShootingSpotBoostStatus,
	CrDeviceProperty_ContinuousShootingSpotBoostEnableStatus,
	CrDeviceProperty_TimeShiftShootingStatus,
	CrDeviceProperty_ZoomDrivingStatus,
	CrDeviceProperty_ShootingSelfTimerStatus,
	CrDeviceProperty_CreateNewFolderEnableStatus,
	CrDeviceProperty_ForcedFileNumberResetEnableStatus,
	CrDeviceProperty_DefaultAFFreeSizeAndPositionSetting,
	CrDeviceProperty_TrackingOnAndAFOnEnableStatus,
	CrDeviceProperty_ProgramShiftStatus,
	CrDeviceProperty_MeteredManualLevel,
	CrDeviceProperty_ZoomAndFocusPresetDataVersion,
	CrDeviceProperty_SecondBatteryRemain,
	CrDeviceProperty_SecondBatteryLevel,
	CrDeviceProperty_TotalBatteryRemain,
	CrDeviceProperty_TotalBatteryLevel,
	CrDeviceProperty_BodySerialNumber,

	CrDeviceProperty_MaxVal	= 0x1000,
};

enum CrLiveViewPropertyCode : CrInt32u
{
	CrLiveViewProperty_AF_Area_Position = CrDevicePropertyCode::CrDeviceProperty_AF_Area_Position,
	CrLiveViewProperty_Focus_Magnifier_Position = 0x0122,
	CrLiveViewProperty_FaceFrame = 0x0581,
	CrLiveViewProperty_TrackingFrame = CrDevicePropertyCode::CrDeviceProperty_RemoteTouchOperation,
	CrLiveViewProperty_Level = 0x0582,
	CrLiveViewProperty_LiveViewUndefined = CrDevicePropertyCode::CrDeviceProperty_MaxVal,
	CrLiveViewProperty__LiveViewMaxVal = 0x2000,
};

enum CrSdkControlMode : CrInt32u
{
	CrSdkControlMode_Remote = 0x00000000,
	CrSdkControlMode_ContentsTransfer,
};

// =========================== S1, S2, AEL, FEL, AWBL ===========================
enum CrLockIndicator : CrInt16u
{
	CrLockIndicator_Unknown = 0x0000,
	CrLockIndicator_Unlocked,
	CrLockIndicator_Locked,
};
// ===============================================================================


enum CrPropValueSet : CrInt16
{
	CrPropValueMinus1 = -1,
	CrPropValuePlus1 = 1,
};

// FNumber
// type: CrDataType_UInt16
// value = F number * 100
enum CrFnumberSet : CrInt16u
{
	CrFnumber_Unknown = 0xFFFE, // Display "--"
	CrFnumber_Nothing = 0xFFFF, // Nothing to display
};

// ExposureBiasCompensation
// type: CrDataType_UInt16
// value: compensation value * 1000

// FlashCompensation
// type: CrDataType_UInt16
// value = compensation value * 1000

// ShutterSpeed
// type: CrDataType_UInt32
// value: upper two bytes = numerator, lower two bytes = denominator.
enum CrShutterSpeedSet : CrInt32u
{
	CrShutterSpeed_Bulb = 0x00000000,
	CrShutterSpeed_Nothing = 0xFFFFFFFF, // Nothing to display
};

// IsoSensitivity
// type: CrDataType_UInt32
// value: bit 28-31 extension, bit 24-27 ISO mode, bit 0-23 ISO value
enum CrISOMode : CrInt32u
{
	CrISO_Normal = 0x00,	// ISO setting Normal
	CrISO_MultiFrameNR = 0x01,	// Multi Frame NR
	CrISO_MultiFrameNR_High = 0x02,	// Multi Frame NR High
	CrISO_Ext = 0x10,	// Indicates of extended value
	CrISO_AUTO = 0xFFFFFF,
};
// ===============================================================================

// ShutterSlowFrames
static const CrInt8u CrShutterSlowFrames_Disable = 0x00;

//
// ShutterAngle
static const CrInt32u CrShutterAngle_Disable = 0x00000000;

// MoviePlayingSpeed
// type: CrDataType_UInt64
// value: upper four bytes = numerator, lower four bytes = denominator.
enum CrMoviePlayingSpeed : CrInt64u
{
	CrMoviePlayingSpeed_Nothing = 0xFFFFFFFFFFFFFFFF, // Nothing to display
};

// Focal Distance in Meter/Feet
static const CrInt32u CrFocalDistance_Infinity = 0xFFFFFFFF;

// Battery Remaining in Minutes
static const CrInt32u CrBatteryRemainingInMinutes_Untaken = 0xFFFFFFFF;

// Battery Remaining in Voltage
static const CrInt32u CrBatteryRemainingInVoltage_Untaken = 0xFFFFFFFF;

// DCVoltage
static const CrInt32u CrDCVoltage_Untaken = 0xFFFFFFFF;

// Lens Version Number
#define CrLensVersionNumber_Untaken = "--";

//ND Filter Value
enum CrNDFilterValue : CrInt64u
{
	CrNDFilterValue_Nothing = 0xFFFFFFFFFFFFFFFF // Nothing to display
};

// ExposureProgramMode
enum CrExposureProgram : CrInt32u
{
	CrExposure_M_Manual						= 0x00000001,
	CrExposure_P_Auto,
	CrExposure_A_AperturePriority,
	CrExposure_S_ShutterSpeedPriority,
	CrExposure_Program_Creative,
	CrExposure_Program_Action,
	CrExposure_Portrait,
	CrExposure_Auto							= 0x00008000,
	CrExposure_Auto_Plus,
	CrExposure_P_A,
	CrExposure_P_S,
	CrExposure_Sports_Action,
	CrExposure_Sprots_Action = CrExposure_Sports_Action, /* Do not use. Will be removed in the next release. */
	CrExposure_Sunset,
	CrExposure_Night,
	CrExposure_Landscape,
	CrExposure_Macro,
	CrExposure_HandheldTwilight,
	CrExposure_NightPortrait,
	CrExposure_AntiMotionBlur,
	CrExposure_Pet,
	CrExposure_Gourmet,
	CrExposure_Fireworks,
	CrExposure_HighSensitivity,
	CrExposure_MemoryRecall						= 0x00008020,
	CrExposure_ContinuousPriority_AE_8pics		= 0x00008031,
	CrExposure_ContinuousPriority_AE_10pics,
	CrExposure_ContinuousPriority_AE_12pics,
	CrExposure_3D_SweepPanorama					= 0x00008040,
	CrExposure_SweepPanorama,
	CrExposure_Movie_P							= 0x00008050,
	CrExposure_Movie_A,
	CrExposure_Movie_S,
	CrExposure_Movie_M,
	CrExposure_Movie_Auto,
	CrExposure_Movie_F,
	CrExposure_Movie_SQMotion_P				= 0x00008059,
	CrExposure_Movie_SQMotion_A,
	CrExposure_Movie_SQMotion_S,
	CrExposure_Movie_SQMotion_M,
	CrExposure_Movie_SQMotion_AUTO,
	CrExposure_Movie_SQMotion_F,
	CrExposure_Flash_Off					= 0x00008060,
	CrExposure_PictureEffect				= 0x00008070,
	CrExposure_HiFrameRate_P				= 0x00008080,
	CrExposure_HiFrameRate_A,
	CrExposure_HiFrameRate_S,
	CrExposure_HiFrameRate_M,
	CrExposure_SQMotion_P,
	CrExposure_SQMotion_A,
	CrExposure_SQMotion_S,
	CrExposure_SQMotion_M,
	CrExposure_MOVIE,
	CrExposure_STILL,
	CrExposure_Movie_F_Mode, /* Do not use. Will be removed in the next release. */
	CrExposure_F_MovieOrSQMotion = CrExposure_Movie_F_Mode,
	CrExposure_Movie_IntervalRec_F = 0x00008092,
	CrExposure_Movie_IntervalRec_P,
	CrExposure_Movie_IntervalRec_A,
	CrExposure_Movie_IntervalRec_S,
	CrExposure_Movie_IntervalRec_M,
	CrExposure_Movie_IntervalRec_AUTO,
};

// FileType
enum CrFileType : CrInt16u
{
	CrFileType_None = 0x0000,
	CrFileType_Jpeg,
	CrFileType_Raw,
	CrFileType_RawJpeg,
	CrFileType_RawHeif,
	CrFileType_Heif,
};

// JpegQuality
enum CrJpegQuality : CrInt16u
{
	CrJpegQuality_Unknown = 0x0000,
	CrJpegQuality_Light,
	CrJpegQuality_Standard,
	CrJpegQuality_Fine,
	CrJpegQuality_ExFine,
};  /* Do not use. Will be removed in the next release. */

// ImageQuality
enum CrImageQuality : CrInt16u
{
	CrImageQuality_Unknown  = 0x0000,
	CrImageQuality_Light,
	CrImageQuality_Standard,
	CrImageQuality_Fine,
	CrImageQuality_ExFine,
};

// WhiteBalance
enum CrWhiteBalanceSetting : CrInt16u
{
	CrWhiteBalance_AWB				= 0x0000,
	CrWhiteBalance_Underwater_Auto,
	CrWhiteBalance_Daylight				= 0x0011,
	CrWhiteBalance_Shadow,
	CrWhiteBalance_Cloudy,
	CrWhiteBalance_Tungsten,
	CrWhiteBalance_Fluorescent			= 0x0020,
	CrWhiteBalance_Fluorescent_WarmWhite,
	CrWhiteBalance_Fluorescent_CoolWhite,
	CrWhiteBalance_Fluorescent_DayWhite,
	CrWhiteBalance_Fluorescent_Daylight,
	CrWhiteBalance_Flush				= 0x0030,
	CrWhiteBalance_ColorTemp			= 0x0100,
	CrWhiteBalance_Custom_1,
	CrWhiteBalance_Custom_2,
	CrWhiteBalance_Custom_3,
	CrWhiteBalance_Custom,
};

// FocusMode
enum CrFocusMode : CrInt16u
{
	CrFocus_MF					= 0x0001,
	CrFocus_AF_S,
	CrFocus_AF_C,
	CrFocus_AF_A,
	CrFocus_AF_D,
	CrFocus_DMF,
	CrFocus_PF,
};

// MeteringMode
enum CrMeteringMode : CrInt16u
{
	CrMetering_Average				= 0x0001,
	CrMetering_CenterWeightedAverage,
	CrMetering_MultiSpot,
	CrMetering_CenterSpot,
	CrMetering_Multi,
	CrMetering_CenterWeighted,
	CrMetering_EntireScreenAverage,
	CrMetering_Spot_Standard,
	CrMetering_Spot_Large,
	CrMetering_HighLightWeighted,
};

// FlashMode
enum CrFlashMode : CrInt16u
{
	CrFlash_Auto					= 0x0001,
	CrFlash_Off,
	CrFlash_Fill,
	CrFlash_ExternalSync,
	CrFlash_SlowSync,
	CrFlash_RearSync,
};

// WirelessFlash
enum CrWirelessFlash : CrInt16u
{
	CrWirelessFlash_Off = 0x0000,
	CrWirelessFlash_On,
};

// RedEyeReduction
enum CrRedEyeReduction : CrInt16u
{
	CrRedEye_Off = 0x0000,
	CrRedEye_On,
};

// MediaFormat
enum CrMediaFormat : CrInt8u
{
	CrMediaFormat_Disable = 0x00,
	CrMediaFormat_Enable,
};

// Cancel MediaFormat
enum CrCancelMediaFormat : CrInt8u
{
	CrCancelMediaFormat_Disable = 0x00,
	CrCancelMediaFormat_Enable,
};

// DriveMode
enum CrDriveMode : CrInt32u
{
	CrDrive_Single					= 0x00000001,
	CrDrive_Continuous_Hi				= 0x00010001,
	CrDrive_Continuous_Hi_Plus,
	CrDrive_Continuous_Hi_Live,
	CrDrive_Continuous_Lo,
	CrDrive_Continuous,
	CrDrive_Continuous_SpeedPriority,
	CrDrive_Continuous_Mid,
	CrDrive_Continuous_Mid_Live,
	CrDrive_Continuous_Lo_Live,
	CrDrive_SingleBurstShooting_lo			= 0x00011001,
	CrDrive_SingleBurstShooting_mid,
	CrDrive_SingleBurstShooting_hi,
	CrDrive_FocusBracket					= 0x00012001,
	CrDrive_Timelapse				= 0x00020001,
	CrDrive_Timer_2s				= 0x00030001,
	CrDrive_Timer_5s,
	CrDrive_Timer_10s,
	CrDrive_Continuous_Bracket_03Ev_3pics		= 0x00040301,
	CrDrive_Continuous_Bracket_03Ev_5pics,
	CrDrive_Continuous_Bracket_03Ev_9pics,
	CrDrive_Continuous_Bracket_05Ev_3pics,
	CrDrive_Continuous_Bracket_05Ev_5pics,
	CrDrive_Continuous_Bracket_05Ev_9pics,
	CrDrive_Continuous_Bracket_07Ev_3pics,
	CrDrive_Continuous_Bracket_07Ev_5pics,
	CrDrive_Continuous_Bracket_07Ev_9pics,
	CrDrive_Continuous_Bracket_10Ev_3pics,
	CrDrive_Continuous_Bracket_10Ev_5pics,
	CrDrive_Continuous_Bracket_10Ev_9pics,
	CrDrive_Continuous_Bracket_20Ev_3pics,
	CrDrive_Continuous_Bracket_20Ev_5pics,
	CrDrive_Continuous_Bracket_30Ev_3pics,
	CrDrive_Continuous_Bracket_30Ev_5pics,
	CrDrive_Continuous_Bracket_03Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_03Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_03Ev_7pics,
	CrDrive_Continuous_Bracket_05Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_05Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_05Ev_7pics,
	CrDrive_Continuous_Bracket_07Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_07Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_07Ev_7pics,
	CrDrive_Continuous_Bracket_10Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_10Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_10Ev_7pics,
	CrDrive_Continuous_Bracket_13Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_13Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_13Ev_3pics,
	CrDrive_Continuous_Bracket_13Ev_5pics,
	CrDrive_Continuous_Bracket_13Ev_7pics,
	CrDrive_Continuous_Bracket_15Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_15Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_15Ev_3pics,
	CrDrive_Continuous_Bracket_15Ev_5pics,
	CrDrive_Continuous_Bracket_15Ev_7pics,
	CrDrive_Continuous_Bracket_17Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_17Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_17Ev_3pics,
	CrDrive_Continuous_Bracket_17Ev_5pics,
	CrDrive_Continuous_Bracket_17Ev_7pics,
	CrDrive_Continuous_Bracket_20Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_20Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_20Ev_7pics,
	CrDrive_Continuous_Bracket_23Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_23Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_23Ev_3pics,
	CrDrive_Continuous_Bracket_23Ev_5pics,
	CrDrive_Continuous_Bracket_25Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_25Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_25Ev_3pics,
	CrDrive_Continuous_Bracket_25Ev_5pics,
	CrDrive_Continuous_Bracket_27Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_27Ev_2pics_Minus,
	CrDrive_Continuous_Bracket_27Ev_3pics,
	CrDrive_Continuous_Bracket_27Ev_5pics,
	CrDrive_Continuous_Bracket_30Ev_2pics_Plus,
	CrDrive_Continuous_Bracket_30Ev_2pics_Minus,
	CrDrive_Single_Bracket_03Ev_3pics		= 0x00050001,
	CrDrive_Single_Bracket_03Ev_5pics,
	CrDrive_Single_Bracket_03Ev_9pics,
	CrDrive_Single_Bracket_05Ev_3pics,
	CrDrive_Single_Bracket_05Ev_5pics,
	CrDrive_Single_Bracket_05Ev_9pics,
	CrDrive_Single_Bracket_07Ev_3pics,
	CrDrive_Single_Bracket_07Ev_5pics,
	CrDrive_Single_Bracket_07Ev_9pics,
	CrDrive_Single_Bracket_10Ev_3pics,
	CrDrive_Single_Bracket_10Ev_5pics,
	CrDrive_Single_Bracket_10Ev_9pics,
	CrDrive_Single_Bracket_20Ev_3pics,
	CrDrive_Single_Bracket_20Ev_5pics,
	CrDrive_Single_Bracket_30Ev_3pics,
	CrDrive_Single_Bracket_30Ev_5pics,
	CrDrive_Single_Bracket_03Ev_2pics_Plus,
	CrDrive_Single_Bracket_03Ev_2pics_Minus,
	CrDrive_Single_Bracket_03Ev_7pics,
	CrDrive_Single_Bracket_05Ev_2pics_Plus,
	CrDrive_Single_Bracket_05Ev_2pics_Minus,
	CrDrive_Single_Bracket_05Ev_7pics,
	CrDrive_Single_Bracket_07Ev_2pics_Plus,
	CrDrive_Single_Bracket_07Ev_2pics_Minus,
	CrDrive_Single_Bracket_07Ev_7pics,
	CrDrive_Single_Bracket_10Ev_2pics_Plus,
	CrDrive_Single_Bracket_10Ev_2pics_Minus,
	CrDrive_Single_Bracket_10Ev_7pics,
	CrDrive_Single_Bracket_13Ev_2pics_Plus,
	CrDrive_Single_Bracket_13Ev_2pics_Minus,
	CrDrive_Single_Bracket_13Ev_3pics,
	CrDrive_Single_Bracket_13Ev_5pics,
	CrDrive_Single_Bracket_13Ev_7pics,
	CrDrive_Single_Bracket_15Ev_2pics_Plus,
	CrDrive_Single_Bracket_15Ev_2pics_Minus,
	CrDrive_Single_Bracket_15Ev_3pics,
	CrDrive_Single_Bracket_15Ev_5pics,
	CrDrive_Single_Bracket_15Ev_7pics,
	CrDrive_Single_Bracket_17Ev_2pics_Plus,
	CrDrive_Single_Bracket_17Ev_2pics_Minus,
	CrDrive_Single_Bracket_17Ev_3pics,
	CrDrive_Single_Bracket_17Ev_5pics,
	CrDrive_Single_Bracket_17Ev_7pics,
	CrDrive_Single_Bracket_20Ev_2pics_Plus,
	CrDrive_Single_Bracket_20Ev_2pics_Minus,
	CrDrive_Single_Bracket_20Ev_7pics,
	CrDrive_Single_Bracket_23Ev_2pics_Plus,
	CrDrive_Single_Bracket_23Ev_2pics_Minus,
	CrDrive_Single_Bracket_23Ev_3pics,
	CrDrive_Single_Bracket_23Ev_5pics,
	CrDrive_Single_Bracket_25Ev_2pics_Plus,
	CrDrive_Single_Bracket_25Ev_2pics_Minus,
	CrDrive_Single_Bracket_25Ev_3pics,
	CrDrive_Single_Bracket_25Ev_5pics,
	CrDrive_Single_Bracket_27Ev_2pics_Plus,
	CrDrive_Single_Bracket_27Ev_2pics_Minus,
	CrDrive_Single_Bracket_27Ev_3pics,
	CrDrive_Single_Bracket_27Ev_5pics,
	CrDrive_Single_Bracket_30Ev_2pics_Plus,
	CrDrive_Single_Bracket_30Ev_2pics_Minus,
	CrDrive_WB_Bracket_Lo				= 0x00060001,
	CrDrive_WB_Bracket_Hi,
	CrDrive_DRO_Bracket_Lo				= 0x00070001,
	CrDrive_DRO_Bracket_Hi,
	CrDrive_Continuous_Timer_3pics			= 0x00080001,
	CrDrive_Continuous_Timer_5pics,
	CrDrive_Continuous_Timer_2s_3pics,
	CrDrive_Continuous_Timer_2s_5pics,
	CrDrive_Continuous_Timer_5s_3pics,
	CrDrive_Continuous_Timer_5s_5pics,
	CrDrive_LPF_Bracket				= 0x10000001,
	CrDrive_RemoteCommander,
	CrDrive_MirrorUp,
	CrDrive_SelfPortrait_1,
	CrDrive_SelfPortrait_2,
};

// DRO
enum CrDRangeOptimizer : CrInt16u
{
	CrDRangeOptimizer_Off				= 0x0000,
	CrDRangeOptimizer_On,
	CrDRangeOptimizer_Plus				= 0x0010,
	CrDRangeOptimizer_Plus_Manual_1,
	CrDRangeOptimizer_Plus_Manual_2,
	CrDRangeOptimizer_Plus_Manual_3,
	CrDRangeOptimizer_Plus_Manual_4,
	CrDRangeOptimizer_Plus_Manual_5,
	CrDRangeOptimizer_Auto				= 0x0020,
	CrDRangeOptimizer_HDR_Auto			= 0x0030,
	CrDRangeOptimizer_HDR_10Ev,
	CrDRangeOptimizer_HDR_20Ev,
	CrDRangeOptimizer_HDR_30Ev,
	CrDRangeOptimizer_HDR_40Ev,
	CrDRangeOptimizer_HDR_50Ev,
	CrDRangeOptimizer_HDR_60Ev,
};

// ImageSize
enum CrImageSize: CrInt16u
{
	CrImageSize_L	= 0x0001,
	CrImageSize_M,
	CrImageSize_S,
	CrImageSize_VGA,
};

// AspectRatio
enum CrAspectRatioIndex : CrInt16u
{
	CrAspectRatio_3_2	= 0x0001,
	CrAspectRatio_16_9,
	CrAspectRatio_4_3,
	CrAspectRatio_1_1,
};

// PictureEffect
enum CrPictureEffect : CrInt32u
{
	CrPictureEffect_Off = 0x00000000,
	CrPictureEffect_ToyCameraNormal,
	CrPictureEffect_ToyCameraCool,
	CrPictureEffect_ToyCameraWarm,
	CrPictureEffect_ToyCameraGreen,
	CrPictureEffect_ToyCameraMagenta,
	CrPictureEffect_Pop = 0x00000100,
	CrPictureEffect_PosterizationBW = 0x00000200,
	CrPictureEffect_PosterizationColor,
	CrPictureEffect_Retro = 0x00000300,
	CrPictureEffect_SoftHighkey = 0x00000400,
	CrPictureEffect_PartColorRed = 0x00000500,
	CrPictureEffect_PartColorGreen,
	CrPictureEffect_PartColorBlue,
	CrPictureEffect_PartColorYellow,
	CrPictureEffect_HighContrastMonochrome = 0x00000600,
	CrPictureEffect_SoftFocusLow = 0x00000700,
	CrPictureEffect_SoftFocusMid,
	CrPictureEffect_SoftFocusHigh,
	CrPictureEffect_HDRPaintingLow = 0x00000800,
	CrPictureEffect_HDRPaintingMid,
	CrPictureEffect_HDRPaintingHigh,
	CrPictureEffect_RichToneMonochrome = 0x00000901,
	CrPictureEffect_MiniatureAuto = 0x00000A00,
	CrPictureEffect_MiniatureTop,
	CrPictureEffect_MiniatureMidHorizontal,
	CrPictureEffect_MiniatureBottom,
	CrPictureEffect_MiniatureLeft,
	CrPictureEffect_MiniatureMidVertical,
	CrPictureEffect_MiniatureRight,
	CrPictureEffect_MiniatureWaterColor = 0x00000B00,
	CrPictureEffect_MiniatureIllustrationLow = 0x00000C00,
	CrPictureEffect_MiniatureIllustrationMid,
	CrPictureEffect_MiniatureIllustrationHigh,
};

// Movie Recording State
enum CrMovie_Recording_State : CrInt16u
{
	CrMovie_Recording_State_Not_Recording = 0x0000,
	CrMovie_Recording_State_Recording = 0x0001,
	CrMovie_Recording_State_Recording_Failed = 0x0002,
	CrMovie_Recording_State_IntervalRec_Waiting_Record = 0x0003
};

// FocusArea
enum CrFocusArea : CrInt16u
{
	CrFocusArea_Unknown				= 0x0000,
	CrFocusArea_Wide,
	CrFocusArea_Zone,
	CrFocusArea_Center,
	CrFocusArea_Flexible_Spot_S,
	CrFocusArea_Flexible_Spot_M,
	CrFocusArea_Flexible_Spot_L,
	CrFocusArea_Expand_Flexible_Spot,
	CrFocusArea_Flexible_Spot,
	CrFocusArea_Tracking_Wide		= 0x0011,
	CrFocusArea_Tracking_Zone,
	CrFocusArea_Tracking_Center,
	CrFocusArea_Tracking_Flexible_Spot_S,
	CrFocusArea_Tracking_Flexible_Spot_M,
	CrFocusArea_Tracking_Flexible_Spot_L,
	CrFocusArea_Tracking_Expand_Flexible_Spot,
	CrFocusArea_Tracking_Flexible_Spot,
	CrFocusArea_Flexible_Spot_XS,
	CrFocusArea_Flexible_Spot_XL,
	CrFocusArea_Flexible_Spot_FreeSize1,
	CrFocusArea_Flexible_Spot_FreeSize2,
	CrFocusArea_Flexible_Spot_FreeSize3,
	CrFocusArea_Tracking_Flexible_Spot_XS = 0x0023,
	CrFocusArea_Tracking_Flexible_Spot_XL,
	CrFocusArea_Tracking_Flexible_Spot_FreeSize1,
	CrFocusArea_Tracking_Flexible_Spot_FreeSize2,
	CrFocusArea_Tracking_Flexible_Spot_FreeSize3,
};

// Colortemp
// type unsigned long
// value = color temp (K) step 100

enum CrColortemp : CrInt16u
{
	CrColortemp_Min = 0x0000,
	CrColortemp_Max = 0xFFFF,
};

// ColorTuningAB, ColorTuningGM
enum CrColorTuning : CrInt8u
{
	CrColorTuning_Min = 0x00,
	CrColorTuning_Max = 0xFF,
};


// LiveViewDisplayEffect
enum CrLiveViewDisplayEffect : CrInt16u
{
	CrLiveViewDisplayEffect_Unknown = 0x0000,
	CrLiveViewDisplayEffect_ON,
	CrLiveViewDisplayEffect_OFF,
};

// StillImageStoreDestination
enum CrStillImageStoreDestination : CrInt16u
{
	CrStillImageStoreDestination_HostPC = 0x0001,
	CrStillImageStoreDestination_MemoryCard,
	CrStillImageStoreDestination_HostPCAndMemoryCard,
};

// Near/Far Enable Status
enum CrNearFarEnableStatus : CrInt16u
{
	CrNearFar_Disable,
	CrNearFar_Enable,
};

// IntervalRecMode state
enum CrIntervalRecMode : CrInt16u
{
	CrIntervalRecMode_OFF = 0x0001,
	CrIntervalRecMode_ON,
};

// Buffered image file count
// type unsigned short
// value number of buffered image files.

// Battery Residual Quantity
// type unsigned short
// 0~100: percentage of the battery residual quantity.
static const CrInt16u CrBatteryRemain_Untaken = 0xFFFF;

// Battery Level Indicator
enum CrBatteryLevel : CrInt32u
{
	CrBatteryLevel_PreEndBattery	= 0x00000001,
	CrBatteryLevel_1_4,								// Level 1/4
	CrBatteryLevel_2_4,
	CrBatteryLevel_3_4,
	CrBatteryLevel_4_4,
	CrBatteryLevel_1_3,								// Level 1/3
	CrBatteryLevel_2_3,
	CrBatteryLevel_3_3,
	CrBatteryLevel_USBPowerSupply = 0x00010000,	// USB Power Supply
	CrBatteryLevel_PreEnd_PowerSupply,
	CrBatteryLevel_1_4_PowerSupply,					// Level 1/4 with USB Power Supply
	CrBatteryLevel_2_4_PowerSupply,
	CrBatteryLevel_3_4_PowerSupply,
	CrBatteryLevel_4_4_PowerSupply,
	CrBatteryLevel_Fake = 0xFFFFFFFD,				// Fake
	CrBatteryLevel_BatteryNotInstalled = 0xFFFFFFFE,
};

enum CrWhiteBalanceInitialize : CrInt16u
{
	CrWhiteBalance_Initialized = 0x0001,	// Initialized PTP=0x01
};

// LiveView status
enum CrLiveViewStatus: CrInt16u
{
	CrLiveView_NotSupport				= 0x0000,	// Live view is not supported
	CrLiveView_Disable,								// Live view is supported, but can't get LV image
	CrLiveView_Enable,								// Live view is supported, application can get LV image
};

// Interval Rec status
enum CrIntervalRecStatus : CrInt16u
{
	CrIntervalRecStatus_WaitingStart = 0x0001,
	CrIntervalRecStatus_IntervalShooting,
};

// Focus Indicator
enum CrFocusIndicator : CrInt32u
{
	CrFocusIndicator_Unlocked = 0x00000001,
	CrFocusIndicator_Focused_AF_S = 0x00000102,
	CrFocusIndicator_NotFocused_AF_S = 0x00000202,
	CrFocusIndicator_Focused_AF_C = 0x00000103,
	CrFocusIndicator_NotFocused_AF_C = 0x00000203,
	CrFocusIndicator_TrackingSubject_AF_C = 0x00000303,
};

// Media SLOT Status
enum CrSlotStatus : CrInt16u
{
	CrSlotStatus_OK = 0x0000,
	CrSlotStatus_NoCard,
	CrSlotStatus_CardError,
	CrSlotStatus_RecognizingOrLockedError,
};

enum CrPriorityKeySettings : CrInt16u
{
	CrPriorityKey_CameraPosition = 0x0001,
	CrPriorityKey_PCRemote = 0x0002,
};

enum CrLevelState : CrInt32
{
	CrLevel_Off = 0x00000001,
	CrLevel_On
};

enum CrFocusFrameType : CrInt16u
{
    CrFocusFrameType_Unknown = 0x0000,
	CrFocusFrameType_PhaseDetection_AFSensor = 0x0001,
	CrFocusFrameType_PhaseDetection_ImageSensor,
	CrFocusFrameType_Wide,
	CrFocusFrameType_Zone,
	CrFocusFrameType_CentralEmphasis,
	CrFocusFrameType_ContrastFlexibleMain,
	CrFocusFrameType_ContrastFlexibleAssist,
	CrFocusFrameType_Contrast,
	CrFocusFrameType_FrameSomewhere = 0x000F,
};

// FocusFrameInfoState, FaceFrameState,TrackingFrameState
enum CrFocusFrameState : CrInt16u
{
    CrFocusFrameState_Unknown = 0x0000,
	CrFocusFrameState_NotFocused = 0x0001,
	CrFocusFrameState_Focused,
	CrFocusFrameState_FocusFrameSelection,
	CrFocusFrameState_Moving,
	CrFocusFrameState_RegistrationAF = 0x0006,
	CrFocusFrameState_Island,
};

// FaceFrameInfoSelectState
enum CrFocusFrameSelectState : CrInt8u
{
	CrFocusFrameSelectState_Unknown = 0x00,
};

enum CrTrackingFrameType : CrInt16u
{
	CrTrackingFrameType_Unknown = 0x0000,
	CrTrackingFrameType_NonTargetAF = 0x0001,
	CrTrackingFrameType_TargetAF,
};

enum CrFaceFrameType : CrInt16u
{
	CrFaceFrameType_Unknown = 0x0000,
	CrFaceFrameType_DetectedFace = 0x0001,
	CrFaceFrameType_AF_TargetFace,
	CrFaceFrameType_PersonalRecognitionFace,
	CrFaceFrameType_SmileDetectionFace,
	CrFaceFrameType_SelectedFace,
	CrFaceFrameType_AF_TargetSelectionFace,
	CrFaceFrameType_SmileDetectionSelectFace,
};

enum CrFrameInfoType : CrInt16u
{
    CrFrameInfoType_Unknown = 0x0000,
    CrFrameInfoType_FocusFrameInfo,
	CrFrameInfoType_Magnifier_Position,
	CrFrameInfoType_FaceFrameInfo = 0x0004,
	CrFrameInfoType_TrackingFrameInfo,
	CrFrameInfoType_Level,
};

enum CrPropertyEnableFlag : CrInt16
{
	CrEnableValue_NotSupported = -1,
	CrEnableValue_False = 0,
	CrEnableValue_True,
	CrEnableValue_DisplayOnly,
	CrEnableValue_SetOnly,
};

enum CrPropertyVariableFlag : CrInt16u
{
	CrEnableValue_Invalid,
	CrEnableValue_Invariable,
	CrEnableValue_Variable,
};

enum CrPropertyStillImageTransSize : CrInt16u
{
	CrPropertyStillImageTransSize_Original,
	CrPropertyStillImageTransSize_SmallSize,
	CrPropertyStillImageTransSize_SmallSizeJPEG = CrPropertyStillImageTransSize_SmallSize, /* Do not use. Will be removed in the next release. */
};

enum CrPropertyRAWJPCSaveImage : CrInt16u
{
	CrPropertyRAWJPCSaveImage_RAWAndJPEG,
	CrPropertyRAWJPCSaveImage_JPEGOnly,
	CrPropertyRAWJPCSaveImage_RAWOnly,
	CrPropertyRAWJPCSaveImage_RAWAndHEIF,
	CrPropertyRAWJPCSaveImage_HEIFOnly,
};

enum CrPropertyLiveViewImageQuality : CrInt16u
{
	CrPropertyLiveViewImageQuality_Low,
	CrPropertyLiveViewImageQuality_High,
};

enum CrPropertyCustomWBOperation : CrInt16u
{
	CrPropertyCustomWBOperation_Disable,
	CrPropertyCustomWBOperation_Enable,
};

enum CrPropertyCustomWBExecutionState : CrInt16u
{
	CrPropertyCustomWBExecutionState_Invalid,
	CrPropertyCustomWBExecutionState_Standby,
	CrPropertyCustomWBExecutionState_Capturing,
	CrPropertyCustomWBExecutionState_OperatingCamera,
};

enum CrPropertyCustomWBCaptureButton : CrInt16u
{
	CrPropertyCustomWBCapture_Up,
	CrPropertyCustomWBCapture_Down,
};

// File Format(Movie), Proxy File Format(Movie)
enum CrFileFormatMovie : CrInt8u
{
	CrFileFormatMovie_AVCHD,
	CrFileFormatMovie_MP4,
	CrFileFormatMovie_XAVC_S_4K,
	CrFileFormatMovie_XAVC_S_HD,
	CrFileFormatMovie_XAVC_HS_8K,
	CrFileFormatMovie_XAVC_HS_4K,
	CrFileFormatMovie_XAVC_S_L_4K,
	CrFileFormatMovie_XAVC_S_L_HD,
	CrFileFormatMovie_XAVC_S_I_4K,
	CrFileFormatMovie_XAVC_S_I_HD,
	CrFileFormatMovie_XAVC_I,
	CrFileFormatMovie_XAVC_L,
	CrFileFormatMovie_XAVC_HS_HD,
	CrFileFormatMovie_XAVC_S_I_DCI_4K,
	CrFileFormatMovie_XAVC_H_I_HQ,
	CrFileFormatMovie_XAVC_H_I_SQ,
	CrFileFormatMovie_XAVC_H_L,
	CrFileFormatMovie_X_OCN_XT,
	CrFileFormatMovie_X_OCN_ST,
	CrFileFormatMovie_X_OCN_LT,
};

// Recording Setting(Movie), S&Q Recording Setting, Interval REC(Movie) Record Setting
enum CrRecordingSettingMovie : CrInt16u
{
	CrRecordingSettingMovie_Invalid = 0x0000,	
	CrRecordingSettingMovie_60p_50M = 0x0001,
	CrRecordingSettingMovie_30p_50M,
	CrRecordingSettingMovie_24p_50M,
	CrRecordingSettingMovie_50p_50M,
	CrRecordingSettingMovie_25p_50M,
	CrRecordingSettingMovie_60i_24M,
	CrRecordingSettingMovie_50i_24M_FX,
	CrRecordingSettingMovie_60i_17M_FH,
	CrRecordingSettingMovie_50i_17M_FH,
	CrRecordingSettingMovie_60p_28M_PS,
	CrRecordingSettingMovie_50p_28M_PS,
	CrRecordingSettingMovie_24p_24M_FX,
	CrRecordingSettingMovie_25p_24M_FX,
	CrRecordingSettingMovie_24p_17M_FH,
	CrRecordingSettingMovie_25p_17M_FH,
	CrRecordingSettingMovie_120p_50M_1280x720,
	CrRecordingSettingMovie_100p_50M_1280x720,
	CrRecordingSettingMovie_1920x1080_30p_16M,
	CrRecordingSettingMovie_1920x1080_25p_16M,
	CrRecordingSettingMovie_1280x720_30p_6M,
	CrRecordingSettingMovie_1280x720_25p_6M,
	CrRecordingSettingMovie_1920x1080_60p_28M,
	CrRecordingSettingMovie_1920x1080_50p_28M,
	CrRecordingSettingMovie_60p_25M_XAVC_S_HD,
	CrRecordingSettingMovie_50p_25M_XAVC_S_HD,
	CrRecordingSettingMovie_30p_16M_XAVC_S_HD,
	CrRecordingSettingMovie_25p_16M_XAVC_S_HD,
	CrRecordingSettingMovie_120p_100M_1920x1080_XAVC_S_HD,
	CrRecordingSettingMovie_100p_100M_1920x1080_XAVC_S_HD,
	CrRecordingSettingMovie_120p_60M_1920x1080_XAVC_S_HD,
	CrRecordingSettingMovie_100p_60M_1920x1080_XAVC_S_HD,
	CrRecordingSettingMovie_30p_100M_XAVC_S_4K,
	CrRecordingSettingMovie_25p_100M_XAVC_S_4K,
	CrRecordingSettingMovie_24p_100M_XAVC_S_4K,
	CrRecordingSettingMovie_30p_60M_XAVC_S_4K,
	CrRecordingSettingMovie_25p_60M_XAVC_S_4K,
	CrRecordingSettingMovie_24p_60M_XAVC_S_4K,
	CrRecordingSettingMovie_600M_422_10bit,
	CrRecordingSettingMovie_500M_422_10bit,
	CrRecordingSettingMovie_400M_420_10bit,
	CrRecordingSettingMovie_300M_422_10bit,
	CrRecordingSettingMovie_280M_422_10bit,
	CrRecordingSettingMovie_250M_422_10bit,
	CrRecordingSettingMovie_240M_422_10bit,
	CrRecordingSettingMovie_222M_422_10bit,
	CrRecordingSettingMovie_200M_422_10bit,
	CrRecordingSettingMovie_200M_420_10bit,
	CrRecordingSettingMovie_200M_420_8bit,
	CrRecordingSettingMovie_185M_422_10bit,
	CrRecordingSettingMovie_150M_420_10bit,
	CrRecordingSettingMovie_150M_420_8bit,
	CrRecordingSettingMovie_140M_422_10bit,
	CrRecordingSettingMovie_111M_422_10bit,
	CrRecordingSettingMovie_100M_422_10bit,
	CrRecordingSettingMovie_100M_420_10bit,
	CrRecordingSettingMovie_100M_420_8bit,
	CrRecordingSettingMovie_93M_422_10bit,
	CrRecordingSettingMovie_89M_422_10bit,
	CrRecordingSettingMovie_75M_420_10bit,
	CrRecordingSettingMovie_60M_420_8bit,
	CrRecordingSettingMovie_50M_422_10bit,
	CrRecordingSettingMovie_50M_420_10bit,
	CrRecordingSettingMovie_50M_420_8bit,
	CrRecordingSettingMovie_45M_420_10bit,
	CrRecordingSettingMovie_30M_420_10bit,
	CrRecordingSettingMovie_25M_420_8bit,
	CrRecordingSettingMovie_16M_420_8bit,
	CrRecordingSettingMovie_520M_422_10bit,
	CrRecordingSettingMovie_260M_422_10bit,
};

// Recording Frame Rate Setting(Movie), Recording Frame Rate Proxy Setting(Movie), S&Q Recording Frame Rate Setting
// Interval REC(Movie) Frame Rate
enum CrRecordingFrameRateSettingMovie : CrInt8u
{
	CrRecordingFrameRateSettingMovie_120p = 0x01,
	CrRecordingFrameRateSettingMovie_100p,
	CrRecordingFrameRateSettingMovie_60p,
	CrRecordingFrameRateSettingMovie_50p,
	CrRecordingFrameRateSettingMovie_30p,
	CrRecordingFrameRateSettingMovie_25p,
	CrRecordingFrameRateSettingMovie_24p,
	CrRecordingFrameRateSettingMovie_23_98p,
	CrRecordingFrameRateSettingMovie_29_97p,
	CrRecordingFrameRateSettingMovie_59_94p,
	CrRecordingFrameRateSettingMovie_24_00p = 0x16,
	CrRecordingFrameRateSettingMovie_119_88p,
};

// Compression File Format (Still)
enum CrCompressionFileFormat : CrInt8u
{
	CrCompressionFileFormat_JPEG = 0x01,
	CrCompressionFileFormat_HEIF_422,
	CrCompressionFileFormat_HEIF_420,
};

// Zoom Operation Enable Status
enum CrZoomOperationEnableStatus : CrInt8u
{
	CrZoomOperationEnableStatus_Default = 0x00,
	CrZoomOperationEnableStatus_Disable = 0x00,
	CrZoomOperationEnableStatus_Enable,
};

// Zoom Setting
enum CrZoomSettingType : CrInt8u
{
	CrZoomSetting_OpticalZoomOnly = 0x01,
	CrZoomSetting_SmartZoomOnly,
	CrZoomSetting_On_ClearImageZoom,
	CrZoomSetting_On_DigitalZoom,
};

// Zoom Type Status
enum CrZoomTypeStatus : CrInt8u
{
	CrZoomTypeStatus_OpticalZoom = 0x01,
	CrZoomTypeStatus_SmartZoom,
	CrZoomTypeStatus_ClearImageZoom,
	CrZoomTypeStatus_DigitalZoom,
};

// Zoom Operation
enum CrZoomOperation : CrInt8
{
	CrZoomOperation_Wide = -1,
	CrZoomOperation_Stop = 0,
	CrZoomOperation_Tele = 1,
};

// Remocon Zoom Speed Type
enum CrRemoconZoomSpeedType : CrInt8u
{
	CrRemoconZoomSpeedType_Invalid = 0x00,
	CrRemoconZoomSpeedType_Variable,
	CrRemoconZoomSpeedType_Fixed,
};

// RAW File Type
enum CrRAWFileCompressionType : CrInt16u
{
	CrRAWFile_Uncompression = 0x0000,
	CrRAWFile_Compression,
	CrRAWFile_LossLess,
	CrRAWFile_LossLessS,
	CrRAWFile_LossLessM,
	CrRAWFile_LossLessL,
};

enum CrContentsTransferStatus : CrInt16u
{
	CrContentsTransfer_OFF = 0x0000,
	CrContentsTransfer_ON,
};

enum CrCancelContentsTransferEnableStatus : CrInt16u
{
	CrCancelContentsTransfer_Disable = 0x0000,
	CrCancelContentsTransfer_Enable,
};

// APS-C or Full Switching Setting
enum CrAPS_C_or_Full_SwitchingSetting : CrInt8u
{
	CrAPS_C_or_Full_SwitchingSetting_Full = 0x01,
	CrAPS_C_or_Full_SwitchingSetting_APS_C,
};

// APS-C or Full Switching Enable Status
enum CrAPS_C_or_Full_SwitchingEnableStatus : CrInt8u
{
	CrAPS_C_or_Full_Switching_Disable = 0x00,
	CrAPS_C_or_Full_Switching_Enable,
};

// Camera-Setting Save Operation Enable Status
enum CrCameraSettingSaveOperation : CrInt8u
{
	CrCameraSettingSaveOperation_Disable,
	CrCameraSettingSaveOperation_Enable,
};

// Camera-Setting Read Operation Enable Status
enum CrCameraSettingReadOperation : CrInt8u
{
	CrCameraSettingReadOperation_Disable,
	CrCameraSettingReadOperation_Enable,
};

// Camera-Setting Save/Read State
enum CrCameraSettingSaveReadState : CrInt8u
{
	CrCameraSettingSaveReadState_Idle,
	CrCameraSettingSaveReadState_Reading,
};

enum CrDownloadSettingFileType : CrInt32u
{
	CrDownloadSettingFileType_Setup = 0x00000000,
	CrDownloadSettingFileType_FTPTransferSetting =0x00000002,
	CrDownloadSettingFileType_None = 0xFFFFFFFF,
};

enum CrUploadSettingFileType : CrInt32u
{
	CrUploadSettingFileType_Setup = 0x00001000,
	CrUploadSettingFileType_FTPTransferSetting = 0x00001002,
};

// Playback Media
enum CrPlaybackMedia : CrInt8u
{
	CrPlaybackMedia_Slot1 = 0x01,
	CrPlaybackMedia_Slot2,
};

// Touch Operation
enum CrTouchOperation : CrInt8u
{
	CrTouchOperation_Off = 0x01,
	CrTouchOperation_On,
	CrTouchOperation_PlaybackOnly,
};

// Camera Setting Reset Enable Status
enum CrCameraSettingsResetEnableStatus : CrInt8u
{
	CrCameraSettingsReset_Disable = 0x00,
	CrCameraSettingsReset_Enable,
};

// Auto Power OFF Temperature
enum CrAutoPowerOffTemperature : CrInt8u
{
	CrAutoPowerOffTemperature_Standard = 0x01,
	CrAutoPowerOffTemperature_High,
};

// Body Key Lock
enum CrBodyKeyLock : CrInt8u
{
	CrBodyKey_Unlock = 0x01,
	CrBodyKey_Lock,
};

// Select Finder/Monitor
enum CrSelectFinder : CrInt8u
{
	CrSelectFinder_Auto = 0x01,
	CrSelectFinder_ViewFinder_M,
	CrSelectFinder_Monitor_M,
	CrSelectFinder_Auto2,
};

// Disp Mode
enum CrDispMode : CrInt8u
{
	CrDispMode_GraphicDisplay = 0x01,
	CrDispMode_DisplayAllInfo,
	CrDispMode_NoDispInfo,
	CrDispMode_Histogram,
	CrDispMode_Level,
	CrDispMode_ForViewFinder,
	CrDispMode_MonitorOff,
};

// Disp Mode Bit Num
enum CrDispModeBitNum : CrInt32u
{
	CrDispModeBitNum_GraphicDisplay = 0x00000001,
	CrDispModeBitNum_DisplayAllInfo = 0x00000002,
	CrDispModeBitNum_Histogram = 0x00000004,
	CrDispModeBitNum_Level = 0x00000008,
	CrDispModeBitNum_NoDispInfo = 0x00000010,
	CrDispModeBitNum_NoDispInfoExposureOn = 0x00000020,
	CrDispModeBitNum_NoDispInfoExposureTimeOut = 0x00000040,
	CrDispModeBitNum_ForViewFinder = 0x00000080,
	CrDispModeBitNum_MonitorOff = 0x00000100,
};

// Gain Base Sensitivity
enum CrGainBaseSensitivity : CrInt8u
{
	CrGainBaseSensitivity_High = 0x01,
	CrGainBaseSensitivity_Low,
};

// Gain Base ISO Sensitivity
enum CrGainBaseIsoSensitivity : CrInt8u
{
	CrGainBaseIsoSensitivity_High = 0x01,
	CrGainBaseIsoSensitivity_Low,
};

// BaseLook Value
// type: CrDataType_UInt16
// value: bit bit 8-15 mode, bit 0-7 index
// ex: 0x0003 = index3 (Preset)
// ex: 0x0108 = index8 (User)
enum CrBaseLookValueSetter : CrInt16u
{
	CrBaseLookValue_Preset = 0x00,
	CrBaseLookValue_User = 0x01,
};

// Monitor LUT Setting (All Line)
enum CrMonitorLUTSetting : CrInt8u
{
	CrMonitorLUT_OFF = 0x01,
	CrMonitorLUT_ON,
};

// GetDisplayStringList of Type 
enum CrDisplayStringType : CrInt32u
{
	CrDisplayStringType_AllList = 0x00000000,
	CrDisplayStringType_BaseLook_AELevelOffset_ExposureValue = 0x00000001,
	CrDisplayStringType_BaseLook_Input_Display = 0x00000002,
	CrDisplayStringType_BaseLook_Name_Display = 0x00000003,
	CrDisplayStringType_BaseLook_Output_Display = 0x00000004,
	CrDisplayStringType_SceneFile_Name_Display = 0x00000005,
	CrDisplayStringType_ShootingMode_Cinema_ColorGamut_Display = 0x00000006,
	CrDisplayStringType_ShootingMode_TargetDisplay_Display = 0x00000007,
	CrDisplayStringType_Camera_Gain_BaseISO_Display = 0x00000008,
	CrDisplayStringType_Video_EIGain_Display = 0x00000009,
	CrDisplayStringType_Button_Assign_Display = 0x0000000A,
	CrDisplayStringType_Button_Assign_ShortDisplay = 0x0000000B,
	CrDisplayStringType_FTP_ServerName_Display = 0x0000000C,
	CrDisplayStringType_FTP_UpLoadDirectory_Display = 0x0000000D,
	CrDisplayStringType_FTP_JobStatus_Display = 0x0000000E,
	CrDisplayStringType_Reserved4 = 0x0000000F,
	CrDisplayStringType_Reserved5 = 0x00000010,
	CrDisplayStringType_Reserved6 = 0x00000011,
	CrDisplayStringType_Reserved7 = 0x00000012,
	CrDisplayStringType_CreativeLook_Name_Display = 0x00000013,
	CrDisplayStringType_IPTC_Metadata_Display = 0x00000014,
	CrDisplayStringType_SubjectRecognitionAF_Display = 0x00000015,
	CrDisplayStringType_Reserved11 = 0x00000016,
};

// Image ID (Numerical Value) Setting
enum CrImageIDNumSetting : CrInt8u
{
	CrImageIDNumSetting_Off = 0x01,
	CrImageIDNumSetting_On,
};

// Iris Mode Setting
enum CrIrisModeSetting : CrInt8u
{
	CrIrisMode_Automatic = 0x01,
	CrIrisMode_Manual,
};

// Shutter Mode Setting
enum CrShutterModeSetting : CrInt8u
{
	CrShutterMode_Automatic = 0x01,
	CrShutterMode_Manual,
};

// Exposure Ctrl Type
enum CrExposureCtrlType : CrInt8u
{
	CrExposureCtrlType_PASMMode = 0x01,
	CrExposureCtrlType_FlexibleExposureMode,
};

// Gain Control Setting
enum CrGainControlSetting : CrInt8u
{
	CrGainControl_Automatic = 0x01,
	CrGainControl_Manual,
};

// Focal Distance Unit Setting
enum CrFocalDistanceUnitSetting : CrInt8u
{
	CrFocalDistanceUnitSetting_Meter= 0x01,
	CrFocalDistanceUnitSetting_Feet,
};

// Shutter Mode Status
enum CrShutterModeStatus : CrInt8u
{
	CrShutterModeStatus_Off = 0x01,
	CrShutterModeStatus_Speed,
	CrShutterModeStatus_Angle,
	CrShutterModeStatus_ECS,
	CrShutterModeStatus_Auto,
};

// Shutter Slow
enum CrShutterSlow : CrInt8u
{
	CrShutterSlow_Off = 0x01,
	CrShutterSlow_On,
};

// Do not use. Will be removed in the next release. Please use CrRecordingFrameRateSettingMovie from now on.
//// Recording Frame Rate Proxy Setting(Movie) 
enum CrRecordingFrameRateProxySettingMovie : CrInt8u
{
	CrRecordingFrameRateProxySettingMovie_50p = 0x04,
	CrRecordingFrameRateProxySettingMovie_25p = 0x06,
	CrRecordingFrameRateProxySettingMovie_24p,
	CrRecordingFrameRateProxySettingMovie_23_98p,
	CrRecordingFrameRateProxySettingMovie_29_97p,
	CrRecordingFrameRateProxySettingMovie_59_94p,
	CrRecordingFrameRateProxySettingMovie_24_00p = 0x16,
	CrRecordingFrameRateProxySettingMovie_119_88p,
}; // Do not use. Will be removed in the next release.

// Zoom Distance Unit Setting
enum CrZoomDistanceUnitSetting : CrInt8u
{
	CrZoomDistanceUnitSetting_mm = 0x01,
	CrZoomDistanceUnitSetting_percent,
};

// Battery Remain Display Unit
enum CrBatteryRemainDisplayUnit : CrInt8u
{
	CrBatteryRemainDisplayUnit_minute = 0x01,
	CrBatteryRemainDisplayUnit_percent,
	CrBatteryRemainDisplayUnit_voltage,
};

// Power Source
enum CrPowerSource : CrInt8u
{
	CrPowerSource_DC = 0x01,
	CrPowerSource_Battery,
};

// ND Filter Mode
enum CrNDFilterMode : CrInt8u
{
	CrNDFilterMode_Auto = 0x01,
	CrNDFilterMode_Preset,
	CrNDFilterMode_PresetClear,
	CrNDFilterMode_Variable,
	CrNDFilterMode_VariableClear,
	CrNDFilterMode_Step,
	CrNDFilterMode_StepClear,
};

// Media SLOT Player
enum CrMediaPlayer : CrInt8u
{
	CrMediaPlayer_None = 0x00,
	CrMediaPlayer_Player,
	CrMediaPlayer_Recorder,
	CrMediaPlayer_Player_Recorder,
};

// Movie Playing State
enum CrMoviePlayingState : CrInt8u
{
	CrMoviePlayingState_NotPlaying = 0x00,
	CrMoviePlayingState_Playing,
};

// Movie Shooting Mode Color Gamut
enum CrMovieShootingModeColorGamut : CrInt8u
{
	CrMovieShootingModeColorGamut_S_Gamut3_Cine = 0x01,
	CrMovieShootingModeColorGamut_S_Gamut3,
};

// Depth of Field Adjustment Mode
enum CrDepthOfFieldAdjustmentMode : CrInt8u
{
	CrDepthOfFieldAdjustmentMode_OFF = 0x01,
	CrDepthOfFieldAdjustmentMode_ON,
};

// Focus TouchSpot Status
enum CrFocusTouchSpotStatus : CrInt8u
{
	CrFocusTouchSpotStatus_Stopped = 0x01,
	CrFocusTouchSpotStatus_Running,
};

// Focus Tracking Status
enum CrFocusTrackingStatus : CrInt8u
{
	CrFocusTrackingStatus_OFF = 0x01,
	CrFocusTrackingStatus_Focusing,
	CrFocusTrackingStatus_Tracking,
};

// Depth of Field Adjustment Interlocking Mode State
enum CrDepthOfFieldAdjustmentInterlockingMode : CrInt8u
{
	CrDepthOfFieldAdjustmentInterlockingMode_NDInterlockingMode = 0x01,
	CrDepthOfFieldAdjustmentInterlockingMode_GainInterlockingMode,
};

// Recorder Control Main Setting, Recorder Control Proxy Setting
enum CrRecorderControlSetting : CrInt8u
{
	CrRecorderControlSetting_RecDisable = 0x00,
	CrRecorderControlSetting_RecEnable,
};

// Recorder Start Main,Recorder Start Proxy
enum CrRecorderStart : CrInt8u
{
	CrRecorderStart_RecStartDisable = 0x00,
	CrRecorderStart_RecStartEnable,
};

// Recorder Main Status, Recorder Proxy Status, Recorder Ext Raw Status
enum CrRecorderStatus : CrInt8u
{
	CrRecorderStatus_Idle = 0x00,
	CrRecorderStatus_Ready,
	CrRecorderStatus_PreparingToRecord,
	CrRecorderStatus_Standby,
	CrRecorderStatus_Recording,
	CrRecorderStatus_Stopping,
};

// Recorder Save Destination
enum CrRecorderSaveDestination : CrInt16u
{
	CrRecorderSaveDestination_External = 0x0001,
	CrRecorderSaveDestination_Internal = 0x0010,
	CrRecorderSaveDestination_ExternalAndInternal = 0x0011,
};

// Focus Operation
enum CrFocusOperation : CrInt8
{
	CrFocusOperation_Wide = -1,
	CrFocusOperation_Stop = 0,
	CrFocusOperation_Tele = 1,
};

// Movie Shooting Mode Target Display
enum CrMovieShootingModeTargetDisplay : CrInt8u
{
	CrMovieShootingModeTargetDisplay_BT709 = 0x01,
	CrMovieShootingModeTargetDisplay_BT2020,
};

// Movie Shooting Mode
enum CrMovieShootingMode : CrInt16u
{
	CrMovieShootingMode_Off = 0x0001,
	CrMovieShootingMode_CineEI = 0x0301,
	CrMovieShootingMode_CineEIQuick,
	CrMovieShootingMode_Custom = 0x0401,
	CrMovieShootingMode_FlexibleISO = 0x0501,
};

// Shutter ECS Setting
enum CrShutterECSSetting : CrInt8u
{
	CrShutterECSSetting_OFF = 0x01,
	CrShutterECSSetting_ON,
};

// Focus Mode Setting
enum CrFocusModeSetting : CrInt8u
{
    CrFocusModeSetting_Automatic     = 0x01,
    CrFocusModeSetting_Manual,
};

// Function of Remote Touch Operation
enum CrFunctionOfRemoteTouchOperation : CrInt8u
{
	CrFunctionOfRemoteTouchOperation_Tracking_AF = 0x01,
	CrFunctionOfRemoteTouchOperation_Spot_AF,
	CrFunctionOfRemoteTouchOperation_AFAreaSelect,
};

// Remote Touch Operation Enable Status
enum CrRemoteTouchOperationEnableStatus : CrInt8u
{
	CrRemoteTouchOperation_Disable = 0x00,
	CrRemoteTouchOperation_Enable,
};

// Cancel Remote Touch Operation Enable Status
enum CrCancelRemoteTouchOperationEnableStatus : CrInt8u
{
	CrCancelRemoteTouchOperation_Disable = 0x00,
	CrCancelRemoteTouchOperation_Enable,
};

// Lens Information Enable Status
enum CrLensInformationEnableStatus : CrInt8u
{
	CrLensInformation_Disable = 0x00,
	CrLensInformation_Enable,
};

// White Balance Mode Setting
enum CrWhiteBalanceModeSetting : CrInt8u
{
    CrWhiteBalanceModeSetting_Automatic     = 0x01,
    CrWhiteBalanceModeSetting_Manual,
};

// Shutter Setting
enum CrShutterSetting : CrInt8u
{
    CrShutterSetting_OFF        = 0x01,
    CrShutterSetting_ON,
};

// Shutter Mode
enum CrShutterMode : CrInt8u
{
    CrShutterMode_Speed         = 0x01,
    CrShutterMode_Angle,
};

// ND Filter
enum CrNDFilter : CrInt8u
{
    CrNDFilter_OFF          = 0x01,
    CrNDFilter_ON,
};

// ND Filter Mode Setting
enum CrNDFilterModeSetting : CrInt8u
{
    CrNDFilterModeSetting_Automatic     = 0x01,
    CrNDFilterModeSetting_Manual,
};

// Gain Unit Setting
enum CrGainUnitSetting : CrInt8u
{
    CrGainUnitSetting_dB        = 0x01,
    CrGainUnitSetting_ISO,
};

// AWB
enum CrAWB : CrInt16u
{
    CrAWB_Up    = 0x0001,
    CrAWB_Down,
};

// Current SceneFile Edited
enum CrCurrentSceneFileEdited : CrInt8u
{
    CrCurrentSceneFileEdited_Unedited = 0x01,
    CrCurrentSceneFileEdited_Edited,
};

// Movie Button
enum CrMovieXButton : CrInt16u
{
    CrMovieXButton_Up    = 0x0001,
    CrMovieXButton_Down,
};

// Movie Rec Button(Toggle) Enable Status
enum CrMovieRecButtonToggleEnableStatus : CrInt8u
{
    CrMovieRecButtonToggle_Disable   = 0x00,
    CrMovieRecButtonToggle_Enable,
};

// Do not use. Will be removed in the next release. Please use CrFaceEyeDetectionAF from now on.
//// Face Eye Detection AF
enum CrFaceEyeDetectionAF : CrInt8u
{
	CrFaceEyeDetectionAF_Off = 0x01,
	CrFaceEyeDetectionAF_FaceEyeOnlyAF,
	CrFaceEyeDetectionAF_FaceEyePriorityAF,
};

// Subject Recognition AF
enum CrSubjectRecognitionAF : CrInt8u
{
	CrSubjectRecognitionAF_Off = 0x01,
	CrSubjectRecognitionAF_OnlyAF,
	CrSubjectRecognitionAF_PriorityAF,
};

// AF Assist
enum CrAFAssist : CrInt8u
{
    CrAFAssist_Off = 0x01,
    CrAFAssist_On,
};

// Do not use. Will be removed in the next release. Please use CrNDFilterSwitchingSetting from now on.
//// ND PRESET or VARIABLE Switching Setting
enum CrNDPresetOrVariableSwitchingSetting : CrInt8u
{
	CrNDPresetOrVariableSwitchingSetting_Preset = 0x01,
	CrNDPresetOrVariableSwitchingSetting_Variable,
}; // Do not use. Will be removed in the next release.

// ND Filter Switching Setting
enum CrNDFilterSwitchingSetting : CrInt8u
{
	CrNDFilterSwitchingSetting_Preset = 0x01,
	CrNDFilterSwitchingSetting_Variable,
	CrNDFilterSwitchingSetting_Step,
};

// Lens Information of Type 
enum CrLensInformationType : CrInt32u
{
	CrLensInformationType_Undefined = 0x00000000,
	CrLensInformationType_Feet ,
	CrLensInformationType_Meter,
};

// Assignable/LensAssignable Button Setting
enum CrAssignableButton : CrInt16u
{
	CrAssignableButton_Up = 0x0001,
	CrAssignableButton_Down,
};

//  Assignable/LensAssignable Button Indicator
enum CrAssignableButtonIndicator : CrInt8u
{
	CrAssignableButtonIndicator_Off = 0x1,
	CrAssignableButtonIndicator_On,
};

// Focus Bracket Shooting Status
enum CrFocusBracketShootingStatus : CrInt8u
{
	CrFocusBracket_NotShooting = 0x00,
	CrFocusBracket_Shooting,
};

// Extended Interface Mode
enum CrExtendedInterfaceMode : CrInt8u
{
	CrExtendedInterfaceMode_Off = 0x01,
	CrExtendedInterfaceMode_On,
};

// Pixel Mapping Enable Status
enum CrPixelMappingEnableStatus : CrInt8u
{
	CrPixelMapping_Disable = 0x00,
	CrPixelMapping_Enable,
};

// S&Q Frame Rate
enum CrSQFrameRate : CrInt16u
{
	CrSQFrameRate_Invalid = 0x0000
};

// Audio Recording
enum CrAudioRecording : CrInt8u
{
	CrAudioRecording_Off = 0x00,
	CrAudioRecording_On,
};

//  Time Code Preset Reset Enable Status
enum CrTimeCodePresetResetEnableStatus : CrInt8u
{
	CrTimeCodePresetReset_Disable = 0x00,
	CrTimeCodePresetReset_Enable,
};

//  Time Code Format
enum CrTimeCodeFormat : CrInt8u
{
	CrTimeCodeFormat_DF = 0x01,
	CrTimeCodeFormat_NDF,
};

//  Time Code Run
enum CrTimeCodeRun : CrInt8u
{
	CrTimeCodeRun_RecRun = 0x01,
	CrTimeCodeRun_FreeRun,
};

//  Time Code Make
enum CrTimeCodeMake : CrInt8u
{
	CrTimeCodeMake_Preset = 0x01,
	CrTimeCodeMake_Regenerate,
};

//  User Bit Preset Reset Enable Status
enum CrUserBitPresetResetEnableStatus : CrInt8u
{
	CrUserBitPresetReset_Disable = 0x00,
	CrUserBitPresetReset_Enable,
};

//  User Bit Time Rec
enum CrUserBitTimeRec : CrInt8u
{
	CrUserBitTimeRec_Off = 0x01,
	CrUserBitTimeRec_On,
};

// Image Stabilization Steady Shot
enum CrImageStabilizationSteadyShot : CrInt8u
{
	CrImageStabilizationSteadyShot_Off = 0x01,
	CrImageStabilizationSteadyShot_On,
};

// Image Stabilization Steady Shot(Movie)
enum CrImageStabilizationSteadyShotMovie : CrInt8u
{
	CrImageStabilizationSteadyShotMovie_Off = 0x01,
	CrImageStabilizationSteadyShotMovie_Standard,
	CrImageStabilizationSteadyShotMovie_Active,
	CrImageStabilizationSteadyShotMovie_DynamicActive,
};

// Silent Mode
enum CrSilentMode : CrInt8u
{
	CrSilentMode_Off = 0x01,
	CrSilentMode_On,
};

// Silent Mode Aperture Drive in AF
enum CrSilentModeApertureDriveInAF : CrInt8u
{
	CrSilentModeApertureDriveInAF_NotTarget = 0x01,
	CrSilentModeApertureDriveInAF_Standard,
	CrSilentModeApertureDriveInAF_SilentPriority,
};

// Silent Mode Shutter When Power OFF
enum CrSilentModeShutterWhenPowerOff : CrInt8u
{
	CrSilentModeShutterWhenPowerOff_NotTarget = 0x01,
	CrSilentModeShutterWhenPowerOff_Off,
};

// Silent Mode Auto Pixel Mapping
enum CrSilentModeAutoPixelMapping : CrInt8u
{
	CrSilentModeAutoPixelMapping_NotTarget = 0x01,
	CrSilentModeAutoPixelMapping_Off,
};

// Shutter Type
enum CrShutterType : CrInt8u
{
	CrShutterType_Auto = 0x01,
	CrShutterType_MechanicalShutter,
	CrShutterType_ElectronicShutter,
};

// Picture Profile
enum CrPictureProfile : CrInt8u
{
	CrPictureProfile_Off = 0x00,
	CrPictureProfile_Number1,
	CrPictureProfile_Number2,
	CrPictureProfile_Number3,
	CrPictureProfile_Number4,
	CrPictureProfile_Number5,
	CrPictureProfile_Number6,
	CrPictureProfile_Number7,
	CrPictureProfile_Number8,
	CrPictureProfile_Number9,
	CrPictureProfile_Number10,
	CrPictureProfile_Number11,
	CrPictureProfile_LUT_Number1 = 0x41,
	CrPictureProfile_LUT_Number2,
	CrPictureProfile_LUT_Number3,
	CrPictureProfile_LUT_Number4,
};

// Picture Profile Gamma
enum CrPictureProfileGamma : CrInt16u
{
	CrPictureProfileGamma_Movie = 0x0001,
	CrPictureProfileGamma_Still,
	CrPictureProfileGamma_S_Cinetone,        //S-Cinetone
	CrPictureProfileGamma_Cine1 = 0x0101,
	CrPictureProfileGamma_Cine2,
	CrPictureProfileGamma_Cine3,
	CrPictureProfileGamma_Cine4,
	CrPictureProfileGamma_ITU709 = 0x0201,
	CrPictureProfileGamma_ITU709_800,        //ITU709(800%)
	CrPictureProfileGamma_S_Log2 = 0x0302,   //S-Log2
	CrPictureProfileGamma_S_Log3,            //S-Log3
	CrPictureProfileGamma_HLG = 0x0401,
	CrPictureProfileGamma_HLG1,
	CrPictureProfileGamma_HLG2,
	CrPictureProfileGamma_HLG3
};

// Picture Profile BlackGamma Range
enum CrPictureProfileBlackGammaRange : CrInt8u
{
	CrPictureProfileBlackGammaRange_Wide = 0x01,
	CrPictureProfileBlackGammaRange_Middle,
	CrPictureProfileBlackGammaRange_Narrow
};

// Picture Profile Knee Mode
enum CrPictureProfileKneeMode : CrInt8
{
	CrPictureProfileKneeMode_Auto = 0x01,
	CrPictureProfileKneeMode_Manual
};

// Picture Profile Knee AutoSet MaxPoint & Picture Profile Knee ManualSet Point
// type : CrInt16u
// value : 100 times the value of MaxPoint(%)
//         EX) 0x2616 = 97.50%
enum CrPictureProfileKneeSetPoint : CrInt16u
{
	CrPictureProfileKneeSetPoint_Invalid = 0x0000
};

// Picture Profile Knee AutoSet Sensitivity
enum CrPictureProfileKneeAutoSetSensitivity : CrInt8u
{
	CrPictureProfileKneeAutoSetSensitivity_Low = 0x01,
	CrPictureProfileKneeAutoSetSensitivity_Mid,
	CrPictureProfileKneeAutoSetSensitivity_High
};

// Picture Profile Color Mode
enum CrPictureProfileColorMode : CrInt16u {
	CrPictureProfileColorMode_Movie = 0x0001,
	CrPictureProfileColorMode_Still,
	CrPictureProfileColorMode_S_Cinetone,          //S-Cinetone
	CrPictureProfileColorMode_Cinema,
	CrPictureProfileColorMode_Pro,
	CrPictureProfileColorMode_ITU709_Matrix,       //ITU709 Matrix
	CrPictureProfileColorMode_BlackWhite,          //Black&White
	CrPictureProfileColorMode_S_Gamut3_Cine,       //S-Gamut3.Cine
	CrPictureProfileColorMode_S_Gamut3,
	CrPictureProfileColorMode_BT_2020,             //BT.2020
	CrPictureProfileColorMode_709,
	CrPictureProfileColorMode_S_Gamut
};

// Picture Profile Detail Adjust Mode
enum CrPictureProfileDetailAdjustMode : CrInt8u
{
	CrPictureProfileDetailAdjustMode_Auto = 0x01,
	CrPictureProfileDetailAdjustMode_Manual
};

// Reset Picture Profile Enable Status
enum CrPictureProfileResetEnableStatus : CrInt8u
{
	CrPictureProfileReset_Disable = 0x00,
	CrPictureProfileReset_Enable
};

// Creative Look, Custom Look
// type: CrDataType_UInt16
// value: bit bit 8-15 type, bit 0-7 index
// ex: 0x0103 = Custom Look3
// ex: 0x0008 = SH
enum CrCreativeLook : CrInt16u
{
	CrCreativeLook_ST = 0x0001,
	CrCreativeLook_PT,
	CrCreativeLook_NT,
	CrCreativeLook_VV,
	CrCreativeLook_VV2,
	CrCreativeLook_FL,
	CrCreativeLook_IN,
	CrCreativeLook_SH,
	CrCreativeLook_BW,
	CrCreativeLook_SE,
	CrCreativeLook_CustomLookOffset          = 0x0100
};

// Reset Creative Look Enable Status
enum CrCreativeLookResetEnableStatus : CrInt8u
{
	CrCreativeLookReset_Disable = 0x00,
	CrCreativeLookReset_Enable,
};

// Sensor Cleaning Enable Status
enum CrSensorCleaningEnableStatus : CrInt8u
{
	CrSensorCleaning_Disable = 0x00,
	CrSensorCleaning_Enable,
};

// Proxy Recording Setting
enum CrProxyRecordingSetting : CrInt16u
{
	CrProxyRecordingSetting_Invalid = 0x0000,
	CrProxyRecordingSetting_16M_420_10bit,
	CrProxyRecordingSetting_9M_420_10bit,
	CrProxyRecordingSetting_6M_420_8bit,
};

// Device Overheating State
enum CrDeviceOverheatingState : CrInt8u
{
	CrDeviceOverheatingState_NotOverheating = 0x00,
	CrDeviceOverheatingState_PreOverheating,
	CrDeviceOverheatingState_Overheating,
};

// Function Of Touch Operation
enum CrFunctionOfTouchOperation : CrInt8u
{
	CrFunctionOfTouchOperation_Off = 0x01,
	CrFunctionOfTouchOperation_Shutter,
	CrFunctionOfTouchOperation_Focus,
	CrFunctionOfTouchOperation_Tracking,
	CrFunctionOfTouchOperation_AE,
	CrFunctionOfTouchOperation_ShutterAndAEOn,
	CrFunctionOfTouchOperation_ShutterAndAEOff,
	CrFunctionOfTouchOperation_FocusAndAEOn,
	CrFunctionOfTouchOperation_FocusAndAEOff,
	CrFunctionOfTouchOperation_TrackingAndAEOn,
	CrFunctionOfTouchOperation_TrackingAndAEOff,
};


// AF Tracking Sensitivity
enum CrAFTrackingSensitivity : CrInt8u
{
	CrAFTrackingSensitivity_1 = 0x01,
	CrAFTrackingSensitivity_2,
	CrAFTrackingSensitivity_3,
	CrAFTrackingSensitivity_4,
	CrAFTrackingSensitivity_5,
};

// BaseLookImport Operation Enable Status
enum CrBaseLookImportOperationEnableStatus : CrInt8u
{
	CrBaseLookImportOperation_Disable = 0x00,
	CrBaseLookImportOperation_Enable,
};

// Delete UserBaseLook
enum CrDeleteUserBaseLook : CrInt16u
{
	CrDeleteUserBaseLook_Invalid = 0x0000,
	CrDeleteUserBaseLook_All = 0xFFFF,
};

// Select UserBaseLook to Edit
enum CrSelectUserBaseLookToEdit : CrInt16u
{
	CrSelectUserBaseLookToEdit_Invalid = 0x0000,
};

// Select UserBaseLook to Set in PPLUT
enum CrSelectUserBaseLookToSetInPPLUT : CrInt16u
{
	CrSelectUserBaseLookToSetInPPLUT_Invalid = 0x0000,
};

// UserBaseLook Input
enum CrUserBaseLookInput : CrInt8u
{
	CrUserBaseLookInput_S_Gamut3_SLog3 = 0x01,
	CrUserBaseLookInput_S_Gamut3_Cine_SLog3
};

// UserBaseLook AE Level Offset
// CrDataType_UInt16Array
// e.g.) 0x0203 means 2/3EV

// LUTFile Import BaseLookNumber
enum CrBaseLookNumber : CrInt16u
{
	CrBaseLookNumber_1 = 0x0001,
	CrBaseLookNumber_2,
	CrBaseLookNumber_3,
	CrBaseLookNumber_4,
	CrBaseLookNumber_5,
	CrBaseLookNumber_6,
	CrBaseLookNumber_7,
	CrBaseLookNumber_8,
	CrBaseLookNumber_9,
	CrBaseLookNumber_10,
	CrBaseLookNumber_11,
	CrBaseLookNumber_12,
	CrBaseLookNumber_13,
	CrBaseLookNumber_14,
	CrBaseLookNumber_15,
	CrBaseLookNumber_16,
};

// Base ISO Switch EI
// CrDataType_UInt16Array
// e.g.) If setting with "1600EI", set 0x0640

// Flicker Less Shooting
enum CrFlickerLessShooting : CrInt8u
{
	CrFlickerLessShooting_Off = 0x01,
	CrFlickerLessShooting_On,
};

// Auto Review
enum CrAutoReview : CrInt8u
{
	CrAutoReview_Off = 0x00,
};

// Audio Signals
enum CrAudioSignals : CrInt8u
{
	CrAudioSignals_Off = 0x01,
	CrAudioSignals_On,
	CrAudioSignals_OnShutterOnly,
	CrAudioSignals_OnWithoutShutter,
};

// HDMI Resolution(Still/Play)
// HDMI Output Resolution(Movie)
enum CrHDMIResolution : CrInt16u
{
	CrHDMIResolution_4320p_2160p = 0x0001,
	CrHDMIResolution_2160p,
	CrHDMIResolution_2160p_1080p,
	CrHDMIResolution_1080p,
	CrHDMIResolution_720p,
	CrHDMIResolution_480p,
	CrHDMIResolution_576p,
	CrHDMIResolution_1080i = 0x0104,
	CrHDMIResolution_480i  = 0x0106,
	CrHDMIResolution_576i  = 0x0107,
	CrHDMIResolution_Auto  = 0xFFFF,
};

// HDMI Output Rec Media(Movie)
enum CrHDMIOutputRecMediaMovie : CrInt8u
{
	CrHDMIOutputRecMediaMovie_Off = 0x01, // HDMI only
	CrHDMIOutputRecMediaMovie_On,
};

// HDMI Output 4K Set(Movie)
enum CrHDMIOutput4KSettingMovie : CrInt16u
{
	CrHDMIOutput4KSettingMovie_59_94p_10bit = 0x0001,
	CrHDMIOutput4KSettingMovie_50_00p_10bit,
	CrHDMIOutput4KSettingMovie_29_97p_10bit,
	CrHDMIOutput4KSettingMovie_25_00p_10bit,
	CrHDMIOutput4KSettingMovie_24_00p_10bit,
	CrHDMIOutput4KSettingMovie_23_98p_10bit,
	CrHDMIOutput4KSettingMovie_59_94p_8bit  = 0x0101,
	CrHDMIOutput4KSettingMovie_50_00p_8bit,
	CrHDMIOutput4KSettingMovie_29_97p_8bit,
	CrHDMIOutput4KSettingMovie_25_00p_8bit,
	CrHDMIOutput4KSettingMovie_23_98p_8bit  = 0x0106,
};

// HDMI Output RAW(Movie)
enum CrHDMIOutputRAWMovie : CrInt8u
{
	CrHDMIOutputRAWMovie_Off = 0x01,
	CrHDMIOutputRAWMovie_On,
};

// HDMI Output Raw Setting(Movie)
enum CrHDMIOutputRawSettingMovie : CrInt8u
{
	CrHDMIOutputRawSettingMovie_59_94p = 0x01,
	CrHDMIOutputRawSettingMovie_50_00p,
	CrHDMIOutputRawSettingMovie_29_97p,
	CrHDMIOutputRawSettingMovie_25_00p,
	CrHDMIOutputRawSettingMovie_24_00p,
	CrHDMIOutputRawSettingMovie_23_98p,
};

// HDMI Output Time Code(Movie)
enum CrHDMIOutputTimeCodeMovie : CrInt8u
{
	CrHDMIOutputTimeCodeMovie_Off = 0x01,
	CrHDMIOutputTimeCodeMovie_On,
};

// HDMI Output Rec Control(Movie)
enum CrHDMIOutputRecControlMovie : CrInt8u
{
	CrHDMIOutputRecControlMovie_Off = 0x01,
	CrHDMIOutputRecControlMovie_On,
};

// Monitoring Output Display HDMI
enum CrMonitoringOutputDisplayHDMI : CrInt8u
{
	CrMonitoringOutputDisplayHDMI_Off = 0x01,
	CrMonitoringOutputDisplayHDMI_On,
};

// Audio Output HDMI Monitor CH
enum CrHDMIOutputAudioCH : CrInt16u
{
	CrHDMIOutputAudioCH_CH1CH2 = 0x0003,
	CrHDMIOutputAudioCH_CH3CH4 = 0x000C,
};

// Interval Rec Time(Movie)
enum CrIntervalRecTimeMovie : CrInt32u
{
	CrIntervalRecTimeMovie_1sec     = 0x00000001,
	CrIntervalRecTimeMovie_2sec,
	CrIntervalRecTimeMovie_3sec,
	CrIntervalRecTimeMovie_4sec,
	CrIntervalRecTimeMovie_5sec,
	CrIntervalRecTimeMovie_6sec,
	CrIntervalRecTimeMovie_7sec,
	CrIntervalRecTimeMovie_8sec,
	CrIntervalRecTimeMovie_9sec,
	CrIntervalRecTimeMovie_10sec,
	CrIntervalRecTimeMovie_15sec     = 0x0000000F,
	CrIntervalRecTimeMovie_20sec     = 0x00000014,
	CrIntervalRecTimeMovie_30sec     = 0x0000001E,
	CrIntervalRecTimeMovie_40sec     = 0x00000028,
	CrIntervalRecTimeMovie_50sec     = 0x00000032,
	CrIntervalRecTimeMovie_1min      = 0x0000003C,
	CrIntervalRecTimeMovie_2min      = 0x00000078,
	CrIntervalRecTimeMovie_3min      = 0x000000B4,
	CrIntervalRecTimeMovie_4min      = 0x000000F0,
	CrIntervalRecTimeMovie_5min      = 0x0000012C,
	CrIntervalRecTimeMovie_6min      = 0x00000168,
	CrIntervalRecTimeMovie_7min      = 0x000001A4,
	CrIntervalRecTimeMovie_8min      = 0x000001E0,
	CrIntervalRecTimeMovie_9min      = 0x0000021C,
	CrIntervalRecTimeMovie_10min     = 0x00000258,
	CrIntervalRecTimeMovie_15min     = 0x00000384,
	CrIntervalRecTimeMovie_20min     = 0x000004B0,
	CrIntervalRecTimeMovie_30min     = 0x00000708,
	CrIntervalRecTimeMovie_40min     = 0x00000960,
	CrIntervalRecTimeMovie_50min     = 0x00000BB8,
	CrIntervalRecTimeMovie_1hour     = 0x00000E10,
	CrIntervalRecTimeMovie_2hour     = 0x00001C20,
	CrIntervalRecTimeMovie_3hour     = 0x00002A30,
	CrIntervalRecTimeMovie_4hour     = 0x00003840,
	CrIntervalRecTimeMovie_6hour     = 0x00005460,
	CrIntervalRecTimeMovie_12hour    = 0x0000A8C0,
	CrIntervalRecTimeMovie_24hour    = 0x00015180,
};

// Camera Eframing
enum CrCameraEframing : CrInt8u
{
	CrCameraEframing_Off   = 0x01,
	CrCameraEframing_On,
};

// Eframing Scale(Auto)
enum CrEframingScaleAuto : CrInt8u
{
	CrEframingScaleAuto_Low    = 0x01,
	CrEframingScaleAuto_Mid,
	CrEframingScaleAuto_High,
};

// Eframing Speed(Auto)
// CrDataType_UInt8Range

// Eframing Mode(Auto)
enum CrEframingModeAuto : CrInt8u
{
	CrEframingModeAuto_Auto    = 0x01,
	CrEframingModeAuto_TouchKick,
	CrEframingModeAuto_TimeSequenceA,
	CrEframingModeAuto_TimeSequenceB,
};

// Eframing Recording Image Crop
enum CrEframingRecordingImageCrop : CrInt8u
{
	CrEframingRecordingImageCrop_Off    = 0x01,
	CrEframingRecordingImageCrop_On,
};

// Eframing HDMI Crop
enum CrEframingHDMICrop : CrInt8u
{
	CrEframingHDMICrop_Off    = 0x01,
	CrEframingHDMICrop_On,
};

// USB Power Supply
enum CrUSBPowerSupply : CrInt8u
{
	CrUSBPowerSupply_Off = 0x01,
	CrUSBPowerSupply_On,
};

// Long Exposure NR
enum CrLongExposureNR : CrInt8u
{
	CrLongExposureNR_Off = 0x01,
	CrLongExposureNR_On,
};

// High ISO NR
enum CrHighIsoNR : CrInt8u
{
	CrHighIsoNR_Off = 0x01,
	CrHighIsoNR_Low,
	CrHighIsoNR_Normal,
	CrHighIsoNR_High,
};

// HLG Still Image
enum CrHLGStillImage : CrInt8u
{
	CrHLGStillImage_Off = 0x01,
	CrHLGStillImage_On,
};

// Color Space (Still Image)
enum CrColorSpace : CrInt8u
{
	CrColorSpace_SRGB = 0x01,
	CrColorSpace_AdobeRGB,
};

// Bracket Order
enum CrBracketOrder : CrInt8u
{
	CrBracketOrder_0ToMinusToPlus = 0x01,
	CrBracketOrder_MinusTo0ToPlus,
};

// Focus Bracket Order
enum CrFocusBracketOrder : CrInt8u
{
	CrFocusBracketOrder_0ToMinusToPlus = 0x01,
	CrFocusBracketOrder_0ToPlus,
};

// Focus Bracket Exposure Lock 1st Img
enum CrFocusBracketExposureLock1stImg : CrInt8u
{
	CrFocusBracketExposureLock1stImg_Off = 0x01,
	CrFocusBracketExposureLock1stImg_On,
};

// Focus Bracket Interval Until Next Shot
// CrDataType_UInt16Array
// value : 10times the real value of interval in seconds.
//         0x03E8 approximately equal 100.0 seconds.
enum CrFocusBracketIntervalUntilNextShot : CrInt16u
{
	CrFocusBracketIntervalUntilNextShot_Invalid = 0x0000,
	CrFocusBracketIntervalUntilNextShot_ShortestInterval = 0xFFFF,
};

// IntervalREC(Still) Shooting Start Time
// CrDataType_UInt16Range
//

// IntervalREC(Still) Shooting Interval
// CrDataType_UInt16Range
//

// IntervalREC(Still) Shooting Interval Priority
enum CrIntervalRecShootIntervalPriority : CrInt8u
{
	CrIntervalRecShootIntervalPriority_Off = 0x01,
	CrIntervalRecShootIntervalPriority_On
};

// IntervalREC(Still) Number of Shots
// CrDataType_UInt16Range
//

// IntervalREC(Still) AE Tracking Sensitivity
enum CrIntervalRecAETrackingSensitivity : CrInt8u
{
	CrIntervalRecAETrackingSensitivity_Off = 0x01,
	CrIntervalRecAETrackingSensitivity_Low,
	CrIntervalRecAETrackingSensitivity_Mid,
	CrIntervalRecAETrackingSensitivity_High,
};

// IntervalREC(Still) Shutter Type
enum CrIntervalRecShutterType : CrInt8u
{
	CrIntervalRecShutterType_Auto = 0x01,
	CrIntervalRecShutterType_MechanicalShutter,
	CrIntervalRecShutterType_ElectronicShutter,
};

// High Resolution Shutter Speed Setting
enum CrHighResolutionShutterSpeedSetting : CrInt8u
{
	CrHighResolutionShutterSpeedSetting_Off = 0x00,
	CrHighResolutionShutterSpeedSetting_On
};

// High Resolution Shutter Speed
// CrDataType_UInt64Range
// Upper four bytes: numerator, Lower four bytes: denominator.
enum CrHighResolutionShutterSpeed : CrInt64u
{
	CrHighResolutionShutterSpeed_Nothing = 0xFFFFFFFFFFFFFFFF, // Nothing to display
};

// Wind Noise Reduction
enum CrWindNoiseReduction : CrInt8u
{
	CrWindNoiseReduction_Off = 0x01,
	CrWindNoiseReduction_On,
	CrWindNoiseReduction_Auto
};

// Movie Recording Self timer
enum CrMovieRecordingSelfTimer : CrInt8u
{
	CrMovieRecordingSelfTimer_Off = 0x00,
	CrMovieRecordingSelfTimer_On,
};

// Movie Recording Self timer Count time
enum CrMovieRecordingSelfTimerCountTime : CrInt16u
{
	CrMovieRecordingSelfTimerCountTime_None = 0x0000, // Not counting down
};

// Movie Recording Self timer Continuous
enum CrMovieRecordingSelfTimerContinuous : CrInt8u
{
	CrMovieRecordingSelfTimerContinuous_Off = 0x00,
	CrMovieRecordingSelfTimerContinuous_On,
};

// Movie Recording Self timer Status
enum CrMovieRecordingSelfTimerStatus : CrInt8u
{
	CrMovieRecordingSelfTimerStatus_Idle = 0x00,
	CrMovieRecordingSelfTimerStatus_CountingDown,
};

// Bulb Timer Setting
enum CrBulbTimerSetting : CrInt8u
{
	CrBulbTimerSetting_Off = 0x00,
	CrBulbTimerSetting_On,
};

// Bulb Exposure Time Setting
// CrDataType_UInt16Range
//

// Auto Slow Shutter
enum CrAutoSlowShutter : CrInt8u
{
	CrAutoSlowShutter_Off = 0x01,
	CrAutoSlowShutter_On,
};

// ISO Auto Min Shutter Speed Mode
enum CrIsoAutoMinShutterSpeedMode : CrInt8u
{
	CrIsoAutoMinShutterSpeedMode_Preset = 0x01,
	CrIsoAutoMinShutterSpeedMode_Manual,
};

// ISO Auto Min Shutter Speed Manual
// CrDataType_UInt64Array
// Upper two bytes: numerator, Lower two bytes: denominator
// In the case of the shutter speed is displayed as "Real Number" on the camera, the denominator is fixed 0x0000000A.
// e.g.) 0x0000000F0000000A: 0x0000000F (means 15) / 0x00000000A (means 10) = 1.5"
// In the case of the shutter speed is displayed as "Fraction Number" on the camera, the numerator is fixed 0x00000001.
// e.g.) 0x00000001000003E8: 0x00000001 (means 1) / 0x000003E8 (means 1000) = 1/1000
enum CrIsoAutoMinShutterSpeedManual : CrInt64u
{
	CrIsoAutoMinShutterSpeedManual_Invalid = 0x0000000000000000,
};

// ISO Auto Min Shutter Speed Preset
enum CrIsoAutoMinShutterSpeedPreset : CrInt8u
{
	CrIsoAutoMinShutterSpeedPreset_Slower = 0x01,
	CrIsoAutoMinShutterSpeedPreset_Slow,
	CrIsoAutoMinShutterSpeedPreset_Standard,
	CrIsoAutoMinShutterSpeedPreset_Fast,
	CrIsoAutoMinShutterSpeedPreset_Faster,
};

// Focus Position Setting
// CrDataType_UInt16Range

// Focus Position Current Value
// CrDataType_UInt16Range

// Focus Driving Status
enum CrFocusDrivingStatus : CrInt8u
{
	CrFocusDrivingStatus_NotDriving = 0x01,
	CrFocusDrivingStatus_Driving,
};

// Soft Skin Effect
enum CrSoftSkinEffect : CrInt8u
{
	CrSoftSkinEffect_Off = 0x01,
	CrSoftSkinEffect_Low,
	CrSoftSkinEffect_Mid,
	CrSoftSkinEffect_High,
};

// Priority Set in AF-S/AF-C
enum CrPrioritySetInAF : CrInt8u
{
	CrPrioritySetInAF_AF = 0x01,
	CrPrioritySetInAF_Release,
	CrPrioritySetInAF_BalancedEmphasis,
};

// Focus Magnification Time
enum CrFocusMagnificationTime : CrInt8u
{
	CrFocusMagnificationTime_NoLimit  = 0xFF,
};

// Subject Recognition in AF
enum CrSubjectRecognitionInAF : CrInt8u
{
	CrSubjectRecognitionInAF_Off = 0x01,
	CrSubjectRecognitionInAF_On,
};

// Recognition Target
enum CrRecognitionTarget : CrInt16u
{
	CrRecognitionTarget_Person = 0x0001,
	CrRecognitionTarget_AnimalBird,
	CrRecognitionTarget_Animal,
	CrRecognitionTarget_Bird,
	CrRecognitionTarget_Insect,
	CrRecognitionTarget_CarTrain,
	CrRecognitionTarget_Plane,
};

// Right/Left Eye Select
enum CrRightLeftEyeSelect : CrInt8u
{
	CrRightLeftEyeSelect_Auto = 0x01,
	CrRightLeftEyeSelect_RightEye,
	CrRightLeftEyeSelect_LeftEye,
};

// Select FTP Server
// CrDataType_UInt8Array

// Select FTP ServerID (ILME-FX6)
// CrDataType_UInt32Array
enum CrSelectFTPServerID : CrInt32u
{
	CrSelectFTPServerID_Nothing = 0xFFFFFFFF, // Nothing to display
};

// FTP Connection Status
enum CrFTPConnectionStatus : CrInt8u
{
	CrFTPConnectionStatus_Connecting = 0x01,
	CrFTPConnectionStatus_Connected,
	CrFTPConnectionStatus_Connected_ServerError,
	CrFTPConnectionStatus_ConnectionError,
};

// FTP Connection Error Info
enum CrFTPConnectionErrorInfo : CrInt16u
{
	CrFTPConnectionErrorInfo_Unknown = 0xFFFF,
	CrFTPConnectionErrorInfo_NoError = 0x0000,
	CrFTPConnectionErrorInfo_CameraSystemError,
	CrFTPConnectionErrorInfo_WiFi_HardwareError,
	CrFTPConnectionErrorInfo_WiredLAN_HardwareError,
	CrFTPConnectionErrorInfo_AP_NotReg,
	CrFTPConnectionErrorInfo_AP_NotFound,
	CrFTPConnectionErrorInfo_AP_ConnectionError,
	CrFTPConnectionErrorInfo_AP_PasswordError,
	CrFTPConnectionErrorInfo_InvalidKeyError_WEP_StaticIPAddrSettingError,
	CrFTPConnectionErrorInfo_InvalidKeyError_WEP_IPAddrAcquisitionError,
	CrFTPConnectionErrorInfo_DHCP_IPAddrAcquisitionError,
	CrFTPConnectionErrorInfo_DNS_IPAddrAcquisitionError,
	CrFTPConnectionErrorInfo_AirplaneModeON,
	CrFTPConnectionErrorInfo_LANCableError,
	CrFTPConnectionErrorInfo_FTPServerSettingNotSet,
	CrFTPConnectionErrorInfo_FTPServerSettingError,
	CrFTPConnectionErrorInfo_FTPServerSevered,
	CrFTPConnectionErrorInfo_CertificateError,
	CrFTPConnectionErrorInfo_DirectoryCreateError,
	CrFTPConnectionErrorInfo_AuthorityError_FTPServerOverCapacity,
	CrFTPConnectionErrorInfo_CantRecognizeUSBAdapter,
	CrFTPConnectionErrorInfo_CantRecognizeUSBDevice,
	CrFTPConnectionErrorInfo_CheckConnectDevice,
	CrFTPConnectionErrorInfo_Reconnecting_FailedConnectServer,
	CrFTPConnectionErrorInfo_Reconnecting_CantTransfer,
};

// FTP Server Setting Version, FTP Job List Data Version
// CrDataType_UInt16
// value = Version * 100. 0x0064 = 1.00

// FTP Server Setting Operation Enable Status
enum CrFTPServerSettingOperationEnableStatus : CrInt8u
{
	CrFTPServerSettingOperation_Disable = 0x00,
	CrFTPServerSettingOperation_Enable,
};

// FTP Transfer Setting Save Operation Enable Status
enum CrFTPTransferSettingSaveOperationEnableStatus : CrInt8u
{
	CrFTPTransferSettingSaveOperation_Disable = 0x00,
	CrFTPTransferSettingSaveOperation_Enable,
};

// FTP Transfer Setting Read Operation Enable Status
enum CrFTPTransferSettingReadOperationEnableStatus : CrInt8u
{
	CrFTPTransferSettingReadOperation_Disable = 0x00,
	CrFTPTransferSettingReadOperation_Enable,
};

// FTP Transfer Setting Save/Read State
enum CrFTPTransferSettingSaveReadState : CrInt8u
{
	CrFTPTransferSettingSaveReadState_Idle = 0x00,
	CrFTPTransferSettingSaveReadState_Reading,
};

//	FTP Function
enum CrFTPFunction : CrInt8u
{
	CrFTPFunction_Off = 0x01,
	CrFTPFunction_On,
};

//	Auto FTP Transfer
enum CrFTPAutoTransfer : CrInt8u
{
	CrFTPAutoTransfer_Off = 0x01,
	CrFTPAutoTransfer_On,
};

//	Auto FTP Transfer Target FileType (Still and/or Movie)
enum CrFTPAutoTransferTarget : CrInt8u
{
	CrFTPAutoTransferTarget_StillOnly = 0x01,
	CrFTPAutoTransferTarget_MovieOnly,
	CrFTPAutoTransferTarget_StillAndMovie,
};

//	Auto FTP Transfer Target(Movie)
enum CrFTPAutoTransferTargetMovie : CrInt8u
{
	CrFTPAutoTransferTargetMovie_All = 0x01,
	CrFTPAutoTransferTargetMovie_OnlyShotMark,
	CrFTPAutoTransferTargetMovie_ProtectOnly,
};

//	FTP Transfer Target(Still)
enum CrFTPTransferTargetStill : CrInt8u
{
	CrFTPTransferTargetStill_JpegHeifOnly = 0x01,
	CrFTPTransferTargetStill_RawOnly,
	CrFTPTransferTargetStill_RawAndJpegHeif,
};

//	FTP Transfer Target(Movie)
enum CrFTPTransferTargetMovie : CrInt8u
{
	CrFTPTransferTargetMovie_ProxyOnly = 0x01,
	CrFTPTransferTargetMovie_OriginalOnly,
	CrFTPTransferTargetMovie_OriginalAndProxy,
};

//	FTP Power Save
enum CrFTPPowerSave : CrInt8u
{
	CrFTPPowerSave_Off = 0x01,
	CrFTPPowerSave_On,
};

// Flicker Scan Status
enum CrFlickerScanStatus : CrInt8u
{
	CrFlickerScanStatus_Invalid = 0x00,
	CrFlickerScanStatus_Idle,
	CrFlickerScanStatus_FlickerScanning,
};

// Flicker Scan Enable Status
enum CrFlickerScanEnableStatus : CrInt8u
{
	CrFlickerScan_Disable = 0x00,
	CrFlickerScan_Enable,
};

// CameraShakeStatus 
enum CrCameraShakeStatus : CrInt8u
{
	CrCameraShakeStatus_NoError = 0x01,
	CrCameraShakeStatus_Error
};

// UpdateBodyStatus
enum CrUpdateStatus : CrInt16u
{
	CrUpdateStatus_NoError                 = 0x0001,
	CrUpdateStatus_OtherError              = 0x0101,
	CrUpdateStatus_NoUpdateFileInMedia,
	CrUpdateStatus_FileVersionOlder,
	CrUpdateStatus_FileDamaged,
	CrUpdateStatus_FileInvalidData,
	CrUpdateStatus_FileModelNotMatch,
	CrUpdateStatus_FileRegionNotMatch,
	CrUpdateStatus_FileVersionNotMatch,
	CrUpdateStatus_LowBattery,
	CrUpdateStatus_UnsupportedBattery,
};

// Media SLOT Writing State
enum CrMediaSlotWritingState : CrInt8u
{
	CrMediaSlotWritingState_NotWriting = 0x01,
	CrMediaSlotWritingState_ContentsWriting
};

// Media SLOT Recording Available Type
enum CrMediaSlotRecordingAvailableType : CrInt8u
{
	CrMediaSlotRecordingAvailableType_None = 0x00,
	CrMediaSlotRecordingAvailableType_Main,
	CrMediaSlotRecordingAvailableType_Proxy,
	CrMediaSlotRecordingAvailableType_MainAndProxy,
};

//	FTP Server Service Type
enum CrFTPServerServiceType : CrInt8u
{
	CrFTPServerServiceType_Invalid = 0x00,
	CrFTPServerServiceType_FTP,
};

//	FTP Server Password Exists
enum CrFTPServerPasswordExists : CrInt8u
{
	CrFTPServerPassword_NotUse = 0x00,
	CrFTPServerPassword_Use,
};

//	FTP Server Passive Mode
enum CrFTPServerPassiveMode : CrInt8u
{
	CrFTPServerPassiveMode_Invalid = 0x00,
	CrFTPServerPassiveMode_Off,
	CrFTPServerPassiveMode_On,
};

//	FTP Server using Secure Protocol
enum CrFTPServerUsingSecureProtocol : CrInt8u
{
	CrFTPServerUsingSecureProtocol_Invalid = 0x00,
	CrFTPServerUsingSecureProtocol_Off,
	CrFTPServerUsingSecureProtocol_On,   // Do not use. Will be removed in the next release.
	CrFTPServerUsingSecureProtocol_On_FTPS = CrFTPServerUsingSecureProtocol_On,
	CrFTPServerUsingSecureProtocol_On_SFTP,
};

//	FTP Server Directory Hierarchy Type
enum CrFTPServerDirectoryHierarchyType : CrInt8u
{
	CrFTPServerDirectoryHierarchyType_Invalid = 0x00,
	CrFTPServerDirectoryHierarchyType_Standard,
	CrFTPServerDirectoryHierarchyType_SameAsInCamera,
};

//	FTP Server Same Name File Overwrite Type
enum CrFTPServerSameNameFileOverwriteType : CrInt8u
{
	CrFTPServerSameNameFileOverwriteType_Invalid = 0x00,
	CrFTPServerSameNameFileOverwriteType_Overwrite,
	CrFTPServerSameNameFileOverwriteType_NotOverwrite,
};

//	FTP Server Root Certificate Error Setting
enum CrFTPServerRootCertificateErrorSetting : CrInt8u
{
	CrFTPServerRootCertificateErrorSetting_Invalid = 0x00,
	CrFTPServerRootCertificateErrorSetting_Connect,
	CrFTPServerRootCertificateErrorSetting_NotConnect,
};

// FTP Job Trim Type
enum CrFTPJobTrimType : CrInt32u
{
	CrFTPJobTrimType_NoTrim = 0x00000000, // original
	CrFTPJobTrimType_Trim,
};

// FTP Job Slot ID
enum CrFTPJobSlotId : CrInt32
{
	CrFTPJobSlotId_Invalid    = 0x00000000,
	CrFTPJobSlotId_Slot1,
	CrFTPJobSlotId_Slot2,
	CrFTPJobSlotId_Slot3,
};

// FTP Job Status
enum CrFTPJobStatus : CrInt32
{
	CrFTPJobStatus_Invalid              = 0x00000000,
	CrFTPJobStatus_Waiting              = 0x00000100,
	CrFTPJobStatus_Transferring         = 0x00000200,
	CrFTPJobStatus_Completed            = 0x00000400,
	CrFTPJobStatus_Aborted              = 0x00000800,
	CrFTPJobStatus_OtherErr             = 0x00010000,
	CrFTPJobStatus_DestAuthFailed       = 0x00010001,
	CrFTPJobStatus_ServerCapacityOver   = 0x00010002,
	CrFTPJobStatus_FileAccessErr        = 0x00010003,
	CrFTPJobStatus_DestCertErr          = 0x00010004,
	CrFTPJobStatus_MediaAccessErr       = 0x00010005,
	CrFTPJobStatus_DestConnErr          = 0x00010006,
	CrFTPJobStatus_DestServerErr        = 0x00010007,
	CrFTPJobStatus_UploadErr            = 0x00010008,
	CrFTPJobStatus_DestCertNotValid     = 0x00010009,
	CrFTPJobStatus_DestCertExpired      = 0x0001000A,
	CrFTPJobStatus_PASVNotSupport       = 0x0001000B,
	CrFTPJobStatus_ChunkTransErr        = 0x0001000C,
};

// FTP Job Control Type
enum CrFTPJobControlType : CrInt32u
{
	CrFTPJobControlType_Add      = 0x00000001,
	CrFTPJobControlType_Delete,
	CrFTPJobControlType_Suspend,
	CrFTPJobControlType_Resume,
};

// FTP Job Delete Type
enum CrFTPJobDeleteType : CrInt32u
{
	CrFTPJobDeleteType_Individual      = 0x00000000,
	CrFTPJobDeleteType_All,
	CrFTPJobDeleteType_FinishedAll,
};

// FTP Job Complete Action
enum CrFTPJobCompleteAction : CrInt8
{
	CrFTPJobCompleteAction_Invalid        = 0x00,
	CrFTPJobCompleteAction_NoAction,
	CrFTPJobCompleteAction_DeleteFile,
};

// FTP Job Delete Action
enum CrFTPJobDeleteAction : CrInt8
{
	CrFTPJobDeleteAction_Invalid        = 0x00,
	CrFTPJobDeleteAction_NoAction,
	CrFTPJobDeleteAction_DeleteFile,
};

// Camera Operating Mode
enum CrCameraOperatingMode : CrInt8u
{
	CrCameraOperatingMode_Record    = 0x01,
	CrCameraOperatingMode_Playback  = 0x02,
};

// Playback View Mode
enum CrPlaybackViewMode : CrInt8u
{
	CrPlaybackViewMode_Playback    = 0x01,
	CrPlaybackViewMode_Index       =  0x02,
};

// Monitoring Delivering Status
enum CrMonitoringDeliveringStatus : CrInt16u
{
	CrMonitoringDeliveringStatus_RTSP           = 0x0001,
	CrMonitoringDeliveringStatus_VenderProtocol = 0x0002,
	CrMonitoringDeliveringStatus_None           = 0xFFFF,
};

enum CrMonitoringIsDelivering: CrInt8u
{
	CrMonitoringIsDelivering_False = 0x00,
	CrMonitoringIsDelivering_True
};

//Monitoring Delivery Type
enum CrMonitoringDeliveryType : CrInt8u
{
	CrMonitoringDeliveryType_None = 0x00,
	CrMonitoringDeliveryType_Jpeg
};

// ND Filter Unit Setting
enum CrNDFilterUnitSetting : CrInt8u
{
	CrNDFilterUnitSetting_OpticalDensity = 0x01,
	CrNDFilterUnitSetting_Transmittance,
};

// ND Filter Optical Density Value
enum CrNDFilterOpticalDensityValue : CrInt16u
{
	CrNDFilterOpticalDensityValue_Nothing = 0xFFFF, // Nothing to display
};

// T-Number
// type: CrDataType_UInt16
// value = T number * 100
enum CrTnumber : CrInt16u
{
	CrTnumber_Unknown = 0xFFFE, // Display "--"
	CrTnumber_Nothing = 0xFFFF, // Nothing to display
};

// Iris Display Unit
enum CrIrisDisplayUnit : CrInt8u
{
	CrIrisDisplayUnit_Auto = 0x01,
	CrIrisDisplayUnit_FLock,
	CrIrisDisplayUnit_TLock,
};

// Image Stabilization Level (Movie)
enum CrImageStabilizationLevelMovie : CrInt8u
{
	CrImageStabilizationLevelMovie_OFF = 0x01,
	CrImageStabilizationLevelMovie_Low,
	CrImageStabilizationLevelMovie_High,
};

// Image Stabilization Steady Shot Adjust
enum CrImageStabilizationSteadyShotAdjust : CrInt8u
{
	CrImageStabilizationSteadyShotAdjust_Automatic = 0x01,
	CrImageStabilizationSteadyShotAdjust_Manual,
};

// Image Stabilization Steady Shot Focal Length
// CrDataType_UInt16
// Unit : mm


// Audio Level Display
enum CrAudioLevelDisplay : CrInt8u
{
	CrAudioLevelDisplay_Off = 0x01,
	CrAudioLevelDisplay_On,
};

// HDMI Output Color Gamut for RAW Out(Movie)
enum CrHDMIOutputColorGamutForRAWOutMovie : CrInt8u
{
	CrHDMIOutputColorGamutForRAWOutMovie_S_Gamut3_Cine_SLog3 = 0x01,
	CrHDMIOutputColorGamutForRAWOutMovie_S_Gamut3_SLog3,
};

// e-Front Curtain Shutter
enum CrElectricFrontCurtainShutter : CrInt8u
{
	CrElectricFrontCurtainShutter_Off = 0x01,
	CrElectricFrontCurtainShutter_On
};

// Extend Shutter Speed
// Upper four bytes: numerator, Lower four bytes: denominator.
enum CrExtendedShutterSpeed : CrInt64u
{
	CrExtendedShutterSpeed_Bulb = 0x0000000000000000,
	CrExtendedShutterSpeed_Nothing = 0xFFFFFFFFFFFFFFFF, // Nothing to display
};

// Camera Button Function
// Camera Button Function Multi
enum CrCameraButtonFunction : CrInt32u
{
	CrCameraButtonFunction_UpButton = 0x00010000,
	CrCameraButtonFunction_DownButton = 0x00020000,
	CrCameraButtonFunction_LeftButton = 0x00030000,
	CrCameraButtonFunction_RightButton = 0x00040000,
	CrCameraButtonFunction_EnterButton = 0x00050000,
	CrCameraButtonFunction_MenuButton = 0x00060000,
	CrCameraButtonFunction_MultiSelectorUp = 0x00070000,
	CrCameraButtonFunction_MultiSelectorDown = 0x00080000,
	CrCameraButtonFunction_MultiSelectorLeft = 0x00090000,
	CrCameraButtonFunction_MultiSelectorRight = 0x000A0000,
	CrCameraButtonFunction_MultiSelectorEnter = 0x000B0000,
	CrCameraButtonFunction_MultiSelectorRightUp = 0x000C0000,
	CrCameraButtonFunction_MultiSelectorRightDown = 0x000D0000,
	CrCameraButtonFunction_MultiSelectorLeftUp = 0x000E0000,
	CrCameraButtonFunction_MultiSelectorLeftDown = 0x000F0000,
	CrCameraButtonFunction_FnButton = 0x00100000,
	CrCameraButtonFunction_PlaybackButton = 0x00110000,
	CrCameraButtonFunction_DeleteButton = 0x00120000,
	CrCameraButtonFunction_ModeButton = 0x00130000,
	CrCameraButtonFunction_C1Button = 0x00140000,
	CrCameraButtonFunction_C2Button = 0x00150000,
	CrCameraButtonFunction_C3Button = 0x00160000,
	CrCameraButtonFunction_C4Button = 0x00170000,
	CrCameraButtonFunction_C5Button = 0x00180000,
	CrCameraButtonFunction_C6Button = 0x00190000,
	CrCameraButtonFunction_MovieButton = 0x001A0000,
	CrCameraButtonFunction_AELButton = 0x001B0000,
	CrCameraButtonFunction_AFOnButton = 0x001C0000,
};

// Lower 16 bits of camera button function
enum CrCameraButtonFunctionValue : CrInt16u
{
	CrCameraButtonFunctionValue_Up = 0x0001,
	CrCameraButtonFunctionValue_Down,
};

// Camera Dial Function
enum CrCameraDialFunction : CrInt32u
{
	CrCameraDialFunction_ControlWheel = 0x40010000,
	CrCameraDialFunction_FrontDial = 0x40020000,
	CrCameraDialFunction_RearDialL = 0x40030000,
	CrCameraDialFunction_RearDialR = 0x40040000,
};

// Camera Button Function Status
enum CrCameraButtonFunctionStatus : CrInt16u
{
	CrCameraButtonFunctionStatus_Idle = 0x0001,
	CrCameraButtonFunctionStatus_AnyKeyOn,
};

// Synchroterminal Forced Output
enum CrSynchroterminalForcedOutput : CrInt8u
{
	CrSynchroterminalForcedOutput_Off = 0x01,
	CrSynchroterminalForcedOutput_On,
};

// Shutter Release Time Lag Control
enum CrShutterReleaseTimeLagControl : CrInt8u
{
	CrShutterReleaseTimeLagControl_Off = 0x01,
	CrShutterReleaseTimeLagControl_On_Stability,
	CrShutterReleaseTimeLagControl_On_Fastest,
};

// Continuous Shooting Spot Boost Frame Speed
// CrDataType_UInt16
// Unit : fps
// e.g.) 0x0078 = 120 fps

// Continuous Shooting Spot Boost Status
enum CrContinuousShootingSpotBoostStatus : CrInt8u
{
	CrContinuousShootingSpotBoostStatus_NotSpotBoosting = 0x01,
	CrContinuousShootingSpotBoostStatus_SpotBoosting,
};

// Continuous Shooting Spot Boost Enable Status
enum CrContinuousShootingSpotBoostEnableStatus : CrInt8u
{
	CrContinuousShootingSpotBoost_Disable = 0x01,
	CrContinuousShootingSpotBoost_Enable,
};

// TimeShift Shooting
enum CrTimeShiftShooting : CrInt8u
{
	CrTimeShiftShooting_Off = 0x01,
	CrTimeShiftShooting_On,
};

// TimeShift Trigger Setting
enum CrTimeShiftTriggerSetting : CrInt8u
{
	CrTimeShiftTriggerSetting_S1AndAF = 0x01,
	CrTimeShiftTriggerSetting_S1,
	CrTimeShiftTriggerSetting_AF,
};


// TimeShift Shooting Status
enum CrTimeShiftShootingStatus : CrInt8u
{
	CrTimeShiftShootingStatus_Idle = 0x01,
	CrTimeShiftShootingStatus_TimeShiftShooting,
	CrTimeShiftShootingStatus_Impossible,
	CrTimeShiftShootingStatus_Impossible_TimerShiftOverheating,
	CrTimeShiftShootingStatus_MainShooting,
};

// TimeShift PreShooting Time Setting
// CrDataType_UInt32
// Unit : msec
// e.g.) 0x0000000A = 10 msec


// Embed LUT File
enum CrEmbedLUTFile : CrInt8u
{
	CrEmbedLUTFile_Off = 0x01,
	CrEmbedLUTFile_On,
};

// APS-C/Super 35mm Shooting
enum CrAPS_C_S35 : CrInt8u
{
	CrAPS_C_S35_Off = 0x01,
	CrAPS_C_S35_On,
	CrAPS_C_S35_Auto,
};

// Lens Compensation Shading
enum CrLensCompensationShading : CrInt8u
{
	CrLensCompensationShading_Off = 0x01,
	CrLensCompensationShading_Auto,
	CrLensCompensationShading_Low,
};

// Lens Compensation Chromatic Aberration
enum CrLensCompensationChromaticAberration : CrInt8u
{
	CrLensCompensationChromaticAberration_Off = 0x01,
	CrLensCompensationChromaticAberration_Auto,
};

// Lens Compensation Distortion
enum CrLensCompensationDistortion : CrInt8u
{
	CrLensCompensationDistortion_Off = 0x01,
	CrLensCompensationDistortion_Auto,
};

// Lens Compensation Breathing
enum CrLensCompensationBreathing : CrInt8u
{
	CrLensCompensationBreathing_Off = 0x01,
	CrLensCompensationBreathing_On,
};

// Recording Media (Still Image)
enum CrRecordingMedia : CrInt16u
{
	CrRecordingMedia_Slot1 = 0x0001,
	CrRecordingMedia_Slot2,
	CrRecordingMedia_SimultaneousRecording = 0x0101,
	CrRecordingMedia_SortRecording,
};

// Recording Media (Movie)
enum CrRecordingMediaMovie : CrInt16u
{
	CrRecordingMediaMovie_Slot1 = 0x0001,
	CrRecordingMediaMovie_Slot2,
	CrRecordingMediaMovie_SimultaneousRecording = 0x0101,
};

// Auto Switch Media
enum CrAutoSwitchMedia : CrInt8u
{
	CrAutoSwitchMedia_Off = 0x01,
	CrAutoSwitchMedia_On,
};

// Recording File Number (Still)
// Recording File Number (Movie)
enum CrRecordingFileNumber : CrInt8u
{
	CrRecordingFileNumber_Reset = 0x01,
	CrRecordingFileNumber_Series,
};

// Recording Setting File Name 
// CrDataType_STR


// Recording Folder Format
enum CrRecordingFolderFormat : CrInt8u
{
	CrRecordingFolderFormat_Standard = 0x01,
	CrRecordingFolderFormat_Date,
};

// Create New Folder(Still) Enable Status
enum CrCreateNewFolderEnableStatus : CrInt8u
{
	CrCreateNewFolderEnableStatus_Disable = 0x00,
	CrCreateNewFolderEnableStatus_Enable,
};

// Create New Folder(Still)
// CrDataType_STR
// SetOnly


// Select IPTC Metadata
// Index The value of IPTCMetadata
//   cf.) CrDisplayStringType_IPTC_Metadata_Display
enum CrSelectIPTCMetadata : CrInt8u
{
	CrSelectIPTCMetadata_Off = 0x00,
};

// Copyright Info
enum CrWriteCopyrightInfo : CrInt8u
{
	CrWriteCopyrightInfo_Off = 0x01,
	CrWriteCopyrightInfo_On,
};

// Set Photographer
// CrDataType_STR

// Set Copyright
// CrDataType_STR

// File Settings Title Name Settings
// CrDataType_STR


// Focus Bracket Recording Folder
enum CrFocusBracketRecordingFolder : CrInt8u
{
	CrFocusBracketRecordingFolder_CurrentFolder = 0x01,
	CrFocusBracketRecordingFolder_NewFolder,
};

// Forced File Number Reset Enable Status
enum CrForcedFileNumberReset : CrInt8u
{
	CrForcedFileNumberReset_Disable = 0x00,
	CrForcedFileNumberReset_Enable,
};

// Release without Lens
enum CrReleaseWithoutLens : CrInt8u
{
	CrReleaseWithoutLens_Disable = 0x01,
	CrReleaseWithoutLens_Enable,
};

// Release without Card
enum CrReleaseWithoutCard : CrInt8u
{
	CrReleaseWithoutCard_Disable = 0x01,
	CrReleaseWithoutCard_Enable,
};

// Grid Line Display
enum CrGridLineDisplay : CrInt8u
{
	CrGridLineDisplay_Off = 0x01,
	CrGridLineDisplay_On,
};

// Continuous Shooting Speed in Electric Shutter(Hi+)
// Continuous Shooting Speed in Electric Shutter(Hi)
// Continuous Shooting Speed in Electric Shutter(Mid)
// Continuous Shooting Speed in Electric Shutter(Lo)
// 
// The real value of shutter speed in pictures/second.
enum CrContinuousShootingSpeedInElectricShutter : CrInt16u
{
	CrContinuousShootingSpeedInElectricShutter_Invalid = 0x0000,
};

// ISO Auto Range Limit(min), ISO Auto Range Limit(max)
// The value is same as IsoSensitivity


// Face Priority in Multi Metering
enum CrFacePriorityInMultiMetering : CrInt8u
{
	CrFacePriorityInMultiMetering_Off = 0x01,
	CrFacePriorityInMultiMetering_On,
};

// Priority Set in AWB
enum CrPrioritySetInAWB : CrInt8u
{
	CrPrioritySetInAWB_Standard = 0x01,
	CrPrioritySetInAWB_Ambience,
	CrPrioritySetInAWB_White,
};

// Custom WB Size Setting
enum CrCustomWBSizeSetting : CrInt8u
{
	CrCustomWBSizeSetting_S = 0x01,
	CrCustomWBSizeSetting_M,
	CrCustomWBSizeSetting_L,
};

// AF Illuminator
enum CrAFIlluminator : CrInt8u
{
	CrAFIlluminator_Off = 0x01,
	CrAFIlluminator_Auto,
};

// Aperture Drive in AF
enum CrApertureDriveInAF : CrInt8u
{
	CrApertureDriveInAF_Standard = 0x01,
	CrApertureDriveInAF_FocusPriority,
	CrApertureDriveInAF_SilentPriority,
};

// AF with shutter
enum CrAFWithShutter : CrInt8u
{
	CrAFWithShutter_Off = 0x01,
	CrAFWithShutter_On,
};

// Full Time DMF
enum CrFullTimeDMF : CrInt8u
{
	CrFullTimeDMF_Off = 0x01,
	CrFullTimeDMF_On,
};

// Pre-AF
enum CrPreAF : CrInt8u
{
	CrPreAF_Off = 0x01,
	CrPreAF_On,
};

// Subject Recognition Person Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Animal+Bird Priority
enum CrSubjectRecognitionAnimalBirdPriority : CrInt8u
{
	CrSubjectRecognitionAnimalBirdPriority_Auto = 0x01,
	CrSubjectRecognitionAnimalBirdPriority_AnimalPriority,
	CrSubjectRecognitionAnimalBirdPriority_BirdPriority,
};

// Subject Recognition Animal+Bird Detection Parts
// Subject Recognition Animal(Still) Detection Parts
// Subject Recognition Bird Detection Parts
enum CrSubjectRecognitionAnimalBirdDetectionParts : CrInt8u
{
	CrSubjectRecognitionAnimalBirdDetectionParts_FollowIndividualSetting = 0xFF,
	CrSubjectRecognitionAnimalBirdDetectionParts_EyeHeadBody = 0x01,
	CrSubjectRecognitionAnimalBirdDetectionParts_EyeHead,
	CrSubjectRecognitionAnimalBirdDetectionParts_Eye,
};

// Subject Recognition Animal(Still) Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Animal(Still) Tracking Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Animal(Still) Detection Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Bird Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Bird Tracking Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Bird Detection Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Insect Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Insect Tracking Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Insect Detection Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Car/Train Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Car/Train Tracking Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Car/Train Detection Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Plane Tracking Subject Shift Range
// CrDataType_UInt8Range

// Subject Recognition Plane Tracking Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Plane Detection Sensitivity
// CrDataType_UInt8Range

// Subject Recognition Priority on Registered Face
enum CrSubjectRecognitionPriorityOnRegisteredFace : CrInt8u
{
	CrSubjectRecognitionPriorityOnRegisteredFace_Off = 0x01,
	CrSubjectRecognitionPriorityOnRegisteredFace_On,
};

// Face/Eye Frame Display
enum CrFaceEyeFrameDisplay : CrInt8u
{
	CrFaceEyeFrameDisplay_Off = 0x01,
	CrFaceEyeFrameDisplay_On,
};

// Focus Map
enum CrFocusMap : CrInt8u
{
	CrFocusMap_Off = 0x01,
	CrFocusMap_On,
};

// Initial Focus Magnifier(Still)
// CrDataType_UInt16
// 10 times value of the Ratio
// e.g.) 0x000A = 10 (x1.0)

// AF in Focus Magnifier
enum CrAFInFocusMagnifier : CrInt8u
{
	CrAFInFocusMagnifier_Off = 0x01,
	CrAFInFocusMagnifier_On,
};

// AF Track for Speed Change
enum CrAFTrackForSpeedChange : CrInt8u
{
	CrAFTrackForSpeedChange_Stable = 0x01,
	CrAFTrackForSpeedChange_Standard,
	CrAFTrackForSpeedChange_Responsive,
};

// AF Free Size and Position Setting/Default AF Free Size and Position Setting
// CrDataType_UInt64
// Upper four bytes: Height and Width
//   the height is set in the upper two bytes and the width is set in the lower two bytes. 
// Lower four bytes: Center coordinates .
//   the x coordinate is set in the upper two bytes and the y coordinate is set in the lower two bytes. 
// e.g.) 0x0032003200960064 = Height is 50, Width is 50, x is 150, y is 100

// Play Set of Multi. Media
enum CrPlaySetOfMultiMedia : CrInt8u
{
	CrPlaySetOfMultiMedia_Slot1 = 0x01,
	CrPlaySetOfMultiMedia_Slot2,
};

// Remote Save Image Size
enum CrRemoteSaveImageSize : CrInt8u
{
	CrRemoteSaveImageSize_LargeSize = 0x01,
	CrRemoteSaveImageSize_SmallSize,
};

// FTP Transfer Still Image Quality Size
enum CrFTPTransferStillImageQualitySize : CrInt8u
{
	CrFTPTransferStillImageQualitySize_Small = 0x01,
	CrFTPTransferStillImageQualitySize_Large,
};

// Auto FTP Transfer Target(Still)
enum CrFTPAutoTransferTargetStill : CrInt8u
{
	CrFTPAutoTransferTargetStill_All = 0x01,
	CrFTPAutoTransferTargetStill_ProtectOnly,
};

// Protect Image in FTP Transfer
enum CrProtectImageInFTPTransfer : CrInt8u
{
	CrProtectImageInFTPTransfer_Off = 0x01,
	CrProtectImageInFTPTransfer_On,
};

// Monitor Brightness Type
enum CrMonitorBrightnessType : CrInt8u
{
	CrMonitorBrightnessType_Manual = 0x01,
	CrMonitorBrightnessType_SunnyWeather,
};

// Monitor Brightness Manual
// CrDataType_Int16Range


// Display Quality(Finder/Monitor)
enum CrDisplayQualityFinder : CrInt8u
{
	CrDisplayQualityFinder_Standard = 0x01,
	CrDisplayQualityFinder_High,
};

// TC/UB Display Setting
enum CrTCUBDisplaySetting : CrInt8u
{
	CrTCUBDisplaySetting_Counter = 0x01,
	CrTCUBDisplaySetting_TC, // TimeCode
	CrTCUBDisplaySetting_UB, // UserBit
};

// Gamma Display Assist
enum CrGammaDisplayAssist : CrInt8u
{
	CrGammaDisplayAssist_Off = 0x01,
	CrGammaDisplayAssist_On,
};

// Gamma Display Assist Type
enum CrGammaDisplayAssistType : CrInt16u
{
	CrGammaDisplayAssistType_Auto = 0x0001,
	CrGammaDisplayAssistType_SLog2_709_800 = 0x0302,
	CrGammaDisplayAssistType_SLog3_709_800 = 0x0303,
	CrGammaDisplayAssistType_HLG_BT2020 = 0x0401,
	CrGammaDisplayAssistType_HLG_709 = 0x0402,
};

// Audio Signals(Start/End)
enum CrAudioSignalsStartEnd : CrInt8u
{
	CrAudioSignalsStartEnd_Off = 0x01,
	CrAudioSignalsStartEnd_On,
};

// Audio Signals Volume
// CrDataType_UInt8Range


// Control For HDMI
enum CrControlForHDMI : CrInt8u
{
	CrControlForHDMI_Off = 0x01,
	CrControlForHDMI_On,
};

// Anti-dust Shutter When Power OFF
enum CrAntidustShutterWhenPowerOff : CrInt8u
{
	CrAntidustShutterWhenPowerOff_Off = 0x01,
	CrAntidustShutterWhenPowerOff_On,
};

// Wake on LAN
enum CrWakeOnLAN : CrInt8u
{
	CrWakeOnLAN_Off = 0x01,
	CrWakeOnLAN_On,
};

// Camera Error Caution Status
enum CrCameraErrorCautionStatus : CrInt8u
{
	CrCameraErrorCautionStatus_NoError = 0x01,
	CrCameraErrorCautionStatus_Error,
};

// System Error Caution Status
enum CrSystemErrorCautionStatus : CrInt8u
{
	CrSystemErrorCautionStatus_NoError = 0x01,
	CrSystemErrorCautionStatus_Error,
};

// Flicker Less Shooting Status
enum CrFlickerLessShootingStatus : CrInt8u
{
	CrFlickerLessShootingStatus_NotDetected = 0x00,
	CrFlickerLessShootingStatus_Detected,
};

// Zoom Driving Status
enum CrZoomDrivingStatus : CrInt8u
{
	CrZoomDrivingStatus_NotDriving = 0x01,
	CrZoomDrivingStatus_Driving,
};

// Shooting Self timer Status
enum CrShootingSelfTimerStatus : CrInt8u
{
	CrShootingSelfTimerStatus_Idle = 0x01,
	CrShootingSelfTimerStatus_CountingDown,
};

// Tracking On + AF On Enable Status
enum CrTrackingOnAndAFOnEnableStatus : CrInt8u
{
	CrTrackingOnAndAFOnEnableStatus_Disable = 0x00,
	CrTrackingOnAndAFOnEnableStatus_Enable,
};

// Program Shift Status
enum CrProgramShiftStatus : CrInt8u
{
	CrProgramShiftStatus_Idle = 0x01,
	CrProgramShiftStatus_ProgramShift,
};

// Metered Manual Level
// CrDataType_Int16Range
// 1000 times value


// Zoom and Focus Preset Data Version
// CrDataType_UInt16
// 100 times value
// e.g.) 0x0065 = 101 (version 1.01)

// Zoom and Focus Preset ZoomOnly Set
// CrDataType_UInt16
// Upper 8bit = Preset number, Lower 8bit = Off/On(CrZoomAndFocusPresetZoomOnlyValue)


// Second/Total Battery Remain
// 0~100: percentage of the battery residual quantity.
// cf.) Battery Residual Quantity 


// Second/Total Battery Level
// cf.) Battery Level Indicator


// Body Serial Number
// CrDataType_STR


// Media Slot Number
enum CrSlotNumber : CrInt32u
{
	CrSlotNumber_Slot1 = 0x00000001,
	CrSlotNumber_Slot2,
};


class SCRSDK_API CrDeviceProperty
{
public:
	CrDeviceProperty();
	~CrDeviceProperty();

	CrDeviceProperty(const CrDeviceProperty& ref);

	CrDeviceProperty& operator =(const CrDeviceProperty& ref);

	// Do not use. Will be removed in the next release.
	void Alloc(const CrInt32u size, const CrInt32u getSetSize, const CrInt16u getStrSize);

	bool IsGetEnableCurrentValue();

	bool IsSetEnableCurrentValue();

	void SetCode(CrInt32u code);

	CrInt32u GetCode();

	void SetValueType(CrDataType type);
	CrDataType GetValueType();

	// Do not use. Will be removed in the next release.
	void SetPropertyEnableFlag(CrPropertyEnableFlag flag);


	CrPropertyEnableFlag GetPropertyEnableFlag();

	// Do not use. Will be removed in the next release.
	void SetPropertyVariableFlag(CrPropertyVariableFlag flag);

	CrPropertyVariableFlag GetPropertyVariableFlag();

	void SetCurrentValue(CrInt64u value);
	CrInt64u GetCurrentValue();

	void SetCurrentStr(CrInt16u* str);
	CrInt16u* GetCurrentStr();

	// Do not use. Will be removed in the next release.
	void SetValueSize(CrInt32u size);

	CrInt32u GetValueSize();

	// Do not use. Will be removed in the next release.
	void SetValues(CrInt8u* value);

	CrInt8u* GetValues();

	// Do not use. Will be removed in the next release.
	void SetSetValueSize(CrInt32u size);

	CrInt32u GetSetValueSize();

	// Do not use. Will be removed in the next release.
	void SetSetValues(CrInt8u* value);

	CrInt8u* GetSetValues();

private:
	CrInt32u code;
	CrDataType valueType;
	CrPropertyEnableFlag enableFlag;
	CrPropertyVariableFlag variableFlag;
	CrInt64u currentValue;
	CrInt16u* currentStr;
	CrInt32u valuesSize;
	CrInt8u* values;
	CrInt32u getSetValuesSize;
	CrInt8u* getSetValues;
};

class SCRSDK_API CrLiveViewProperty
{
public:
	CrLiveViewProperty();
	~CrLiveViewProperty();
	CrLiveViewProperty(const CrLiveViewProperty& ref);
	CrLiveViewProperty& operator =(const CrLiveViewProperty& ref);

	// Do not use. Will be removed in the next release.
	void Alloc(const CrInt32u size);

	bool IsGetEnableCurrentValue();

	// Do not use. Will be removed in the next release.
	void SetCode(CrInt32u code);

	CrInt32u GetCode();

	// Do not use. Will be removed in the next release.
	void SetPropertyEnableFlag(CrPropertyEnableFlag flag);

	CrPropertyEnableFlag GetPropertyEnableFlag();

	// Do not use. Will be removed in the next release.
	void SetFrameInfoType(CrFrameInfoType type);

	CrFrameInfoType GetFrameInfoType();

	// Do not use. Will be removed in the next release.
	void SetValueSize(CrInt32u size);

	CrInt32u GetValueSize();

	// Do not use. Will be removed in the next release.
	void SetValue(CrInt8u* value);

	CrInt8u* GetValue();

	CrInt32u GetTimeCode();

private:
        CrInt32u code;
		CrPropertyEnableFlag enableFlag;
        CrFrameInfoType valueType;
		CrInt32u valueSize;
		CrInt8u* value;
		CrInt32u timeCode; // SMPTE 12M time-code from monitoring meta.
};

class SCRSDK_API CrMtpFolderInfo
{
public:
	CrMtpFolderInfo();
	~CrMtpFolderInfo();
	CrMtpFolderInfo(const CrMtpFolderInfo& ref);
	CrMtpFolderInfo& operator =(const CrMtpFolderInfo& ref);

private:
	// Do not use. Will be removed in the next release.
	void Alloc(const CrInt32u size); 

public:
	CrFolderHandle handle;
	CrInt32u folderNameSize;
	CrChar*  folderName;
};


class SCRSDK_API CrMtpContentsInfo
{
public:
	CrMtpContentsInfo();
	~CrMtpContentsInfo();
	CrMtpContentsInfo(const CrMtpContentsInfo& ref);
	CrMtpContentsInfo& operator =(const CrMtpContentsInfo& ref);

private:
	// Do not use. Will be removed in the next release.
	void Alloc(const CrInt32u size); 

public:
	CrContentHandle handle;
	CrFolderHandle parentFolderHandle;
	CrInt64u contentSize;
	CrChar dateChar[16];
	CrInt32u width;
	CrInt32u height;
	CrInt32u fileNameSize;
	CrChar* fileName;
};

#pragma pack(1)
class CrLevelInfo
{
public:
	CrLevelInfo()
		: state(CrLevel_Off)
		, reserved(0)
		, x(0)
		, y(0)
		, z(0)
	{}
	~CrLevelInfo()
	{}
public:
	CrLevelState state;
	CrInt32 reserved;
	CrInt32 x;
	CrInt32 y;
	CrInt32 z;
};
#pragma pack()

#pragma pack(1)
class CrFocusFrameInfo
{
public:
	CrFocusFrameInfo()
		: type(CrFocusFrameType_Unknown)
		, state(CrFocusFrameState_Unknown)
		, priority(0)
		, xNumerator(0)
		, xDenominator(0)
		, yNumerator(0)
		, yDenominator(0)
		, width(0)
		, height(0)
	{}
	~CrFocusFrameInfo()
	{}

public:
    CrFocusFrameType type;
    CrFocusFrameState state;
    CrInt8u priority;
    CrInt32u xNumerator;
    CrInt32u xDenominator;
    CrInt32u yNumerator;
    CrInt32u yDenominator;
    CrInt32u width;
    CrInt32u height;
};
#pragma pack()

#pragma pack(1)
class CrFaceFrameInfo
{
public:
	CrFaceFrameInfo()
		: type(CrFaceFrameType_Unknown)
		, state(CrFocusFrameState_Unknown)
		, isSelected(CrFocusFrameSelectState_Unknown)
		, priority(0)
		, xNumerator(0)
		, xDenominator(0)
		, yNumerator(0)
		, yDenominator(0)
		, width(0)
		, height(0)
	{}
	~CrFaceFrameInfo()
	{}
public:
	CrFaceFrameType type;
	CrFocusFrameState state;
	CrFocusFrameSelectState isSelected;
	CrInt8u priority;
	CrInt32u xNumerator;
	CrInt32u xDenominator;
	CrInt32u yNumerator;
	CrInt32u yDenominator;
	CrInt32u width;
	CrInt32u height;
};
#pragma pack()

#pragma pack(1)
class CrTrackingFrameInfo
{
public:
	CrTrackingFrameInfo()
		: type(CrTrackingFrameType_Unknown)
		, state(CrFocusFrameState_Unknown)
		, priority(0)
		, xNumerator(0)
		, xDenominator(0)
		, yNumerator(0)
		, yDenominator(0)
		, width(0)
		, height(0)
	{}
	~CrTrackingFrameInfo()
	{}
public:
	CrTrackingFrameType type;
	CrFocusFrameState state;
	CrInt8u priority;
	CrInt32u xNumerator;
	CrInt32u xDenominator;
	CrInt32u yNumerator;
	CrInt32u yDenominator;
	CrInt32u width;
	CrInt32u height;
};
#pragma pack()

class CrMagPosInfo
{
public:
	CrMagPosInfo()
		: xNumerator(0)
		, xDenominator(0)
		, yNumerator(0)
		, yDenominator(0)
		, width(0)
		, height(0)
	{}
	~CrMagPosInfo()
	{}

public:
	CrInt32u xNumerator;
	CrInt32u xDenominator;
	CrInt32u yNumerator;
	CrInt32u yDenominator;
    CrInt32u width;
    CrInt32u height;
};

class SCRSDK_API CrDisplayStringListInfo
{
public:
	CrDisplayStringListInfo();
	~CrDisplayStringListInfo();
	CrDisplayStringListInfo(const 	CrDisplayStringListInfo& ref);
	CrDisplayStringListInfo& operator =(const 	CrDisplayStringListInfo& ref);

private:
	void Alloc(const CrInt32u size);

public:
	CrDataType dataType;
	CrDisplayStringType listType;
	CrInt64u value;
	CrInt32u displayStringSize;
	CrInt8u* displayString;
};

#pragma pack(1)
class SCRSDK_API CrMediaProfileInfo
{
public:
	CrMediaProfileInfo();
	~CrMediaProfileInfo();
	CrMediaProfileInfo(const CrMediaProfileInfo& ref);
	CrMediaProfileInfo& operator =(const CrMediaProfileInfo& ref);

public:
	CrInt8u* contentName;
	CrInt8u* contentUrl;
	CrInt8u* contentType;
	CrInt8u* contentFrameRate;
	CrInt8u* contentAspectRatio;
	CrInt8u* contentChannel;
	CrInt8u* contentVideoType;
	CrInt8u* contentAudioType;
	CrInt8u* proxyUrl;
	CrInt8u* proxyType;
	CrInt8u* proxyFrameRate;
	CrInt8u* proxyAspectRatio;
	CrInt8u* proxyChannel;
	CrInt8u* proxyVideoType;
	CrInt8u* proxyAudioType;
	CrInt8u* thumbnailUrl;
	CrInt8u* metaUrl;
	CrInt8u  umid[32];
	CrInt32u duration;
	CrInt32u restrictionFrame;
	bool     isTrimmingAvailable;
};
#pragma pack()

class SCRSDK_API CrLensInformation
{
public:
	CrLensInformation();
	~CrLensInformation();
	CrLensInformation(const  CrLensInformation& ref);
	CrLensInformation& operator =(const 	CrLensInformation& ref);

public:
	CrLensInformationType type;
	CrInt16u dataVersion;
	CrInt32u normalizedValue;
	CrInt32u focusPosition;
};

#pragma pack(1)
class SCRSDK_API CrFTPServerSetting
{
public:
	CrFTPServerSetting();
	~CrFTPServerSetting();
	CrFTPServerSetting(const CrFTPServerSetting& ref);
	CrFTPServerSetting& operator = (const CrFTPServerSetting& ref);

public:
	CrInt16u                               serverId;
	CrInt8u*                               displayName;    // Not required, Display for Camera menu
	CrFTPServerServiceType                 serviceType;
	CrInt8u*                               hostName;       // The first 2bytes are String length
	CrInt16u                               portNumber;
	CrInt8u*                               userName;       // The first 2bytes are String length
	CrFTPServerPasswordExists              passwordExists;
	CrInt8u*                               password;       // The first 2bytes are String length
	CrFTPServerPassiveMode                 passiveMode;
	CrInt8u*                               destinationDir; // The first 2bytes are String length
	CrFTPServerUsingSecureProtocol         secureProtocol;
	CrFTPServerDirectoryHierarchyType      directoryHierarchyType;
	CrFTPServerSameNameFileOverwriteType   overwriteType;
	CrFTPServerRootCertificateErrorSetting rootCertificateErrorSetting; // Available only when FTPS
};
#pragma pack()

class CrOperationResultSupportedInfo
{
public:
	CrOperationResultSupportedInfo();
	~CrOperationResultSupportedInfo();
public:
	CrSdkApi api;
	CrInt32u code;
};

// Used by GetFTPJobList API
#pragma pack(1)
class SCRSDK_API CrFTPJobInfo
{
public:
	CrFTPJobInfo();
	~CrFTPJobInfo();
	CrFTPJobInfo(const CrFTPJobInfo& ref);
	CrFTPJobInfo& operator =(const CrFTPJobInfo& ref);

public:
	CrInt32u serverId;
	CrInt32u jobId;
	CrFTPJobSlotId slotId;
	CrFTPJobStatus jobStatus;
	CrInt32  chunkNum;
	CrInt64u fileSize;
	CrInt64u transferSize;
	CrInt8u* clipName;      // The first 2bytes are String length
	CrInt8u* mainName;      // The first 2bytes are String length
	CrInt8u* metaName;      // The first 2bytes are String length
};
#pragma pack()

// Used by ControlFTPJobList API
const CrInt32u CrFTPJOBLIST_MAX = 500;
const CrInt16u CrFTPJOBLIST_ADD_CLIP_PATH_MAX_LEN = 129;
const CrInt16u CrFTPJOBLIST_ADD_META_PATH_MAX_LEN = 129;
const CrInt16u CrFTPJOBLIST_ADD_TRANSFER_DIR_MAX_LEN = 513;
const CrInt16u CrFTPJOBLIST_ADD_DEST_CLIP_NAME_MAX_LEN = 129;
#pragma pack(1)
class SCRSDK_API CrFTPJobSetting
{
public:
	CrFTPJobSetting();
	~CrFTPJobSetting();
	CrFTPJobSetting(const CrFTPJobSetting& ref);
	CrFTPJobSetting(CrFTPJobSetting&& ref) noexcept;
	CrFTPJobSetting& operator = (const CrFTPJobSetting& ref);

public:
	CrFTPJobTrimType                       trimType;
	CrInt32u                               serverId;
	CrFTPJobSlotId                         slotId;
	CrInt8u*                               clipPath;       // The first 2bytes are String length
	CrInt8u*                               metaPath;       // The first 2bytes are String length
	CrInt8u*                               transferDir;    // The first 2bytes are String length
	CrInt32u                               inFrame;
	CrInt32u                               outFrame;
	CrInt32u                               duration;
	CrInt8u*                               destClipName;   // The first 2bytes are String length
	CrInt8u                                umid[32];
	CrInt8u*                               videoType;      // The first 2bytes are String length
	CrFTPJobCompleteAction                 compJobAction;
	CrFTPJobDeleteAction                   deleteJobAction;
};
#pragma pack()

class SCRSDK_API CrMonitoringDeliverySetting
{
public:
	CrMonitoringDeliverySetting();
	~CrMonitoringDeliverySetting();
	CrMonitoringDeliverySetting(const CrMonitoringDeliverySetting& ref);

public:
	CrInt16u                 reserved1;
	CrMonitoringDeliveryType type;
	CrInt8u                  reserved2;
	CrInt8u*                 ipAddress;
	CrInt32u                 downTime;
	CrInt32u                 videoPort;
};


// Zoom and Focus PresetInfo isExists
enum CrZoomAndFocusPresetExist : CrInt8u
{
	CrZoomAndFocusPresetExist_False = 0x01,
	CrZoomAndFocusPresetExist_True ,
};

// Zoom and Focus PresetInfo ZoomOnly Enable Status
enum CrZoomAndFocusPresetZoomOnlyEnableStatus : CrInt8u
{
	CrZoomAndFocusPresetZoomOnlyEnableStatus_Disable = 0x01,
	CrZoomAndFocusPresetZoomOnlyEnableStatus_Enable,
};

// Zoom and Focus PresetInfo ZoomOnly Value
// CrDeviceProperty_ZoomAndFocusPresetZoomOnly_Set
enum CrZoomAndFocusPresetZoomOnlyValue : CrInt8u
{
	CrZoomAndFocusPresetZoomOnlyValue_Off = 0x01,
	CrZoomAndFocusPresetZoomOnlyValue_On,
};

// Used by GetZoomAndFocusPreset API
#pragma pack(1)
class SCRSDK_API CrZoomAndFocusPresetInfo
{
public:
	CrZoomAndFocusPresetInfo();
	~CrZoomAndFocusPresetInfo();
	CrZoomAndFocusPresetInfo(const CrZoomAndFocusPresetInfo& ref);
	CrZoomAndFocusPresetInfo& operator =(const CrZoomAndFocusPresetInfo& ref);

public:
	CrZoomAndFocusPresetExist                isExists;
	CrInt16u*                                lensModelName;
	CrInt32u                                 zoomDistance;
	CrInt32u                                 focalDistance;
	CrZoomAndFocusPresetZoomOnlyEnableStatus zoomOnlyEnableStatus;
	CrZoomAndFocusPresetZoomOnlyValue        zoomOnlyValue;
};
#pragma pack()

}

#pragma warning (pop)

#endif //CRDEVICEPROPERTY_H
