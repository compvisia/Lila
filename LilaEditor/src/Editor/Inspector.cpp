#include "Inspector.h"

namespace Editor {

	Inspector::Inspector(Lila::Registry* registry) {
		this->registry = registry;
	}
	Inspector::~Inspector() {}

	void Inspector::update() {
		
	}
	void Inspector::onImGui() {

		if (selected == -1)
			return;

		ImGui::Begin("Inspector");

		for (Lila::Entity entity = 0; entity < registry->getAll().size(); entity++) {
			if(selected != entity)
				continue;

			if (registry->hasComponent<Lila::Tag>(entity)) {
				Lila::Tag* tag = registry->getComponent<Lila::Tag>(entity);
				ImGui::Text("Name");
				ImGui::SameLine();
				ImGui::Text(tag->name);
				//ImGui::InputText("##Name", tag->name, 64, ImGuiInputTextFlags_CharsNoBlank);
			}
			
			if (registry->hasComponent<Lila::Transform>(entity)) {
				Lila::Transform* transform = registry->getComponent<Lila::Transform>(entity);
				ImGui::Text("Position");
				ImGui::SameLine();
				ImGui::Text("%f", transform->position->X());

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