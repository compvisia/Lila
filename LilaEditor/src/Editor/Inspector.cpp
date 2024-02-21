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

		/*for (Lila::Entity entity = 0; entity < world->getEntities().size(); entity++) {
			if(selected != entity)
				continue;

			Lila::Tag* tag = world->getComponent<Lila::Tag>(entity);
			ImGui::Text("Name");
			ImGui::SameLine();
			ImGui::InputText("##Name", tag->name, sizeof(tag->name)/sizeof(*tag->name), ImGuiInputTextFlags_CharsNoBlank);

			Lila::Transform* transform = world->getComponent<Lila::Transform>(entity);
			ImGui::Text("Position");
			ImGui::SameLine();
			ImGui::InputFloat3("##position", transform->position.toArray());

			ImGui::Text("Rotation");
			ImGui::SameLine();
			ImGui::InputFloat3("##rotation", transform->rotation.toArray());

			ImGui::Text("Scale");
			ImGui::SameLine();
			ImGui::InputFloat3("##scale", transform->scale.toArray());
		}*/

		ImGui::End();
	}
	
}