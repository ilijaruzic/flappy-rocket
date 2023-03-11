workspace "Navia"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Navia/vendor/GLFW/include"
IncludeDir["Glad"] = "Navia/vendor/Glad/include"
IncludeDir["ImGui"] = "Navia/vendor/imgui"
IncludeDir["glm"] = "Navia/vendor/glm"
IncludeDir["stb_image"] = "Navia/vendor/stb_image"

group "Dependencies"
	include "Navia/vendor/GLFW"
	include "Navia/vendor/Glad"
	include "Navia/vendor/imgui"

group ""

project "Navia"
	location "Navia"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Navia/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"NAVIA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "NAVIA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NAVIA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NAVIA_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Navia/vendor/spdlog/include",
		"Navia/src",
		"Navia/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Navia"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "NAVIA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NAVIA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NAVIA_DIST"
		runtime "Release"
		optimize "on"
