#pragma once
#include "stdafx.h"
#include "entity.h"


class Ship : public Entity
{
public:
	Ship(float x, float y);
	void Updating();
	void Hit(Entity* entity);
private:
};