#include "Animation.h"
#include <iostream>


Animation::Animation(sf::Sprite * sprite, float switchAnimationTime) : 
	animatedSprite(sprite), switchAnimationTime(switchAnimationTime), currentTime(0), textureRectIndex(0)
{
	currentAnimation = animationContainer.find(" ");
}

Animation::Animation()
{
	currentAnimation = animationContainer.find(" ");
}

Animation::~Animation()
{
}

void Animation::applyAnimation(std::string key)
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

void Animation::storeAnimation(std::string key,std::vector<sf::IntRect> animations)
{
	animationContainer.insert(std::pair<std::string, std::vector<sf::IntRect>>(key, animations));
}

void Animation::setSprite(sf::Sprite * sprite)
{
	this->animatedSprite = sprite;
}

void Animation::setSwitchAnimationTime(float switchAnimationTime)
{
	this->switchAnimationTime = switchAnimationTime;
}

void Animation::setDefault(sf::IntRect rect)
{
	animatedSprite->setTextureRect(rect);
}

void Animation::update(int width, int height)
{

	if (currentAnimation != animationContainer.end())
	{
		if (clock.getElapsedTime().asMilliseconds() > switchAnimationTime)
		{

			if (textureRectIndex >= currentAnimation->second.size())
			{
				textureRectIndex = 0;
			}
			else
			{
				textureRectIndex++;
			}
			clock.restart();
		}

		if (textureRectIndex < currentAnimation->second.size())
		{
			animatedSprite->setTextureRect(currentAnimation->second.at(textureRectIndex));
		}
	}
	else
	{
		std::cout << "bad iterator" << std::endl;
	}
	
}
