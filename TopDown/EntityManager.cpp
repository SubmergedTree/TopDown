#include "EntityManager.h"

#include "BaseEntity.h"

typedef std::pair<std::string, std::vector<std::shared_ptr<BaseEntity>>> lmPair;




EntityManager::EntityManager(sf::RenderWindow & window) : window(window), tiledBackground(1,30), tiledForeground(1, 30)
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
		entities.insert(lmPair(toInsert->getTag(),newVector));
	}

}
#include <iostream>
void EntityManager::testBla()
{
	//std::cout << "Bla" << std::endl;
}

void EntityManager::render()
{
	while (!renderSequence.empty())
	{
		window.draw(*renderSequence.top()->getSprite());
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

bool EntityManager::Comperator::operator()(std::shared_ptr<BaseEntity> a, std::shared_ptr<BaseEntity> b)
{
	return a->getRenderPos() > b->getRenderPos();
}
