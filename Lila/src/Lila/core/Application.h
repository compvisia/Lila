#pragma once

#include <string>

namespace Lila {

	class Application {
	public:
		Application() {};

		virtual void run() {}

		std::string getName() { return name; };

	protected:
		std::string name = "App";
	};

	Application* CreateApp();

}