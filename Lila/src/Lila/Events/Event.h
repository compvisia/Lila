#pragma once

#include "Platform/Defines.h"

namespace Lila {
	class Event {
	public:
		Event() {}
		virtual ~Event() {}

		b8 getCanceled() { return canceled_m; }
		void setCanceled(b8 canceled) { canceled_m = canceled; }

	private:
		b8 canceled_m = false;
	};
}