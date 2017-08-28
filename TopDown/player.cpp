#include "Player.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

Player::Player(const sf::Texture  & texture, sf::Vector2f &size,EntityManager * eM) : BaseEntity(texture, size, eM)
{
	animation.setSprite(getSprite());
	animation.setSwitchAnimationTime(200);
	std::vector<sf::IntRect> walkDown;
	walkDown.push_back(sf::IntRect(0 , 0, 100, 100));
	walkDown.push_back(sf::IntRect(100, 0, 100, 100));
	walkDown.push_back(sf::IntRect(200, 0, 100, 100));
	animation.storeAnimation("walkDown",walkDown);
	animation.setDefault(sf::IntRect(0, 0, 100, 100));

	setWidthHeight(800, 600);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	std::cout << getWidth() << " " << getHeight() << std::endl;

	//entityManager->testBla();
	animation.setDefault(sf::IntRect(0, 0, 100, 100));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		animation.applyAnimation("walkDown");
		getSprite()->move(-1 * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		getSprite()->move(1 * deltaTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		getSprite()->move(0, -1 * deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		getSprite()->move(0, 1 * deltaTime);
	}
	//std::cout << deltaTime << std::endl;
	animation.update(100,100);
}
