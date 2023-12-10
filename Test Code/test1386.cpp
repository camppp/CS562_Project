#include <unordered_map>

class Entity {
public:
    Entity(int id) : id(id) {}
    int GetID() const { return id; }
private:
    int id;
};

class EntityManager {
public:
    int CreateEntity() {
        int newID = nextID++;
        entities[newID] = std::make_unique<Entity>(newID);
        return newID;
    }

    Entity* GetEntity(int id) {
        auto it = entities.find(id);
        if (it != entities.end()) {
            return it->second.get();
        }
        return nullptr;
    }

    void RemoveEntity(int id) {
        entities.erase(id);
    }

private:
    int nextID = 1;
    std::unordered_map<int, std::unique_ptr<Entity>> entities;
};

class Lvl4Creator {
public:
    Lvl4Creator(EntityManager* entityManager) : entityManager(entityManager) {}

    void Dispose() {
        entityManager->RemoveEntities();
    }

private:
    EntityManager* entityManager;
};
