#include <iostream>

int main() {
    FileSystem fs;

    // Create the file system structure
    FileSystem::Node* root = fs.root;
    root->name = "root";

    FileSystem::Node* file1 = new FileSystem::Node{"file1.txt", true, {}};
    root->children.push_back(file1);

    FileSystem::Node* directory1 = new FileSystem::Node{"directory1", false, {}};
    root->children.push_back(directory1);

    FileSystem::Node* file2 = new FileSystem::Node{"file2.txt", true, {}};
    directory1->children.push_back(file2);

    FileSystem::Node* subdirectory1 = new FileSystem::Node{"subdirectory1", false, {}};
    directory1->children.push_back(subdirectory1);

    FileSystem::Node* file3 = new FileSystem::Node{"file3.txt", true, {}};
    subdirectory1->children.push_back(file3);

    FileSystem::Node* directory2 = new FileSystem::Node{"directory2", false, {}};
    root->children.push_back(directory2);

    FileSystem::Node* file4 = new FileSystem::Node{"file4.txt", true, {}};
    directory2->children.push_back(file4);

    // Calculate the total size of the root directory
    int totalSize = fs.totalSize(root);
    std::cout << "Total size of the root directory: " << totalSize << std::endl;

    return 0;
}
