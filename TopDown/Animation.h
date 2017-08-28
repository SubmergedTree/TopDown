#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

class Animation
{
public:
	Animation(sf::Sprite * sprite, float switchAnimationTime);
	Animation();
	~Animation();
	void applyAnimation(std::string key);
	void storeAnimation(std::string key,std::vector<sf::IntRect> animations);
	void setSprite(sf::Sprite * sprite);
	void setSwitchAnimationTime(float switchAnimationTime);
	void setDefault(sf::IntRect rect);
	void update(int width, int height);
private:
	sf::Sprite * animatedSprite;
	std::map<std::string, std::vector<sf::IntRect>> animationContainer;
	std::map<std::string, std::vector<sf::IntRect>>::iterator currentAnimation;
	float switchAnimationTime;
	float currentTime;
	int textureRectIndex;
	sf::Clock clock;
};

