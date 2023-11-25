#include "impch.h"
#include "VertexArray.h"

#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace IM {
	VertexArray* VertexArray::Create() {
		switch (RendererAPI::GetCurrentAPI()) {
		case RendererAPI::API::None:
			IMAGINE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported !");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		}
		IMAGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}