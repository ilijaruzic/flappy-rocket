#include "hzpch.h"
#include "Navia/Renderer/RenderCommand.h"

namespace Navia {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}