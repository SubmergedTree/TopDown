#include "SpriteEntity.h"
#include "AdditionalMath.h"

SpriteEntity::SpriteEntity() : renderPos(0)
{
}


SpriteEntity::~SpriteEntity()
{
}

sf::Sprite * SpriteEntity::getSprite()
{
	return &sprite;
}

int SpriteEntity::getRenderPos()
{
	return renderPos;
}

void SpriteEntity::setTexture(const sf::Texture & texture)
{
	sprite.setTexture(texture);
}

void SpriteEntity::setRenderPos(int renderPos)
{
	this->renderPos = renderPos;
}


bool SpriteEntity::isRenderable()
{
	return true;
}

void SpriteEntity::setPosition(int x, int y)
{
	worldPosition.x = x; 
	worldPosition.y = y;

	sprite.setPosition(x, y);
}

void SpriteEntity::setWidthHeight(int width, int height)
{
	sprite.setScale(
		width / getSprite()->getLocalBounds().width,
		height / getSprite()->getLocalBounds().height);
	worldPosition.width = width;
	worldPosition.height = height;
}

void SpriteEntity::move(sf::Vector2f distance)
{
	worldPosition.x += distance.x;
	worldPosition.y += distance.y;

	sprite.setPosition(worldPosition.x, worldPosition.y);
}

void SpriteEntity::move(int distanceX, int distanceY)
{
	worldPosition.x += distanceX;
	worldPosition.y += distanceY;

	sprite.setPosition(worldPosition.x, worldPosition.y);
}

#include <iostream>
void SpriteEntity::moveWaypoints(std::list<sf::Vector2f> & waypoints, float deltaTime, float speed)
{
	static bool needNewVelo = true;
	static sf::Vector2f velocity;
	static sf::Vector2f actualWaypoint;
	if (!waypoints.empty())
	{
		
/*
		// actualWaypoint -= actualPosition;
		sf::Vector2f normalizedWPoint;

		//worldPosition.x += normalizedWPoint.x * speed * deltaTime;
		//worldPosition.y += normalizedWPoint.y * speed * deltaTime;
		//std::cin.get();

	//	std::cout << deltaTime << std::endl;

		sf::Vector2f distanceVector = sf::Vector2f(actualWaypoint - this->getPosition());

		float distanceToDestination = std::sqrtf(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

		if (distanceToDestination < 30)
		{
			std::cout << "dtd" << std::endl;
			this->setPosition(actualWaypoint.x, actualWaypoint.y);
		}
		else
		{
			move(normalizedWPoint.x * speed * deltaTime, normalizedWPoint.y * speed * deltaTime);
		}

		std::cout << "moveWaypoints: waypoints: " << actualWaypoint.x << " : " << actualWaypoint.y << std::endl;
		std::cout << "moveWaypoints: move: " << normalizedWPoint.x   << " : " << normalizedWPoint.y   << std::endl;
		std::cout << "moveWaypoints: position: " << worldPosition.x << " : " << worldPosition.y << std::endl;
		//sprite.setPosition(worldPosition.x, worldPosition.y);

		if (worldPosition.x == actualWaypoint.x && worldPosition.y == actualWaypoint.y)
		{
			std::cout << "reachedWaypoint" << std::endl;
			waypoints.pop_front();
		}*/

		if (needNewVelo)
		{
			actualWaypoint = waypoints.front();
			velocity = sf::Vector2f(actualWaypoint.x - worldPosition.x, actualWaypoint.y - worldPosition.y);
			velocity = vec::normalize2f(velocity);
			velocity.x *= speed;
			velocity.y *= speed;
			needNewVelo = false;
		}

	//	std::cout << "actualWaypoint: " << actualWaypoint.x << " : " << actualWaypoint.y << std::endl;
	//	std::cout << "velocity: " << velocity.x << " : " << velocity.y << std::endl;


		worldPosition.x += velocity.x * deltaTime;
		worldPosition.y += velocity.y * deltaTime;


		sprite.setPosition(worldPosition.x, worldPosition.y);

		sf::Vector2f check(actualWaypoint.x - worldPosition.x, actualWaypoint.y - worldPosition.y);

		if(std::sqrtf(check.x * check.x + check.y * check.y) < 20)
		//if (std::sqrtf(velocity.x * velocity.x + velocity.y * velocity.y) < std::sqrtf(check.x * check.x + check.y * check.y))
		{
			velocity.x = 0;
			velocity.y = 0;

			worldPosition.x = actualWaypoint.x;
			worldPosition.y = actualWaypoint.y;
			sprite.setPosition(worldPosition.x, worldPosition.y);
			waypoints.pop_front();
			needNewVelo = true;
		}
	}
}

sf::Vector2f SpriteEntity::getPosition()
{
	return sf::Vector2f(worldPosition.x, worldPosition.y);
}

int SpriteEntity::getWidth()
{
	return getSprite()->getGlobalBounds().width;
}

int SpriteEntity::getHeight()
{
	return getSprite()->getGlobalBounds().height;
}
