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

			
			

			Lila::Tag& tag = registry->getComponent<Lila::Tag>(entity);
			char name[255]{};
			strncpy(name, tag.name.c_str(), sizeof(name) - 1);

			ImGui::InputText("##Name", name, 64);

			tag.name = name;

			ImGui::Columns(2);

			ImGui::Text("Position");

			ImGui::Text("Rotation");

			ImGui::Text("Scale");

			ImGui::NextColumn();

			Lila::Transform& transform = registry->getComponent<Lila::Transform>(entity);
			
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

			ImGui::DragFloat3("##position", transform.position.toArray(), 0.02f);

			ImGui::DragFloat3("##rotation", transform.rotation.toArray(), 0.02f);

			ImGui::DragFloat3("##scale", transform.scale.toArray(), 0.02f);
			
			ImGui::PopStyleVar();

			ImGui::Columns(1);
		}	


		ImGui::End();
	}
	
}