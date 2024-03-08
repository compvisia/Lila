#pragma once

#include "Lila/Lila.h"

#include "Lila/ecs/Registry.h"

#include "imgui.h"
#include "Platform/imgui_impl_glfw.h"
#include "Platform/imgui_impl_opengl3.h"

namespace Editor {

	class Hierarchy {
	public:

		Hierarchy(Lila::Registry* registry);
		~Hierarchy();

		void update();
		void onImGui();
		
		Lila::Entity getSelected() { return selected; };
		
	private:
		Lila::Entity selected;

		Lila::Registry* registry;
	};

}