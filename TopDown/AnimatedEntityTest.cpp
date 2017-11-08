#include "AnimatedEntityTest.h"
#include <iostream>



void AnimatedEntityTest::onCreate()
{
	//setWidthHeight(800, 300);

}

void AnimatedEntityTest::update(float deltaTime)
{
	applyAnimation("walkDown");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		move(0, -1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		move(-1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		move(0, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		move(1, 0);
	}
}
