#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual	~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		// When the layer gets some event, it will be used here.
		virtual void OnEvent(Event& event) {};

		// This line of code is used for debug purpose.
		inline const std::string& GetName() const { return m_DebugName; };

	protected:
		std::string m_DebugName;
	};

}


