#include "ModuleTextures.h"
#include "ModuleCollision.h"

struct Animation {
	float speed;
	bool loop;
	// Other animation properties
};

enum COLLIDER_TYPE {
	COLLIDER_ENEMY
	// Other collider types
};

class Enemy {
public:
	SDL_Texture* sprites;
	int life;
	int score;
	Animation AnimWasp;
	Animation* animation;
	PowerUp* powerUp; // Assuming PowerUp is a class or struct
	Collider* collider;

	Enemy(const char* spriteFile, int initialLife, int initialScore, float animSpeed, bool animLoop, PowerUp* powerUp) {
		sprites = App->textures->Load(spriteFile);
		life = initialLife;
		score = initialScore;
		AnimWasp.speed = animSpeed;
		AnimWasp.loop = animLoop;
		animation = &AnimWasp;
		PowerUp = powerUp;
		collider = App->collision->AddCollider({0, 0, 31, 16}, COLLIDER_ENEMY, (Module*)App->enemies);
	}

	~Enemy() {
		App->textures->Unload(sprites);
		delete powerUp; // Assuming PowerUp needs to be deallocated
		App->collision->RemoveCollider(collider);
	}

	// Other methods for enemy behavior, rendering, updating, etc.
};
