void DrawComponents(Entity* entity) {
    // Get the list of components for the selected entity
    std::vector<Component*> components = entity->GetComponents();

    // Draw each component in the inspector window
    for (int i = 0; i < components.size(); i++) {
        Component* component = components[i];

        // Draw the component name and properties
        ImGui::Text("%s", component->GetName().c_str());
        ImGui::Indent();
        for (int j = 0; j < component->GetProperties().size(); j++) {
            Property* property = component->GetProperties()[j];
            ImGui::Text("%s: %s", property->GetName().c_str(), property->GetValue().c_str());
        }
        ImGui::Unindent();

        // Allow modification of the component properties
        if (ImGui::Button("Edit")) {
            // Open a modal window to edit the component properties
            ImGui::OpenPopup("Edit Component");
        }
        if (ImGui::BeginPopup("Edit Component")) {
            for (int j = 0; j < component->GetProperties().size(); j++) {
                Property* property = component->GetProperties()[j];
                ImGui::Text("%s: %s", property->GetName().c_str(), property->GetValue().c_str());
                ImGui::SameLine();
                ImGui::InputText("##value", property->GetValue().c_str(), 100);
            }
            ImGui::EndPopup();
        }
    }
}
