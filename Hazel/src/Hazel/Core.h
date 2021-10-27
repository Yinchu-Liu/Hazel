#pragma once

// Do not forget to define a couple of macros in:
// Hazel(Right click right inside this project and DO NOT forget define the macros inside Sandbox) -> Configuration Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions. 
// Sandbox project should be performed the same way!
// Make sure check All "Configurations" at top left.

#ifdef HZ_PLATFORM_WINDOWS // It only applies to Windows!
	#ifdef HZ_BUILD_DLL // Which means "HZ_BUILD_DLL" this macro can only be found for Hazel prject and Sandbox cannot.
		#define	HAZEL_API __declspec(dllexport) // Define HAZEL_API as __declspec(dllexport)
	#else
		#define	HAZEL_API __declspec(dllimport)	// Additionaly in Hazel, we should put another macro different from HAZEL_API so that Sandbox will use dllimport.
	#endif
#else
	#error HAZEL ONLY SUPPORTS WINDOWS!
#endif

// Add assertions.
#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)  // 1 * 2^x