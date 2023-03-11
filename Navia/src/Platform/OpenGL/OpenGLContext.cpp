#include "hzpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Navia {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		NAVIA_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		NAVIA_CORE_ASSERT(status, "Failed to initialize Glad!");

		NAVIA_CORE_INFO("OpenGL Info:");
		NAVIA_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		NAVIA_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		NAVIA_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	#ifdef NAVIA_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		NAVIA_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Navia requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}