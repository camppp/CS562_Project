#include <iostream>
#include <string>

std::string modifyString(const std::string& input) {
    std::string modifiedString = input;

    // Replace "EditorDoubleValue::" with "UpdatedValue::"
    size_t pos = modifiedString.find("EditorDoubleValue::");
    while (pos != std::string::npos) {
        modifiedString.replace(pos, 19, "UpdatedValue::");
        pos = modifiedString.find("EditorDoubleValue::", pos + 1);
    }

    // Replace "//" with "##"
    pos = modifiedString.find("//");
    while (pos != std::string::npos) {
        modifiedString.replace(pos, 2, "##");
        pos = modifiedString.find("//", pos + 2);
    }

    return modifiedString;
}

int main() {
    std::string input = "void EditorDoubleValue::UpdateUiToLocal() // This function updates the UI";
    std::string modified = modifyString(input);
    std::cout << modified << std::endl;
    return 0;
}
