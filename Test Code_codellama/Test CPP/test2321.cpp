#include <vector>

class GameObjectManager {
private:
    std::vector<GameObject*> gameObjects;

public:
    void AddGameObject(GameObject* obj) {
        gameObjects.push_back(obj);
    }

    void RemoveGameObject(GameObject* obj) {
        for (int i = 0; i < gameObjects.size(); i++) {
            if (gameObjects[i] == obj) {
                gameObjects.erase(gameObjects.begin() + i);
                break;
            }
        }
    }

    GameObject* GetGameObject(int index) {
        return gameObjects[index];
    }

    int GetGameObjectCount() {
        return gameObjects.size();
    }

    void UpdateAllObjects(float deltaTime) {
        for (int i = 0; i < gameObjects.size(); i++) {
            gameObjects[i]->Update(deltaTime);
        }
    }
};
