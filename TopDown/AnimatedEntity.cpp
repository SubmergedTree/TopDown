#include "AnimatedEntity.h"
#include <iostream>


AnimatedEntity::AnimatedEntity()
{
	currentAnimation = animationContainer.find(" ");
}


AnimatedEntity::~AnimatedEntity()
{
}

void AnimatedEntity::masterUpdate(float deltaTime)
{
	animationUpdate();
	update(deltaTime);
}

void AnimatedEntity::setSwitchAnimationTime(float switchAnimationTime)
{
	this->switchAnimationTime = switchAnimationTime;
}

void AnimatedEntity::setDefault(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
}

void AnimatedEntity::storeAnimation(std::string key, std::vector<sf::IntRect> animations)
{
	animationContainer.insert(std::pair<std::string, std::vector<sf::IntRect>>(key, animations));
}

void AnimatedEntity::applyAnimation(std::string key)
{

	auto iterator = animationContainer.find(key);
	if (iterator != animationContainer.end())
	{
		this->currentAnimation = iterator;
	}
	else
	{
		std::cout << "Animation not available" << std::endl;
	}
}

void AnimatedEntity::animationUpdate()
{
	if (currentAnimation != animationContainer.end())
	{
		if (animationClock.getElapsedTime().asMilliseconds() > switchAnimationTime)
		{

			if (textureRectIndex >= currentAnimation->second.size())
			{
				textureRectIndex = 0;
			}
			else
			{
				textureRectIndex++;
			}
			animationClock.restart();
		}

		if (textureRectIndex < currentAnimation->second.size())
		{
			sprite.setTextureRect(currentAnimation->second.at(textureRectIndex));
			setWidthHeight(worldPosition.width, worldPosition.height);
		}
	}
	else
	{
		std::cout << "bad iterator" << std::endl;
	}
}
