#include "Inspector.h"

namespace Editor {

	Inspector::Inspector(Lila::Registry* registry) {
		this->registry = registry;
	}
	Inspector::~Inspector() {}

	void Inspector::update() {
		
	}
	void Inspector::onImGui() {

		ImGui::Begin("Inspector");

		if(selected == -1)
			return;

		for(Lila::Entity entity = 0; entity < Lila::MAX_ENTITIES; entity++) {
			if(selected != entity)
				continue;

			if (registry->hasComponent<Lila::Tag>(entity)) {
				Lila::Tag* tag = registry->getComponent<Lila::Tag>(entity);
				ImGui::Text("Name");
				ImGui::SameLine();
				ImGui::Text("Entity"); // TODO: Remove Place holder
				//ImGui::InputText("##Name", tag->name, 64, ImGuiInputTextFlags_CharsNoBlank);
			}
			
			if (registry->hasComponent<Lila::Transform>(entity)) {
				Lila::Transform* transform = registry->getComponent<Lila::Transform>(entity);
				if(transform == nullptr)
					error("Transform has not been found!");
					
				ImGui::Text("Position");
				ImGui::SameLine();
				ImGui::Text("%d", 10); // TODO: Remove Place holder

				/*ImGui::Text("Rotation");
				ImGui::SameLine();
				ImGui::InputFloat3("##rotation", transform->rotation);

				ImGui::Text("Scale");
				ImGui::SameLine();
				ImGui::InputFloat3("##scale", transform->scale);*/
			}
		}	


		ImGui::End();
	}
	
}