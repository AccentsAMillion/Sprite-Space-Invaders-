#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	sf::Vector2f velocity;

	Entity() {
		this->texture = new sf::Texture();
		this->activeType = 1;
		this->groupedId = 0;
	}

	void Loading(std::string filename)
	{
		this->texture->loadFromFile("Graphics/sprites/*" + filename);
		this->setTexture(*this->texture);
	}

	virtual void Updating()
	{
		this->move(this->velocity);
	}

	bool CheckHit(Entity* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	virtual void Hit(Entity* entity)
	{

	}

	int GroupedId() {
		return this->groupedId;
	}

	int ActiveType()
	{
		return this->activeType;
	}

	void Destroying()
	{
		this->activeType;
	}

	~Entity()
	{
		delete this->texture;
	}
protected:
	int activeType;
	int groupedId;
private:
	sf::Texture* texture;
};

