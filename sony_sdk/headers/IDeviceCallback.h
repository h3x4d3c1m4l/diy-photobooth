#ifndef IDEVICECALLBACK_H
#define IDEVICECALLBACK_H

#include	"CrDefines.h"

namespace SCRSDK
{

class IDeviceCallback
{
public:
	virtual void OnConnected(DeviceConnectionVersioin version) { }

	virtual void OnDisconnected(CrInt32u error) { }

	virtual void OnPropertyChanged() { }

	virtual void OnPropertyChangedCodes(CrInt32u num, CrInt32u* codes) { }

	virtual void OnLvPropertyChanged() { }

	virtual void OnLvPropertyChangedCodes(CrInt32u num, CrInt32u* codes) { }

	virtual void OnCompleteDownload(CrChar* filename, CrInt32u type = 0xFFFFFFFF) { }

	virtual void OnNotifyContentsTransfer(CrInt32u notify, CrContentHandle handle, CrChar* filename = 0) { }

	virtual void OnWarning(CrInt32u warning) { }

	virtual void OnWarningExt(CrInt32u warning, CrInt32 param1, CrInt32 param2, CrInt32 param3) { }

	virtual void OnError(CrInt32u error) { }

	virtual void OnNotifyFTPTransferResult(CrInt32u notify, CrInt32u numOfSuccess, CrInt32u numOfFail) { }
};

}// namespace SCRSDK

#endif // IDEVICECALLBACK_H
