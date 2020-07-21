#include "stdafx.h"
#include "ship.h"

Ship::Ship(float x, float y)
{
	this->activeType = 1;
	this->groupedId = 0;
	this->Loading("ship.png");
	this->setColor(sf::Color::Blue);

	this->setPosition(x = this->getGlobalBounds().width / 2, y = this->getGlobalBounds().height / 2);
}

void Ship::Updating()
{
	this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
		Entity::Updating();
}

void Ship::Hit(Entity* entity)
{
	switch (entity->GroupedId())
	{
	case 0:
		break;
	default:
		break;
	}
}


