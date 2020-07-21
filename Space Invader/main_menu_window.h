#pragma once

#include "game_state.h"

class main_menu_window : public design_state
{
public:
	void Initializing(sf::RenderWindow* window);
	void Rendering(sf::RenderWindow* window);
	void Destroying(sf::RenderWindow* window);
private:
	sf::Font* fontStyle;
	sf::Text* gameTitle;
	sf::Text* playGame;
	sf::Text* quitGame;

	int selectionItem;

	bool upArrow, downArrow, leftArrow, rightArrow;

};

