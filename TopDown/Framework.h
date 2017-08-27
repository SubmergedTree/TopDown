#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class Framework 
{
public:
	Framework();
	~Framework();
	void run();
private:
	sf::RenderWindow * window;
	void initializeWindow();
};

