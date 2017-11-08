#include "EntityManager.h"

#include "BaseEntity.h"
#include "SpriteEntity.h"
#include "TiledEntity.h"
//#include "Util.h"

typedef std::pair<std::string, std::vector<std::shared_ptr<BaseEntityExp>>> lmPair;




EntityManager::EntityManager(sf::RenderWindow & window) : 
	window(window)
{	
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

	if (toInsert->isTiled())
	{
		std::shared_ptr<TiledEntity> tE = util::downcastShrdPtr<TiledEntity, BaseEntityExp>(toInsert);
		tileMap->insertTiledEntity(*tE.get());
	}
}

void EntityManager::setTileMap(TileMap* tM)
{
	this->tileMap = tM;
}

std::vector<std::shared_ptr<BaseEntityExp>> EntityManager::find(std::string key)
{
	auto it = entities.find(key);
	if (it != entities.end())
	{
		return it->second;
	}
	
	return std::vector<std::shared_ptr<BaseEntityExp>>();
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
