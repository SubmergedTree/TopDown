#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
class Animation
{
public:
	Animation(sf::Sprite * sprite);
	~Animation();
	void applyAnimation(std::string key);
	void storeAnimation(std::string key,const sf::IntRect &textureArea);
	void storeAnimation(std::string key,int x, int y, int w, int h);
private:
	sf::Sprite * animatedSprite;
	std::map<std::string, sf::IntRect> animationContainer;
};

