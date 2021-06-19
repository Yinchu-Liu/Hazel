#pragma once


// Do not forget to define a couple of macros in:
// Hazel(Right click) -> Configuration Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions. 
// Sandbox project should be performed the same way!
// Make sure check All Configurations at top left.
#ifdef HZ_PLATFORM_WINDOWS // It only applies to Windows!
	#ifdef HZ_BUILD_DLL // Which means "HZ_BUILD_DLL" this macro can only be find for Hazel prject and Sandbox cannot.
		#define	HAZEL_API __declspec(dllexport) // Define HAZEL_API as __declspec(dllexport)
	#else
		#define	HAZEL_API __declspec(dllimport)
	#endif
#else
	#error HAZEL ONLY SUPPORTS WINDOWS!
#endif