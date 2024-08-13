#ifndef CRIMAGEDATABLOCK_H
#define CRIMAGEDATABLOCK_H

#include "CrDefines.h"

#if defined(_MSC_VER)
// Windows definitions
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

class SCRSDK_API CrImageInfo
{
public:
	CrImageInfo();
	~CrImageInfo();

	CrInt32u GetBufferSize();

private:
	CrInt32u width;
	CrInt32u height;
	CrInt32u bufferSize;
};

class SCRSDK_API CrImageDataBlock
{
public:
	CrImageDataBlock();
	~CrImageDataBlock();

	CrInt32u GetFrameNo();

	void SetSize(CrInt32u size);
	CrInt32u GetSize();

	void SetData(CrInt8u* data);

	CrInt32u GetImageSize();
	CrInt8u* GetImageData();

	CrInt32u GetTimeCode();

private:
	CrInt32u frameNo;
	//Buffer size (byte) of pData.
	CrInt32u size;
	//Buffer to store the image body.
	CrInt8u* pData;
	//Size (byte) of image body.
	CrInt32u imageSize;
	//SMPTE 12M time-code from Monitoring library.
	CrInt32u timeCode;
};

}
#endif //CRIMAGEDATABLOCK_H