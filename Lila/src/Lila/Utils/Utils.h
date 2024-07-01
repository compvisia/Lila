#pragma once

#include "Platform/Defines.h"

namespace Lila {

	template <typename T, typename U>
	b8 isInstanceOf(T* t) {
		return dynamic_cast<U*>(t) != nullptr;
	}

}