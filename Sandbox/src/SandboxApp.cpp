#include <Navia.h>
#include <Navia/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public Navia::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{
	}
};

Navia::Application* Navia::CreateApplication()
{
	return new Sandbox();
}