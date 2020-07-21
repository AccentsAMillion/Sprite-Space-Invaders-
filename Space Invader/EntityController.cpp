#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController() 
{
}

void EntityController::Adding(std::string name, Entity* entity)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entity));
}

Entity* EntityController::Get(std::string name)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	
	if (found == this->entities.end()) {
		return NULL;
	}
	else {
		return found->second;
	}

}

void EntityController::Updating()
{
	std::vector<std::string>to_Remove;
	for (auto& iterator : this->entities)
	{
		for (auto& iterator2 : this->entities)
		{
			if (iterator.first != iterator2.first) {
				if (iterator.second->CheckHit(iterator2.second))
				{
					iterator.second->Hit(iterator2.second);
					break;
				}

			}

		}
		switch (iterator.second->ActiveType())
		{
		case 0:
			to_Remove.push_back(iterator.first);
			break;
		default:
			iterator.second->Updating();
			break;
		}
	}
	for (auto& iterator : to_Remove)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(iterator);

		if (found != this->entities.end()) 
		{
			delete found->second;
			this->entities.erase(iterator);
		}
	}
	to_Remove.clear();
}

void EntityController::Rendering(sf::RenderWindow* window)
{
	for (auto& iterator : this->entities)
	{
		window->draw(*iterator.second);
	}
}

EntityController::~EntityController()
{
	for (auto& iterator : this->entities)
	{
		delete iterator.second;
	}
	this->entities.clear();
}