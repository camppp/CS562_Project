#include <unordered_map>
#include <vector>

class Material {
public:
    Material(const std::string& name) : name_(name) {}
    ~Material() {}

    const std::string& getName() const { return name_; }

private:
    std::string name_;
};

class Resource {
public:
    Resource(const std::string& name) : name_(name) {}
    ~Resource() {}

    const std::string& getName() const { return name_; }

private:
    std::string name_;
};

class MaterialManager {
public:
    MaterialManager() {}
    ~MaterialManager() {}

    void createResource(const std::string& name) {
        resources_.emplace(name, std::make_unique<Resource>(name));
    }

    void destroyResource(const std::string& name) {
        auto it = resources_.find(name);
        if (it != resources_.end()) {
            resources_.erase(it);
        }
    }

    void createMaterial(const std::string& name) {
        materials_.emplace(name, std::make_unique<Material>(name));
    }

    void destroyMaterial(const std::string& name) {
        auto it = materials_.find(name);
        if (it != materials_.end()) {
            materials_.erase(it);
        }
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Resource>> resources_;
    std::unordered_map<std::string, std::unique_ptr<Material>> materials_;
};
