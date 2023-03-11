#pragma once

#include "Navia/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Navia {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define NAVIA_CORE_TRACE(...)    ::Navia::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NAVIA_CORE_INFO(...)     ::Navia::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NAVIA_CORE_WARN(...)     ::Navia::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NAVIA_CORE_ERROR(...)    ::Navia::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NAVIA_CORE_CRITICAL(...) ::Navia::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NAVIA_TRACE(...)         ::Navia::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NAVIA_INFO(...)          ::Navia::Log::GetClientLogger()->info(__VA_ARGS__)
#define NAVIA_WARN(...)          ::Navia::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NAVIA_ERROR(...)         ::Navia::Log::GetClientLogger()->error(__VA_ARGS__)
#define NAVIA_CRITICAL(...)      ::Navia::Log::GetClientLogger()->critical(__VA_ARGS__)
