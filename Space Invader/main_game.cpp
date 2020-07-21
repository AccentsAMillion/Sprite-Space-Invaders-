#include "stdafx.h"
#include "main_game.h"
#include "main_menu_window.h"
#include "score.h"
#include "entity.h"
#include "ship.h"

void main_game::Initializing(sf::RenderWindow* window)
{
	this->fontStyle = new sf::Font();
	this->fontStyle->loadFromFile("Graphics/font.ttf");
	this->score = new Score(*fontStyle, 64U);

	this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *fontStyle, 64U);
	this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
	this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->pausedGame = false;
	this->enterButton = false;

	this->controller.Adding("ship", new Ship(window->getPosition().x /2, window->getSize().y));
}
	void main_game::Updating(sf::RenderWindow* window){
		if (this->pausedGame)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterButton)
			{
				this->pausedGame = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				
				return;
			}
		}
		else
		{
			this->controller.Updating();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterButton)
			{
				this->pausedGame = true;
			}
		}

		this->enterButton = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void main_game::Rendering(sf::RenderWindow* window)
{
	this->controller.Rendering(window);
	window->draw(*this->score);
	
	if (this->pausedGame)
	{
		window->draw(*this->pausedText);
	}
}
void main_game::Destroying(sf::RenderWindow* window)
{
	delete this->score;
	
	delete this->fontStyle;
}
