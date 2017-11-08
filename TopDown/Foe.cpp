#include "Foe.h"


#include <iostream>
#include <list>

void Foe::onCreate()
{
}

bool b = true;
std::list<sf::Vector2f> waypoints;

void Foe::update(float deltaTime)
{
	if (player == nullptr)
	{
		findPlayer();
	}
	else
	{
		if (b)
		{
			waypoints = pathfinder->getPathByWorldCoords(this->getPosition(), player->getPosition());
			b = false;

			for (auto it : waypoints)
			{
				std::cout << it.x << " : " << it.y << std::endl;
			}
		}


		moveWaypoints(waypoints,deltaTime,0.5);	
	}
}

void Foe::findPlayer()
{
	try
	{
		player = entityManager->findSingle<AnimatedEntityTest>("player");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
