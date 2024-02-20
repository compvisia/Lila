#pragma once

#include "Lila/ecs/World.h"

#include "imgui.h"
#include "Platform/imgui_impl_glfw.h"
#include "Platform/imgui_impl_opengl3.h"

namespace Editor {

	class Inspector {
	public:

		Inspector(Lila::World* world);
		~Inspector();

		void update();
		void onImGui();

		void setSelected(Lila::Entity entity) { selected = entity; }

	private:
		Lila::Entity selected = -1;

		Lila::World* world;

	};

}