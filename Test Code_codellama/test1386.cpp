// EntityManager.h
#include <unordered_map>
#include <vector>

class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    int CreateEntity();
    Entity* GetEntity(int id);
    void RemoveEntity(int id);

private:
    std::unordered_map<int, Entity*> entities;
    std::vector<int> entityIds;
};

// EntityManager.cpp
#include "EntityManager.h"

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
}

int EntityManager::CreateEntity() {
    int id = entities.size();
    Entity* entity = new Entity();
    entities[id] = entity;
    entityIds.push_back(id);
    return id;
}

Entity* EntityManager::GetEntity(int id) {
    return entities[id];
}

void EntityManager::RemoveEntity(int id) {
    Entity* entity = entities[id];
    delete entity;
    entities.erase(id);
    entityIds.erase(std::remove(entityIds.begin(), entityIds.end(), id), entityIds.end());
}

// Lvl4Creator.h
#include "EntityManager.h"

class Lvl4Creator {
public:
    Lvl4Creator(EntityManager* entityManager);
    ~Lvl4Creator();

    void Dispose();

private:
    EntityManager* entityManager;
};

// Lvl4Creator.cpp
#include "Lvl4Creator.h"

Lvl4Creator::Lvl4Creator(EntityManager* entityManager) {
    this->entityManager = entityManager;
}

Lvl4Creator::~Lvl4Creator() {
}

void Lvl4Creator::Dispose() {
    for (int id : entityIds) {
        entityManager->RemoveEntity(id);
    }
}
