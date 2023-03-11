#pragma once

#include "Navia/Core/Layer.h"

#include "Navia/Events/ApplicationEvent.h"
#include "Navia/Events/KeyEvent.h"
#include "Navia/Events/MouseEvent.h"

namespace Navia {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}