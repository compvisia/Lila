#pragma once

#include "Lila/Core/Logger.h"

#include <type_traits>

namespace Lila {
	class EventHandler {
	public:
		EventHandler() {}
		virtual ~EventHandler() {}

		virtual void onEvent(Event&) = 0;
	};
}