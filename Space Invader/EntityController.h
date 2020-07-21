#pragma once

#include <unordered_map>
#include <vector>
#include "entity.h"

class EntityController {
public:
	EntityController();
	
	void Adding(std::string name, Entity* entity);
	Entity* Get(std::string name);
	void Updating();
	void Rendering(sf::RenderWindow* window);

	~EntityController();
private:
	std::unordered_map<std::string, Entity*> entities;
};

