#include "Animation.h"



Animation::Animation(sf::Sprite * sprite) : animatedSprite(sprite)
{
}//sds

Animation::~Animation()
{
}

void Animation::applyAnimation(std::string key)
{
	auto iterator = animationContainer.find(key);
	if (iterator != animationContainer.end())
	{
		animatedSprite->setTextureRect(iterator->second);
	}
	else
	{
		std::cout << "Animation not available" << std::endl;
	}
}

void Animation::storeAnimation(std::string key, const sf::IntRect & textureArea)
{
	animationContainer.insert(std::pair<std::string, sf::IntRect>(key, textureArea));
}

void Animation::storeAnimation(std::string key, int x, int y, int w, int h)
{
	animationContainer.insert(std::pair<std::string, sf::IntRect>(key, sf::IntRect(x,y,w,h)));
}
