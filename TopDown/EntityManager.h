#pragma once
#include <map>
#include <memory>
#include <string>
//#include <tuple>

#include <queue>
#include <SFML\Window.hpp>
#include "Framework.h"
#include "TiledMap.h"

class BaseEntity;

class EntityManager
{
	friend class Framework;
public:
	EntityManager(sf::RenderWindow & window);
	~EntityManager();

	void insertEntity(std::shared_ptr<BaseEntity> toInsert);
	void testBla();
private:

	void render();
	void update(float deltaTime);

	std::map<std::string, std::vector<std::shared_ptr<BaseEntity>>> entities;

	struct Comperator
	{
		bool operator()(std::shared_ptr<BaseEntity> a, std::shared_ptr<BaseEntity> b);
	};

	std::priority_queue<std::shared_ptr<BaseEntity>, std::vector<std::shared_ptr<BaseEntity>>, Comperator> renderSequence;
	
	sf::RenderWindow& window;

	TiledMap tiledForeground;
	TiledMap tiledBackground;
};

