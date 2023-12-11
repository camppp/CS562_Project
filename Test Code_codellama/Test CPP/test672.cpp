#include <unordered_map>
#include <vector>

namespace babs_ecs {

class Entity {
public:
    Entity(int id) : id_(id) {}

    void AddComponent(const std::string& name, const std::string& type) {
        components_.emplace(name, type);
    }

    void RemoveComponent(const std::string& name) {
        components_.erase(name);
    }

private:
    int id_;
    std::unordered_map<std::string, std::string> components_;
};

class ECSManager {
public:
    ECSManager() {}

    Entity CreateEntity() {
        int id = next_id_++;
        entities_.emplace(id, Entity(id));
        return entities_.at(id);
    }

    void DestroyEntity(int id) {
        entities_.erase(id);
    }

private:
    std::unordered_map<int, Entity> entities_;
    int next_id_ = 0;
};

} // namespace babs_ecs
