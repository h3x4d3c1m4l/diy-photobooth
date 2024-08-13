#ifndef ICRCAMERAOBJECTINFO_H
#define ICRCAMERAOBJECTINFO_H

#include "CrTypes.h"

namespace SCRSDK
{

class ICrCameraObjectInfo
{
public:
	virtual void Release() = 0;
	// device name
	virtual CrChar* GetName() const = 0;
	virtual CrInt32u GetNameSize() const = 0;

    // model name
    virtual CrChar *GetModel() const = 0;
    virtual CrInt32u GetModelSize() const = 0;

	// pid (usb)
	virtual CrInt16 GetUsbPid() const = 0;

	// device id
	virtual CrInt8u* GetId() const = 0;
	virtual CrInt32u GetIdSize() const = 0;
	virtual CrInt32u GetIdType() const = 0;

	// current device connection status
	virtual CrInt32u GetConnectionStatus() const = 0;
    virtual CrChar *GetConnectionTypeName() const = 0;
	virtual CrChar *GetAdaptorName() const = 0;

    // device UUID
    virtual CrChar *GetGuid() const = 0;
    
    // device pairing necessity
    virtual CrChar *GetPairingNecessity() const = 0;

	virtual CrInt16u GetAuthenticationState() const = 0;

    // device SSH Support
    virtual CrInt32u GetSSHsupport() const = 0;
};

class ICrEnumCameraObjectInfo
{
public:
	virtual CrInt32u GetCount() const = 0;
	virtual const ICrCameraObjectInfo* GetCameraObjectInfo(CrInt32u index) const = 0;

	virtual void Release() = 0;
};
    
} // namespace SCRSDK

#endif // ICRCAMERAOBJECTINFO_H
