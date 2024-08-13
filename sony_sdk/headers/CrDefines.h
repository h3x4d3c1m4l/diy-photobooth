#ifndef CRDEFINES_H
#define CRDEFINES_H

#include "CrTypes.h"
#include "CrError.h"

namespace SCRSDK
{
	typedef CrInt64 CrDeviceHandle;

	typedef CrInt64 CrDeviceFeature;

	typedef CrInt32u CrImageID;

	typedef CrInt32u CrImageType;

	typedef CrInt32u CrFolderHandle;

	typedef CrInt32u CrContentHandle;

	enum CrDataType : CrInt32u
	{
		CrDataType_Undefined	= 0x0000,
		CrDataType_UInt8		= 0x0001,
		CrDataType_UInt16		= 0x0002,
		CrDataType_UInt32		= 0x0003,
		CrDataType_UInt64		= 0x0004,
		CrDataType_UInt128		= 0x0005,
		CrDataType_SignBit		= 0x1000,
		CrDataType_Int8			= CrDataType_SignBit | CrDataType_UInt8,
		CrDataType_Int16		= CrDataType_SignBit | CrDataType_UInt16,
		CrDataType_Int32		= CrDataType_SignBit | CrDataType_UInt32,
		CrDataType_Int64		= CrDataType_SignBit | CrDataType_UInt64,
		CrDataType_Int128		= CrDataType_SignBit | CrDataType_UInt128,
		CrDataType_ArrayBit		= 0x2000,
		CrDataType_UInt8Array	= CrDataType_ArrayBit | CrDataType_UInt8,
		CrDataType_UInt16Array	= CrDataType_ArrayBit | CrDataType_UInt16,
		CrDataType_UInt32Array	= CrDataType_ArrayBit | CrDataType_UInt32,
		CrDataType_UInt64Array	= CrDataType_ArrayBit | CrDataType_UInt64,
		CrDataType_UInt128Array	= CrDataType_ArrayBit | CrDataType_UInt128,
		CrDataType_Int8Array	= CrDataType_ArrayBit | CrDataType_Int8,
		CrDataType_Int16Array	= CrDataType_ArrayBit | CrDataType_Int16,
		CrDataType_Int32Array	= CrDataType_ArrayBit | CrDataType_Int32,
		CrDataType_Int64Array	= CrDataType_ArrayBit | CrDataType_Int64,
		CrDataType_Int128Array	= CrDataType_ArrayBit | CrDataType_Int128,
		CrDataType_RangeBit		= 0x4000,
		CrDataType_UInt8Range	= CrDataType_RangeBit | CrDataType_UInt8,
		CrDataType_UInt16Range	= CrDataType_RangeBit | CrDataType_UInt16,
		CrDataType_UInt32Range	= CrDataType_RangeBit | CrDataType_UInt32,
		CrDataType_UInt64Range	= CrDataType_RangeBit | CrDataType_UInt64,
		CrDataType_UInt128Range	= CrDataType_RangeBit | CrDataType_UInt128,
		CrDataType_Int8Range	= CrDataType_RangeBit | CrDataType_Int8,
		CrDataType_Int16Range	= CrDataType_RangeBit | CrDataType_Int16,
		CrDataType_Int32Range	= CrDataType_RangeBit | CrDataType_Int32,
		CrDataType_Int64Range	= CrDataType_RangeBit | CrDataType_Int64,
		CrDataType_Int128Range	= CrDataType_RangeBit | CrDataType_Int128,
        CrDataType_STR          = 0xFFFF,

	};
	
	#define CrChanged 0x0001

	typedef enum
	{
		DEVICE_CONNECTION_VERSION_UNKNOWN = 0,
		DEVICE_CONNECTION_VERSION_RCP3 = 300,
	}DeviceConnectionVersioin;

	typedef enum : CrInt16u
	{
		SDKINFO_UNKNOWN,
		SDKINFO_AUTHINFO,
	}SDKInfoType;

	typedef enum
	{
		Setting_Key_EnableLiveView = 0,
		Setting_Key_PartialBuffer = 6,
	}SettingKey;

	typedef enum
	{
		ADAPTER_PTP_USB = 0,
		ADAPTER_PTP_IP,
	}CrAdapterType;

	typedef enum
	{
		CAMERAOBJECTID_TYPE_USB = 0,
		CAMERAOBJECTID_TYPE_IP = 2,
	}CrCameraObjectIdType;

	enum CrCameraDeviceModelList : CrInt32u
	{
		CrCameraDeviceModel_ILCE_7RM4,
		CrCameraDeviceModel_ILCE_9M2,
		CrCameraDeviceModel_ILCE_7C,
		CrCameraDeviceModel_ILCE_7SM3,
		CrCameraDeviceModel_ILCE_1,
		CrCameraDeviceModel_ILCE_7RM4A,
		CrCameraDeviceModel_DSC_RX0M2,
		CrCameraDeviceModel_ILCE_7M4,
		CrCameraDeviceModel_ILME_FX3,
		CrCameraDeviceModel_ILME_FX30,
		CrCameraDeviceModel_ILME_FX6,
		CrCameraDeviceModel_ILCE_7RM5,
		CrCameraDeviceModel_ZV_E1,
		CrCameraDeviceModel_ILCE_6700,
		CrCameraDeviceModel_ILCE_7CM2,
		CrCameraDeviceModel_ILCE_7CR,
		CrCameraDeviceModel_ILX_LR1,
		CrCameraDeviceModel_MPC_2610,
		CrCameraDeviceModel_ILCE_9M3,
	};

	enum CrReconnectingSet : CrInt32u
	{
		CrReconnecting_OFF = 0x00000000,
		CrReconnecting_ON,
	};

	enum CrMediaProfile : CrInt32u
	{
		CrMediaProfile_Slot1 = 0x00000001,
		CrMediaProfile_Slot2,
		CrMediaProfile_Slot3,
	};

	enum CrSSHsupportValue : CrInt32u
	{
		CrSSHsupport_OFF = 0x00000000,
		CrSSHsupport_ON,
	};

	static const CrInt32u USB_SERIAL_LENGTH = 12;

	//Settings for receiving captured images
	enum CrPartialFile : CrInt32u {
		CrPartialFile_Default = 0xFFFFFFFF,
		CrPartialFile_NotPartial = 0x00000000,  // USB only, Batch reception of image size
		CrPartialFile_Min = 0x00000001,       // Partial size = 1MB
		CrPartialFile_Max = 0x00000014,    // Partial size = 20MB;
		CrPartialFile_Step = 0x00000001,
	};

	enum CrDeviceSetting
	{
		CrDeviceSetting_Disable = 0,
		CrDeviceSetting_Enable,
	};

	const CrInt32u CrFTPTRANSFERSETTING_SAVEREAD_PASSWORD_MAX = 33; // 32 + 1(null termination)

	enum CrSdkApi : CrInt32u
	{
		CrSdkApi_Unknown = 0x00000000,
		CrSdkApi_Invalid,
		CrSdkApi_SetDeviceProperty,
		CrSdkApi_SendCommand,
	};

	/* Replaced with the following enum.
	enum CrMonitoringOpertation : CrInt8u */

	enum CrMonitoringOperation : CrInt8u
	{
		CrMonitoringOperation_Stop = 0x00,
		CrMonitoringOperation_Start,
	};
}

#endif //CRDEFINES_H
