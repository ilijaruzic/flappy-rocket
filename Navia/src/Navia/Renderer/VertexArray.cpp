#include "hzpch.h"
#include "Navia/Renderer/VertexArray.h"

#include "Navia/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Navia {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    NAVIA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		NAVIA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}