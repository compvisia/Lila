#pragma once

#include "Lila/Lila.h"

#include "Lila/ecs/Entity.h"

#include "Hierarchy.h"
#include "Inspector.h"

namespace Editor {

	class Editor {
	public:

		Editor(Lila::Window* window, Lila::World* world);
		~Editor();

		void update();
		void onImGui();
	private:
		Lila::FrameBuffer* frame;

		Hierarchy* hierarchy;
		Inspector* inspector;
	};

}