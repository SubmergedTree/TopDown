#pragma once
#include <map>
#include <memory>
#include <string>
//#include <tuple>

#include <queue>
#include <SFML\Window.hpp>
#include "Framework.h"
#include "TiledMap.h"
#include "TileMap.h"
//#include "Util.h"
#include <exception>

class BaseEntityExp;

namespace util
{
	template<typename SHOULD, typename IS>
	std::shared_ptr<SHOULD> downcastShrdPtr(std::shared_ptr<IS> isPtr)
	{
		return std::static_pointer_cast<SHOULD>(isPtr);
	}
}

class EntityManager
{
	friend class Framework;
public:
	EntityManager(sf::RenderWindow & window);
	~EntityManager();

	void insertEntity(std::shared_ptr<BaseEntityExp> toInsert);

	void setTileMap(TileMap* tM);

	//use unique ptr ? 
	std::vector<std::shared_ptr<BaseEntityExp>> find(std::string key);

	template<class TOCAST>
	std::shared_ptr<TOCAST> findSingle(std::string key)
	{
		std::vector<std::shared_ptr<BaseEntityExp>> ret = find(key);
		if (!ret.empty())
			return util::downcastShrdPtr<TOCAST, BaseEntityExp>(ret[0]);
		else
			throw std::runtime_error("can't find entity");
	}

private:

	void render();
	void update(float deltaTime);

	//linked list instead vector ? 
	std::map<std::string, std::vector<std::shared_ptr<BaseEntityExp>>> entities;

	struct Comperator
	{
		bool operator()(std::shared_ptr<BaseEntityExp> a, std::shared_ptr<BaseEntityExp> b);
	};

	std::priority_queue<std::shared_ptr<BaseEntityExp>, std::vector<std::shared_ptr<BaseEntityExp>>, Comperator> renderSequence;
	
	sf::RenderWindow& window;
	TileMap* tileMap;
};

