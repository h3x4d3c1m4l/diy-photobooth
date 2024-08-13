#ifndef CAMERAREMOTE_SDK_H
#define CAMERAREMOTE_SDK_H

#if defined(WIN32) || defined(_WIN64)

	#ifdef CR_SDK_EXPORTS
		#define SCRSDK_API __declspec(dllexport)
	#else
		#define SCRSDK_API __declspec(dllimport)
	#endif

#else

	#if defined(__GNUC__)
		#ifdef CR_SDK_EXPORTS
			#define SCRSDK_API __attribute__ ((visibility ("default")))
		#else
			#define SCRSDK_API
		#endif
	#endif

#define __T(x) x

#endif

#include "CrCommandData.h"
#include "CrDefines.h"
#include "CrDeviceProperty.h"
#include "CrError.h"
#include "CrImageDataBlock.h"
#include "CrTypes.h"
#include "ICrCameraObjectInfo.h"

namespace SCRSDK
{

class IDeviceCallback;

typedef void* objeventcallback;
typedef void(*fneventcallback)(objeventcallback obj, CrInt16u eventCode, CrInt32u param1, CrInt32u /*param2*/, CrInt32u /*param3*/);

/*SDK API*/
extern "C"
SCRSDK_API
bool Init(CrInt32u logtype = 0);

extern "C"
SCRSDK_API
bool Release();

extern "C"
SCRSDK_API
// This function enumerates the cameras that are connected to the pc via the protocol and the physical connection that the library supports.
CrError EnumCameraObjects(ICrEnumCameraObjectInfo** ppEnumCameraObjectInfo, CrInt8u timeInSec = 3);

extern "C"
SCRSDK_API
ICrCameraObjectInfo* CreateCameraObjectInfo(CrChar* name, CrChar *model, CrInt16 usbPid, CrInt32u idType, CrInt32u idSize, CrInt8u* id, CrChar *connectTypeName, CrChar *adaptorName, CrChar *pairingNecessity, CrInt32u sshSupport = 0);

//This function is Create an ICrCameraObjectInfo without using EnumCameraObjects.(Case USB Connection)
extern "C"
SCRSDK_API
CrError CreateCameraObjectInfoUSBConnection(ICrCameraObjectInfo** pCameraObjectInfo, CrCameraDeviceModelList model, CrInt8u* usbSerialNumber);

//This function is Create an ICrCameraObjectInfo without using EnumCameraObjects.(Case Ethernet Connection)
extern "C"
SCRSDK_API
CrError CreateCameraObjectInfoEthernetConnection(ICrCameraObjectInfo** pCameraObjectInfo, CrCameraDeviceModelList model, CrInt32u ipAddress, CrInt8u* macAddress, CrInt32u sshSupport = 0);

extern "C"
SCRSDK_API
CrError EditSDKInfo(CrInt16u infotype);

extern "C"
SCRSDK_API
CrError GetFingerprint(/*in*/ ICrCameraObjectInfo* pCameraObjectInfo, /*out*/ char* fingerprint, /*out*/ CrInt32u* fingerprintSize);

extern "C"
SCRSDK_API
// This function connects the specified camera as Remote Connect Device.
CrError Connect(/*in*/ ICrCameraObjectInfo* pCameraObjectInfo, /*in*/  IDeviceCallback* callback, /*out*/ CrDeviceHandle* deviceHandle, /*in*/ CrSdkControlMode openMode = CrSdkControlMode_Remote, /*in*/ CrReconnectingSet reconnect = CrReconnecting_ON, const char* userId = 0, const char* userPassword = 0, const char* fingerprint = 0, CrInt32u fingerprintSize = 0);

extern "C"
SCRSDK_API
// This function disconnects the connection device.
CrError Disconnect(/*in*/ CrDeviceHandle deviceHandle);

extern "C"
SCRSDK_API
// This function release and finalize the device.
CrError ReleaseDevice(/*in*/ CrDeviceHandle deviceHandle);

extern "C"
SCRSDK_API
CrError GetDeviceProperties(/*in*/ CrDeviceHandle deviceHandle, /*out*/CrDeviceProperty** properties, /*out*/ CrInt32* numOfProperties);

extern "C"
SCRSDK_API
CrError GetSelectDeviceProperties(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrInt32u numOfCodes, /*in*/ CrInt32u* codes, /*out*/CrDeviceProperty** properties, /*out*/ CrInt32* numOfProperties);

extern "C"
SCRSDK_API
CrError ReleaseDeviceProperties(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrDeviceProperty* properties);

extern "C"
SCRSDK_API
CrError SetDeviceProperty(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrDeviceProperty* pProperty);

extern "C"
SCRSDK_API
CrError SendCommand(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrInt32u commandId, /*in*/CrCommandParam commandParam);

extern "C"
SCRSDK_API
CrError GetLiveViewImage(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrImageDataBlock*imageData);

extern "C"
SCRSDK_API
CrError GetLiveViewImageInfo(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrImageInfo* info);

extern "C"
SCRSDK_API
CrError GetLiveViewProperties(/*in*/ CrDeviceHandle deviceHandle, /*out*/CrLiveViewProperty** properties, /*out*/ CrInt32* numOfProperties);

extern "C"
SCRSDK_API
CrError GetSelectLiveViewProperties(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrInt32u numOfCodes, /*in*/ CrInt32u* codes, /*out*/CrLiveViewProperty** properties, /*out*/ CrInt32* numOfProperties);

extern "C"
SCRSDK_API
CrError ReleaseLiveViewProperties(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrLiveViewProperty* properties);

extern "C"
SCRSDK_API
CrError GetDeviceSetting(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrInt32u key, /*out*/ CrInt32u* value);

extern "C"
SCRSDK_API
CrError SetDeviceSetting(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrInt32u key, /*out*/ CrInt32u value);

extern "C"
SCRSDK_API
CrError SetSaveInfo(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrChar *path, CrChar* prefix, CrInt32 no);

// Get SDK version constant - Determined at build time
extern "C"
SCRSDK_API
CrInt32u GetSDKVersion();

// Get SDK serial number constant
extern "C"
SCRSDK_API
CrInt32u GetSDKSerial();

// Get date folders Information
extern "C"
SCRSDK_API
CrError GetDateFolderList(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrMtpFolderInfo** folders, /*out*/ CrInt32u* numOfFolders);

// Get contents handles array
extern "C"
SCRSDK_API
CrError GetContentsHandleList(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrFolderHandle folderHandle, /*out*/ CrContentHandle** contentsHandles, /*out*/ CrInt32u* numOfContents);

// Get contents Information
extern "C"
SCRSDK_API
CrError GetContentsDetailInfo(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrContentHandle contentHandle, /*out*/ CrMtpContentsInfo* contentsInfo);

// Release get contents Information
extern "C"
SCRSDK_API
CrError ReleaseDateFolderList(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrMtpFolderInfo* folders);

// Release get contents handles array
extern "C"
SCRSDK_API
CrError ReleaseContentsHandleList(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrContentHandle* contentsHandles);

// Pull(download) contents file
extern "C"
SCRSDK_API
CrError PullContentsFile(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrContentHandle contentHandle, /*in*/ CrPropertyStillImageTransSize size = CrPropertyStillImageTransSize_Original, /*in*/ CrChar* path = 0, /*in*/ CrChar* fileName = 0);

// Get thumbnail file
extern "C"
SCRSDK_API
CrError GetContentsThumbnailImage(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrContentHandle contentHandle, /*out*/ CrImageDataBlock* imageData, /*out*/ CrFileType* fileType);

extern "C"
SCRSDK_API
CrError DownloadSettingFile(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrDownloadSettingFileType type, CrChar* filePath = 0, CrChar* fileName = 0, const char* password = 0);

extern "C"
SCRSDK_API
CrError UploadSettingFile(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrUploadSettingFileType type, CrChar* fileName, const char* password = 0);

extern "C"
SCRSDK_API
CrError RequestDisplayStringList(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrDisplayStringType type);

extern "C"
SCRSDK_API
CrError GetDisplayStringTypes(/*in*/ CrDeviceHandle deviceHandle, /*out*/CrDisplayStringType** types, /*out*/ CrInt32u* numOfTypes);

extern "C"
SCRSDK_API
CrError GetDisplayStringList(/*in*/ CrDeviceHandle deviceHandle, /*in*/CrDisplayStringType type,/*out*/ CrDisplayStringListInfo** list, /*out*/ CrInt32u* numOfList);

extern "C"
SCRSDK_API
CrError ReleaseDisplayStringTypes(/*in*/ CrDeviceHandle deviceHandle, CrDisplayStringType* types);

extern "C"
SCRSDK_API
CrError ReleaseDisplayStringList(/*in*/ CrDeviceHandle deviceHandle,CrDisplayStringListInfo* list);

extern "C"
SCRSDK_API
CrError GetMediaProfile(/*in*/ CrDeviceHandle deviceHandle, CrMediaProfile slot, /*out*/ CrMediaProfileInfo** mediaProfile, CrInt32u* numOfProfile);

extern "C"
SCRSDK_API
CrError ReleaseMediaProfile(/*in*/ CrDeviceHandle deviceHandle, CrMediaProfileInfo * mediaProfile);

extern "C"
SCRSDK_API
CrError RequestLensInformation(/*in*/ CrDeviceHandle deviceHandle);

extern "C"
SCRSDK_API
CrError GetLensInformation(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrLensInformation** list, /*out*/ CrInt32u* numOfList);

extern "C"
SCRSDK_API
CrError ReleaseLensInformation(/*in*/ CrDeviceHandle deviceHandle, CrLensInformation* list);

extern "C"
SCRSDK_API
CrError ImportLUTFile(/*in*/ CrDeviceHandle deviceHandle, CrChar* fileName, CrBaseLookNumber baseLookNumber);

extern "C"
SCRSDK_API
CrError RequestFTPServerSettingList(/*in*/ CrDeviceHandle deviceHandle);

extern "C"
SCRSDK_API
CrError GetFTPServerSettingList(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrFTPServerSetting** list, /*out*/ CrInt32u* numOfList);

extern "C"
SCRSDK_API
CrError ReleaseFTPServerSettingList(/*in*/ CrDeviceHandle deviceHandle, CrFTPServerSetting* list);

extern "C"
SCRSDK_API
CrError SetFTPServerSetting(/*in*/ CrDeviceHandle deviceHandle, CrFTPServerSetting* setting);

extern "C"
SCRSDK_API
CrError RequestFTPJobList(/*in*/ CrDeviceHandle deviceHandle);
	
extern "C"
SCRSDK_API
CrError GetFTPJobList(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrFTPJobInfo ** list, /*out*/ CrInt32u* numOfList);

extern "C"
SCRSDK_API
CrError ReleaseFTPJobList(/*in*/ CrDeviceHandle deviceHandle, CrFTPJobInfo* list);

extern "C"
SCRSDK_API
CrError ControlFTPJobList(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrFTPJobControlType control, /*in*/ void* jobList, /*in*/ CrInt32u numOfList, /*in*/ CrFTPJobDeleteType deleteType = CrFTPJobDeleteType_Individual);

extern "C"
SCRSDK_API
CrError GetCRSDKOperationResultsSupported(/*in*/ CrDeviceHandle deviceHandle, CrOperationResultSupportedInfo** opeResSupportInfo, /*out*/ CrInt32u* numOfInfo);

extern "C"
SCRSDK_API
CrError ReleaseCRSDKOperationResultsSupported(/*in*/ CrDeviceHandle deviceHandle, CrOperationResultSupportedInfo* opeResSupportInfo);

extern "C"
SCRSDK_API
CrError SetMonitoringDeliverySetting(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrMonitoringDeliverySetting* deliverySetting, /*in*/CrInt32u numOfSetting);

extern "C"
SCRSDK_API
CrError GetMonitoringDeliverySetting(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrMonitoringDeliverySetting** deliverySetting, /*out*/ CrInt32u* numOfSetting);

extern "C"
SCRSDK_API
CrError ReleaseMonitoringDeliverySetting(/*in*/ CrDeviceHandle deviceHandle, CrMonitoringDeliverySetting* deliverySetting);

extern "C"
SCRSDK_API
CrError ControlMonitoring(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrMonitoringOperation operationMode);

extern "C"
SCRSDK_API
CrError RequestZoomAndFocusPreset(/*in*/ CrDeviceHandle deviceHandle);

extern "C"
SCRSDK_API
CrError GetZoomAndFocusPreset(/*in*/ CrDeviceHandle deviceHandle, /*out*/ CrZoomAndFocusPresetInfo** list, /*out*/ CrInt32u* numOfList);

extern "C"
SCRSDK_API
CrError ReleaseZoomAndFocusPreset(/*in*/ CrDeviceHandle deviceHandle, CrZoomAndFocusPresetInfo* list);

extern "C"
SCRSDK_API
CrError RequestFTPTransferResult(/*in*/ CrDeviceHandle deviceHandle, /*in*/ CrSlotNumber slotNumber);
}
#endif //CAMERAREMOTE_SDK_H
