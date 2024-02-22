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

		for (Lila::Entity entity = 0; entity < registry->getAll().size(); entity++) {
			if(!registry->hasComponent<Lila::Tag>(entity))
				continue;

			Lila::Tag* tag = registry->getComponent<Lila::Tag>(entity);
			
			ImGuiTreeNodeFlags nodeFlags = 0;

			bool open = ImGui::TreeNodeEx(tag->name, nodeFlags);

			if(ImGui::IsItemClicked())
				selected = entity;

			if(!open) continue;

			ImGui::TreePop();

		}
		
		ImGui::End();
	}

}