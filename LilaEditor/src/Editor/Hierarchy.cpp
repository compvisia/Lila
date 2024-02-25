#include "Hierarchy.h"

#include <string>

namespace Editor {

	Hierarchy::Hierarchy(Lila::Registry* registry) {
		this->registry = registry;
	}
	Hierarchy::~Hierarchy() {}

	void Hierarchy::update() {}
	void Hierarchy::onImGui() {
		ImGui::Begin("Hierarchy");

		for (Lila::Entity entity = 0; entity < Lila::MAX_ENTITIES; entity++) {
			Lila::Tag* tag = registry->getComponent<Lila::Tag>(entity);
			if(tag == nullptr)
				continue;
			
			ImGuiTreeNodeFlags nodeFlags = 0;

			bool open = ImGui::TreeNodeEx("Entity", nodeFlags); // TODO: Remove Place holder

			if(ImGui::IsItemClicked())
				selected = entity;

			if(!open) continue;

			ImGui::TreePop();
		}
		
		ImGui::End();
	}

}