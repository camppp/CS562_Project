#include <queue>
#include "Projectile.h"
#include "Renderer.h"

class ProjectileQueue {
private:
    std::queue<Projectile*> projectiles;

public:
    void addProjectile(Projectile* projectile) {
        projectiles.push(projectile);
    }

    void removeProjectile() {
        if (!projectiles.empty()) {
            delete projectiles.front();
            projectiles.pop();
        }
    }

    void update(float dt) {
        if (!projectiles.empty()) {
            projectiles.front()->update(dt);
        }
    }

    void draw(Renderer& renderer) {
        for (Projectile* projectile : projectiles) {
            projectile->draw(renderer);
        }
    }
};
