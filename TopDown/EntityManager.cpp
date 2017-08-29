#include "EntityManager.h"

#include "BaseEntity.h"
#include "SpriteEntity.h"

typedef std::pair<std::string, std::vector<std::shared_ptr<BaseEntityExp>>> lmPair;




EntityManager::EntityManager(sf::RenderWindow & window) : window(window), tiledBackground(1,30), tiledForeground(1, 30)
{
	view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
}

EntityManager::~EntityManager()
{
}

void EntityManager::insertEntity(std::shared_ptr<BaseEntityExp> toInsert)
{
	toInsert->onCreate();
	auto it = entities.find(toInsert->getTag());
	if (it != entities.end())
	{
		it->second.push_back(toInsert);
	}
	else
	{
		std::vector<std::shared_ptr<BaseEntityExp>> newVector;
		newVector.push_back(toInsert);
		entities.insert(lmPair(toInsert->getTag(),newVector));
	}

	if (toInsert->isRenderable())
	{
		std::shared_ptr<SpriteEntity> spriteEntity = std::static_pointer_cast<SpriteEntity>(toInsert);
		Coord tmpCoord = spriteEntity->getTiledMapPosition();
		tiledForeground.insert(toInsert->getTag(),tmpCoord);
	}
}

Coord EntityManager::fromTiledToWorldCoordinates(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles)
{
	return tiledForeground.getRealCoordinates(xCoord, yCoord,widthAmountOfTiles, heightAmountOfTiles);
}

void EntityManager::setView(sf::View const & view)
{
	this->view = view;
}

void EntityManager::render()
{
	window.setView(view);
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
			it2->masterUpdate(deltaTime);

			if(it2->isRenderable())
				renderSequence.push(it2);

			if (it2->shouldBeDeleted())
			{
				//delete this entity from container
			}
		}
	}
}

bool EntityManager::Comperator::operator()(std::shared_ptr<BaseEntityExp> a, std::shared_ptr<BaseEntityExp> b)
{
	return a->getRenderPos() > b->getRenderPos();
}
