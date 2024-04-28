#include "EventBus.h"

namespace Lila {
	Unique<EventBus> EventBus::instance_m = makeUnique<EventBus>();
}