#pragma once
#include "SFML\Graphics.hpp"

#include <string>

class BaseEntity
{
public:
	BaseEntity(const sf::Texture  & texture, sf::Vector2f &size);
	~BaseEntity();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void setRenderPos(int rPos);
	virtual void move() = 0;

	virtual void update(float deltaTime) = 0;


	sf::Sprite getSprite();
	int getRenderPos();
	std::string getTag();
private:
	sf::Sprite sprite;
	int renderPos;
	std::string tag;
};

