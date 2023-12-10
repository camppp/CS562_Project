#include <iostream>
#include <vector>
#include <string>

class ResourceManager {
public:
    std::vector<std::string> fbxList;
};

class ModuleEditor {
public:
    ResourceManager* resourceManager;

    void ShowFbxList(const uint& i);
};

void ModuleEditor::ShowFbxList(const uint& i)
{
    for (uint j = 0; j < resourceManager->fbxList.size(); j++)
    {
        std::string fbxFileName = resourceManager->fbxList[j];
        // Process the FBX file using the index i and the name of the FBX file
        std::cout << "Processing FBX file " << fbxFileName << " with index " << i << std::endl;
        // Placeholder processing logic for each FBX file
    }
}

int main() {
    // Example usage
    ModuleEditor editor;
    ResourceManager manager;
    manager.fbxList = { "file1.fbx", "file2.fbx", "file3.fbx" };
    editor.resourceManager = &manager;
    editor.ShowFbxList(5); // Process the FBX files using index 5
    return 0;
}
