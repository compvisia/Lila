#pragma once

#include "Event.h"
#include "EventHandler.h"
#include "Lila/Utils/Utils.h"
#include "Lila/Utils/Memory.h"

#include <vector>

namespace Lila {
	
	class EventBus {
	public:
		EventBus() {}
		virtual ~EventBus() {}

		static EventBus* const getInstance() {
			return instance_m.get();
		}

		template<class T>
		static void fireEvent(T& e) {
			EventBus* bus = getInstance();

			for (const auto& handler : bus->handlers) {
				static_cast<EventHandler*>(handler)->onEvent(dynamic_cast<Lila::Event&>(e));
			}
		}

		static void addHandler(EventHandler& handler) {
			EventBus* bus = getInstance();
			void* ptr = static_cast<void*>(&handler);

			bus->handlers.push_back(ptr);
		}

	private:
		std::vector<void*> handlers;
		static Unique<EventBus> instance_m;
	};
}