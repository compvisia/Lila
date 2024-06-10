#pragma once

#include "Lila/Math/Matrices.h"

#include "Platform/Defines.h"

#include <string>

namespace Lila {

	class Shader {
	public:
		virtual void bind() = 0;
		virtual void unbind() = 0;

	protected:
		virtual void create(std::string vertexPath, std::string fragmentPath) = 0;
		virtual void destroy() = 0;

	protected:
		u32 program_m;

	};

}