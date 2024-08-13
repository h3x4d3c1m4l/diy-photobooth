#ifndef CRTYPES_H
#define CRTYPES_H

// #if defined(_MSC_VER)
// #include <tchar.h>
// #else
// #define __T(x) x
// #endif

#if defined(__APPLE__)

#define	_SIZE_T_
#include	<sys/types.h>
typedef int32_t				CrInt32;	///< 32bit signed integer
typedef u_int32_t			CrInt32u;	///< 32bit unsigned integer
typedef int64_t				CrInt64;	///< 64bit signed integer
typedef u_int64_t			CrInt64u;	///< 64bit unsigned integer

#elif defined(_WIN32) || defined(_WIN64)

typedef __int32				CrInt32;	///< 32bit signed integer
typedef unsigned __int32	CrInt32u;	///< 32bit unsigned integer
typedef __int64				CrInt64;	///< 64bit signed integer
typedef unsigned __int64	CrInt64u;	///< 64bit unsigned integer

#elif defined(__linux__)
#include	<sys/types.h>
typedef int32_t				CrInt32;	///< 32bit signed integer
typedef u_int32_t			CrInt32u;	///< 32bit unsigned integer
typedef int64_t				CrInt64;	///< 64bit signed integer
typedef u_int64_t			CrInt64u;	///< 64bit unsigned integer

#else	// not __APPLE__, not _WIN32, not _WIN64, and not __linux__

#error Unsupported platform.

#endif	// not __APPLE__, not _WIN32, not _WIN64, and not __linux__

typedef char				CrInt8;		///<  8bit signed integer
typedef unsigned char		CrInt8u;	///<  8bit unsigned integer
typedef short				CrInt16;	///< 16bit signed integer
typedef unsigned short		CrInt16u;	///< 16bit unsigned integer
typedef char				CrAChar;
typedef wchar_t				CrWChar;
#if defined(_UNICODE) || defined(UNICODE)
typedef CrWChar				CrChar;		///< Platform native character type
#else
typedef CrAChar				CrChar;		///< Platform native character type
#endif

#endif	//CRTYPES_H