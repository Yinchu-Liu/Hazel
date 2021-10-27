#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// Somewhere we have something(function we will define) that returns a Hazel Application pointer for us.
// In this case, "somewhere" means SandboxApp.
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) /// To be learnt!
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	HZ_INFO("Hello!");

	// It will create an application for us by calling the "extern" Run() function declared inside SandboxApp.cpp while defined inside Application class.
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error HAZEL ONLY SUPPORTS WINDOWS!
#endif
