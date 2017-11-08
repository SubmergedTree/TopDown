#include "TiledEntityTest.h"
#include <iostream>
void TiledEntityTest::onCreate()
{
	pathfinder->insertObstacle(tileMapArea);
}

void TiledEntityTest::update(float deltaTime)
{
}
