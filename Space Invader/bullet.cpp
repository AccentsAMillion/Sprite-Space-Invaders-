#include "bullet.h"

#define BULLET_SPEED 2.5f

sf::SoundBuffer* enemyDeathSoundBuffer = NULL;
sf::Sound* enemyDeathSound = NULL;

sf::SoundBuffer* playerDeathSoundBuffer = NULL;
sf::Sound* playerDeathSound = NULL;

void setupSounds()
{
	if (enemyDeathSoundBuffer == NULL)
	{
		enemyDeathSoundBuffer = new sf::SoundBuffer();
		enemyDeathSoundBuffer->loadFromFile("Sounds/bounce.wav");
		enemyDeathSound = new sf::Sound(*enemyDeathSoundBuffer);
	}
	if (playerDeathSoundBuffer == NULL)
	{
		playerDeathSoundBuffer = enemyDeathSoundBuffer;
		playerDeathSound = new sf::Sound(*playerDeathSoundBuffer);
		playerDeathSound->setPitch(0.5f);
	}
}

Bullet::Bullet(* lives, float x, float y, float direction, bool good)
{
	setupSounds();

	this->activeType = 1;
	if (good)
	{
		this->groupedId = 3;
	}
	else
	{
		this->groupedId = 4;
	}
	this->Loading("ship.png");
	this->setColor(sf::Color::White);

	this->velocity.y = direction * BULLET_SPEED;


}

Bullet::Bullet(Score* score, float x, float y, float direction, bool good)
{
	setupSounds();

	this->activeType = 1;
	if (good)
	{
		this->groupedId = 3;
	}
	else
	{
		this->groupedId = 4;
	}
	this->Loading("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction * BULLET_SPEED;

	this->score = score;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);
}

void Bullet::Updating(sf::RenderWindow* window)
{
	if (this->getPosition().y <= 0 || this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y)
	{
		if (this->GroupedID() == 4)
		{
			ammo += 1;
		}
		else if (this->GroupedID() == 3)
		{
			playerAmmo += 1;
		}
		this->Destroying();
	}
	Entity::Updating(window);
}

void Bullet::Collision(Entity* entity)
{
	if (this->groupedId == 3)
	{
		switch (entity->GroupedId())
		{
		case 1:
		case 3:
		case 4:
			break;
		case 2:
			playerAmmo += 1;
			enemyCount -= 1;
			this->score->IncrementScore();
			entity->Destroying();
			this->Destroying();
			enemyDeathSound->play();
			break;
		}
	}
	else if (this->groupedId == 4)
	{
		switch (entity->GroupedId())
		{
		case 2:
		case 3:
		case 4:
			break;
		default:
			ammo += 1;
			this->Destroying();
			playerDeathSound->play();
			break;
		}
	}
}