#pragma once

#include "Core.h"
#include "Logger.h"
#include "Window.h"

#include <string>

namespace Lila {

	struct ApplicationSpecs {
		std::string name = "App";
		
		bool headless = false;

		unsigned int width  = 1280;
		unsigned int height = 720;
	};

	class Application {
	public:
		Application() {}
		virtual ~Application() { destroy(); }

		virtual void run() {}

		ApplicationSpecs getSpecs() { return specs; }
		Window* getWindowClass() { return window.get(); }
	
	protected:
		void init();
		void destroy();

	protected:
		ApplicationSpecs specs;
		Ref<Window> window;
	};

	Application* CreateApp();

}