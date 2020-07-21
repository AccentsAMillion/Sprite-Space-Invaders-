#include "stdafx.h"
#include <iostream>
#include "main_menu_window.h"
#include "main_game.h"

int difficulty = 1;
void main_menu_window::Initializing(sf::RenderWindow* window)
{
	this->selectionItem = 0;

	this->fontStyle = new sf::Font();
	this->fontStyle->loadFromFile("Graphics/font.ttf");

	this->gameTitle = new sf::Text("Space Intruders", *this->fontStyle, 256U);
	this->gameTitle->setOrigin(this->gameTitle->getGlobalBounds().width / 2, this->gameTitle->getGlobalBounds().height / 2);
	this->gameTitle->setPosition(window->getSize().x / 2, window->getSize().y / 8);

	this->playGame = new sf::Text("Play Game", *this->fontStyle, 128U);
	this->playGame->setOrigin(this->playGame->getGlobalBounds().width / 2, this->playGame->getGlobalBounds().height / 2);
	this->playGame->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->quitGame = new sf::Text("Quit Game", *this->fontStyle, 128U);
	this->quitGame->setOrigin(this->quitGame->getGlobalBounds().width / 2, this->quitGame->getGlobalBounds().height / 2);
	this->quitGame->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->playGame->getGlobalBounds().height);

}

void main_menu_window::Rendering(sf::RenderWindow* window)
{
	this->playGame->setColor(sf::Color::White);
	this->quitGame->setColor(sf::Color::White);
	switch (this->selectionItem)
	{
	case 0:
		this->playGame->setColor(sf::Color::Red);
		break;
	case 1:
		this->quitGame->setColor(sf::Color::Red);
		break;
	}
	window->draw(*this->gameTitle);
	window->draw(*this->playGame);
	window->draw(*this->quitGame);
}
void main_menu_window::Destroying(sf::RenderWindow* window)
{
	delete this->fontStyle;
	delete this->gameTitle;
	delete this->playGame;
	delete this->quitGame;
}
