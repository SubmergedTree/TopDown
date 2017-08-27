#pragma once
#include "SFML\Graphics.hpp"
#include <memory>

#include <string>

#include "EntityManager.h"

class BaseEntity
{
public:
	BaseEntity(const sf::Texture  & texture, sf::Vector2f &size, EntityManager* eM);
	~BaseEntity();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void setRenderPos(int rPos);

	virtual void update(float deltaTime) = 0;


	sf::Sprite* getSprite();
	int getRenderPos();
	std::string getTag();
	//int 


private:
	sf::Sprite sprite;
	int renderPos;
	std::string tag;
	//int 
	int xCoord, yCoord, width, height;
	bool inForeground;
protected:
	EntityManager* entityManager;
};

