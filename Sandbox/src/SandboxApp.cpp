#include <Hazel.h>

// Sandbox will be an .exe file while Hazel is .dll which contains all the stuff. 
// Set as Startup project instead of Hazel and also change the order of Sandbox and Hazel in the text format inside Hazel.sln.
// Have to link them together, rigth click "Sandbx" -> Add -> Reference -> Check Hazel. So when Hazel generates a .lib and .dll(This is going to be run this project) file, Sandbox is going to be linked into Hazel(by .lib file).
// Check in Linker -> Command line.

class ExampleLayer : public Hazel::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{
	}

};

//int main()
//{
//	Sandbox* sandbox = new Sandbox();
//	sandbox->Run();
//	delete sandbox;
//}

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox(); // Return a new class instance.
}