#include "player.h"
#include "SFML\Graphics.hpp"


Player::Player(const sf::Texture  & texture, sf::Vector2f &size) : BaseEntity(texture,size)
{	

}


Player::~Player()
{
}
void Player::move() 
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		shape.move(-0.05, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		shape.move(0.05, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		shape.move(0, -0.05);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		shape.move(0, 0.05);
	}*/
}
void Player::update(float deltaTime)
{
}
