#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// Somewhere we have something to return a Hazel Application pointer.
// In this case, "somewhere" means SandboxApp.
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) /// To be learnt!
{
	auto app = Hazel::CreateApplication(); /// auto
	app->Run();
	delete app;
}

#else
	#error HAZEL ONLY SUPPORTS WINDOWS!
#endif
