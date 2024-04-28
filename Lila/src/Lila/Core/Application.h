#pragma once

#include "Logger.h"
#include "Lila/Utils/UUID.h"

#include <string>

namespace Lila {
	class Application {
	public:
		Application() {}
		virtual ~Application() { lila_info("Deleted Application: %s", name_m.c_str()); };

		virtual void create() {};
		virtual void run() {};

		std::string getName() { return name_m; }
 		UUID getUUID() { return uuid_m; };

	protected:
		std::string name_m;
		UUID uuid_m;
	};

	Shared<Application> createApplication();
}