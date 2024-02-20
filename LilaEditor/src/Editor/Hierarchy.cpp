#include "Hierarchy.h"

#include <string>

namespace Editor {

	Hierarchy::Hierarchy(Lila::World* world) {
		this->world = world;
	}
	Hierarchy::~Hierarchy() {}

	void Hierarchy::update() {}
	void Hierarchy::onImGui() {
		ImGui::Begin("Hierarchy");

		for(Lila::Entity entity = 0; entity < world->getEntities().size(); entity++) {
			Lila::Tag* tag = world->getComponent<Lila::Tag>(entity);

			std::string name = " ";
			name += tag->name;

			ImGuiTreeNodeFlags nodeFlags = 0;

			bool open = ImGui::TreeNodeEx(name.c_str(), nodeFlags);

			if(ImGui::IsItemClicked())
				selected = entity;

			if(!open) continue;

			ImGui::TreePop();

		}
		
		ImGui::End();
	}

}