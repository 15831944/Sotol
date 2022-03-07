#pragma once

#define PLATFORM_DESKTOP 1

#if !defined( _WIN64 )
	#error Only 64-bit platforms are supported
#endif

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#define PLATFORM_SUPPORTS_BORDERLESS_WINDOW	 1