#pragma once
#include "BaseEntity.h"


class Obstacle : public BaseEntity
{
public:
	Obstacle(const sf::Texture  & texture, sf::Vector2f &size, EntityManager * eM);
	~Obstacle();

	void update(float deltaTime);

private:
};

