#include <iostream>

// Simplified implementation of ImGuiManager for demonstration purposes
class ImGuiManager {
public:
    void ListBoxHeader(const char* label, const ImVec2& size) {
        // Implementation of ListBoxHeader
        std::cout << "Displaying ListBoxHeader with label: " << label << " and size: (" << size.x << ", " << size.y << ")" << std::endl;
    }

    bool Button(const char* label) {
        // Implementation of Button
        std::cout << "Displaying Button with label: " << label << std::endl;
        // Simulating button click event
        return true; // Assuming the button is always clicked for demonstration
    }
};

// Simulated function for deselecting an inspected class
void DeselectInspectedCls() {
    std::cout << "Deselecting inspected class" << std::endl;
}

int main() {
    ImGuiManager* igm = new ImGuiManager();

    // Simulated usage of ListBoxHeader and Button
    igm->ListBoxHeader("##cls", ImVec2(800, 600)); // Displaying ListBoxHeader with label: ##cls and size: (800, 600)
    if (igm->Button("Back")) {
        DeselectInspectedCls(); // Deselecting inspected class
    }

    delete igm;
    return 0;
}
