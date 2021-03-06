#pragma once
#include "SFML\Graphics.hpp"
#include "BaseEntity.h"
#include "Animation.h"

class Player :public BaseEntity
{
public:
	Player(const sf::Texture  & texture, sf::Vector2f &size, EntityManager * eM);
	~Player();
	void update(float deltaTime);
private:
	Animation animation;
};

