#pragma once
#include "Navia/Core/Core.h"

#ifdef NAVIA_PLATFORM_WINDOWS

extern Navia::Application* Navia::CreateApplication();

int main(int argc, char** argv)
{
	Navia::Log::Init();

	NAVIA_PROFILE_BEGIN_SESSION("Startup", "NaviaProfile-Startup.json");
	auto app = Navia::CreateApplication();
	NAVIA_PROFILE_END_SESSION();

	NAVIA_PROFILE_BEGIN_SESSION("Runtime", "NaviaProfile-Runtime.json");
	app->Run();
	NAVIA_PROFILE_END_SESSION();

	NAVIA_PROFILE_BEGIN_SESSION("Startup", "NaviaProfile-Shutdown.json");
	delete app;
	NAVIA_PROFILE_END_SESSION();
}

#endif
