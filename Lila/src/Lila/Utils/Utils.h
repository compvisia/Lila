#pragma once

namespace Lila {

	template <typename T, typename U>
	bool isIstanceOf(T* t) {
		return dynamic_cast<U*>(t) != nullptr;
	}

}