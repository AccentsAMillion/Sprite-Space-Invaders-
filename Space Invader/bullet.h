#pragma once

#include "entity.h"
#include "score.h"

extern int ammo;
extern int playerAmmo;
extern int enemyCount;

class Bullet : public Entity
{
public:
	Bullet(Score* score, float x, float y, float direction, bool good);
	void Updating(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	Score* score;
};