#pragma once

#include "Lila/core/Logger.h"

#include <type_traits>

namespace Lila {
	class EventHandler {
	public:
		EventHandler() {}
		virtual ~EventHandler() {}

		virtual void onEvent(Event&) = 0;
	};
}