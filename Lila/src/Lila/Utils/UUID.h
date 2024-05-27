#pragma once

#include "Memory.h"

#include "Platform/Defines.h"

namespace Lila {
	class UUID {
	public:
		UUID();

		operator u64() { return id; }

	private:
		u64 id;
	};
}