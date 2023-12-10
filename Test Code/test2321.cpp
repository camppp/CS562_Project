#include <vector>

class GameObject {
public:
    virtual void Update(float deltaTime) = 0;
};

class GameObjectManager {
private:
    std::vector<GameObject*> gameObjects;

public:
    void AddGameObject(GameObject* obj) {
        gameObjects.push_back(obj);
    }

    void RemoveGameObject(GameObject* obj) {
        auto it = std::find(gameObjects.begin(), gameObjects.end(), obj);
        if (it != gameObjects.end()) {
            gameObjects.erase(it);
        }
    }

    GameObject* GetGameObject(int index) {
        if (index >= 0 && index < gameObjects.size()) {
            return gameObjects[index];
        }
        return nullptr;
    }

    int GetGameObjectCount() {
        return gameObjects.size();
    }

    void UpdateAllObjects(float deltaTime) {
        for (auto obj : gameObjects) {
            obj->Update(deltaTime);
        }
    }
};
