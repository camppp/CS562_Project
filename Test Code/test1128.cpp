void DrawComponents(Entity* selectedEntity) {
    // Get the list of components attached to the selected entity
    std::vector<Component*> components = selectedEntity->GetComponents();

    // Iterate through each component and draw its properties in the inspector window
    for (Component* component : components) {
        ImGui::Text("Component: %s", component->GetName().c_str());

        // Draw and allow modification of component properties
        for (auto& property : component->GetProperties()) {
            if (property.type == PropertyType::Integer) {
                int value = property.GetValue<int>();
                ImGui::InputInt(property.name.c_str(), &value);
                property.SetValue(value);
            } else if (property.type == PropertyType::Float) {
                float value = property.GetValue<float>();
                ImGui::InputFloat(property.name.c_str(), &value);
                property.SetValue(value);
            } // Handle other property types as needed
        }
    }
}
