#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// Somewhere we have something(function we will define) that returns a Hazel Application pointer for us.
// In this case, "somewhere" means SandboxApp.
extern Hazel::Application* Hazel::CreateApplication();

// The two variables are how command line arguments are passed to main() in C/C++.
// The name can be given whatever as you like.
// argc: argument count, number of arguments that will be passed to your program.
// argv: argument vector, array/vector of the arguments you wanna pass.
// Command line argument is mostly used to control a programe from outside.
int main(int argc, char** argv)
{
	// The argv is C:\dev\Hazel\Sandbox\..\bin\Debug-windows-x86_64\Sandbox\Sandbox.exe
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

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


