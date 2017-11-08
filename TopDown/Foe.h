#pragma once
#include "SpriteEntity.h"
#include "AnimatedEntityTest.h"

class Foe : public SpriteEntity
{
public:
	void onCreate();
	void update(float deltaTime);

private:
	std::shared_ptr<AnimatedEntityTest> player;

	void findPlayer();
};

