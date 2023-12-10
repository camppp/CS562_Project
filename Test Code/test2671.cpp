#include <iostream>
#include <unordered_map>
#include <string>

// Forward declarations for dependencies
class GraphicsContext;
class FileSystem;

// Resource class representing a generic resource
class Resource {
public:
    virtual ~Resource() {}
    // Common resource operations
    virtual void Load() = 0;
    virtual void Unload() = 0;
};

// Resource manager class responsible for managing resources
class ResourceManager {
private:
    std::unordered_map<std::string, Resource*> resources;
    GraphicsContext* pGraphicsContext;
    FileSystem* pFileSystem;

public:
    ResourceManager(GraphicsContext* graphicsContext, FileSystem* fileSystem)
        : pGraphicsContext(graphicsContext), pFileSystem(fileSystem) {}

    // Register a resource with the manager
    void RegisterResource(const std::string& name, Resource* resource) {
        resources[name] = resource;
    }

    // Load a resource
    void LoadResource(const std::string& name) {
        if (!pGraphicsContext || !pFileSystem) {
            std::cerr << "Missing dependencies for resource loading" << std::endl;
            return;
        }

        auto it = resources.find(name);
        if (it != resources.end()) {
            it->second->Load();
        } else {
            std::cerr << "Resource '" << name << "' not found" << std::endl;
        }
    }

    // Unload a resource
    void UnloadResource(const std::string& name) {
        auto it = resources.find(name);
        if (it != resources.end()) {
            it->second->Unload();
        } else {
            std::cerr << "Resource '" << name << "' not found" << std::endl;
        }
    }

    // Access a loaded resource
    Resource* GetResource(const std::string& name) {
        auto it = resources.find(name);
        if (it != resources.end()) {
            return it->second;
        } else {
            std::cerr << "Resource '" << name << "' not found" << std::endl;
            return nullptr;
        }
    }
};

// Example usage
class Texture : public Resource {
public:
    void Load() override {
        // Load texture implementation
    }

    void Unload() override {
        // Unload texture implementation
    }
};

int main() {
    // Create dependencies
    GraphicsContext* pGraphicsContext = new GraphicsContext();
    FileSystem* pFileSystem = new FileSystem();

    // Create resource manager
    ResourceManager resourceManager(pGraphicsContext, pFileSystem);

    // Register and load resources
    Texture* texture = new Texture();
    resourceManager.RegisterResource("Texture1", texture);
    resourceManager.LoadResource("Texture1");

    // Access and use loaded resource
    Resource* loadedTexture = resourceManager.GetResource("Texture1");
    if (loadedTexture) {
        // Use the loaded texture
    }

    // Clean up
    delete pGraphicsContext;
    delete pFileSystem;
    delete texture;

    return 0;
}
