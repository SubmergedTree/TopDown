#include "EntityManager.h"
#include <iostream>

typedef std::pair<std::string, std::vector<std::shared_ptr<BaseEntity>>> lmPair;


EntityManager::EntityManager(sf::RenderWindow & window) : window(window)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::insertEntity(std::shared_ptr<BaseEntity> toInsert)
{


	auto it = entities.find(toInsert->getTag());
	if (it != entities.end())
	{
		it->second.push_back(toInsert);
	}
	else
	{
		std::vector<std::shared_ptr<BaseEntity>> newVector;
		newVector.push_back(toInsert);
		entities.insert(lmPair(toInsert->getTag(), newVector));
		
	}

	
}

void EntityManager::render()
{
	while (!renderSequence.empty())
	{
		window.draw(renderSequence.top()->getSprite());
		renderSequence.pop();
	}
}

void EntityManager::update(float deltaTime)
{
	for (auto it : entities)
	{
		for (auto it2 : it.second)
		{
			it2->update(deltaTime);

			renderSequence.push(it2);
		}
	}
}
