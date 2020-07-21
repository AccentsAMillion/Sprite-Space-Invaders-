#pragma once

#include <SFML/Graphics.hpp>

class design_state
{
public:
	virtual void Initializing(sf::RenderWindow* window)
	{
	}

	virtual void Updating(sf::RenderWindow* window)
	{
	}

	virtual void Rendering(sf::RenderWindow* window)
	{
	}

	virtual void Destroying(sf::RenderWindow* window)
	{
	}
};

class gameStatus
{
public:
	gameStatus()
	{
	
		this->status = NULL;
	}

	void createWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void createState(design_state* status)
	{
		if (this->status != NULL)
		{
			this->status->Destroying(this->window);
		}
		this->status = status;
		if (this->status != NULL)
		{
			this->status->Initializing(this->window);
		}
	}

	void Updating()
	{
		if (this->status != NULL)
		{
			this->status->Updating(this->window);
		}
	}
	void Rendering()
	{
		if (this->status != NULL)
		{
			this->status->Rendering(this->window);
		}
	}

	~gameStatus()
	{
		if (this->status != NULL)
		{
			this->status->Destroying(this->window);
		}
	}
private:
	sf::RenderWindow* window;
	design_state* status;
};


