#include <imgui.h>
#include <glm/glm.hpp>

// Define the Tool interface
class Tool {
public:
    virtual void drawToModelView() = 0;
};

// ModelView class encapsulating the model view functionality
class ModelView {
public:
    void drawToModelView(Tool& activeTool) {
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        ImGui::Begin("ModelView", nullptr, 0);

        // Let the active tool draw to the model view
        activeTool.drawToModelView();

        ImGui::End();
        ImGui::PopStyleColor();
    }
};

// Example of a tool implementing the Tool interface
class ExampleTool : public Tool {
public:
    void drawToModelView() override {
        // Draw tool-specific content to the model view using ImGui functions
        ImGui::Text("Drawing with ExampleTool");
    }
};

int main() {
    ModelView modelView;
    ExampleTool exampleTool;

    // Draw the active tool to the model view
    modelView.drawToModelView(exampleTool);

    return 0;
}
