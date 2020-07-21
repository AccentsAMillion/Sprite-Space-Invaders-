#pragma once
#include "EntityController.h"
#include "game_state.h"
#include "score.h"

class main_game : public design_state
{
public:
	void Initializing(sf::RenderWindow* window);
	void Updating(sf::RenderWindow* window);
	void Rendering(sf::RenderWindow* window);
	void Destroying(sf::RenderWindow* window);
private:

	Score* score;
	sf::Text* pausedText;

	sf::Font* fontStyle;

	bool pausedGame, enterButton;
	Entity testing;
	EntityController controller;
		
};