#pragma once
#include <map>
#include <memory>
#include <string>
//#include <tuple>

#include <queue>
#include <SFML\Window.hpp>
#include "Framework.h"
#include "TiledMap.h"

class BaseEntityExp;

class EntityManager
{
	friend class Framework;
public:
	EntityManager(sf::RenderWindow & window);
	~EntityManager();

	void insertEntity(std::shared_ptr<BaseEntityExp> toInsert);
	void testBla();
private:

	void render();
	void update(float deltaTime);

	std::map<std::string, std::vector<std::shared_ptr<BaseEntityExp>>> entities;

	struct Comperator
	{
		bool operator()(std::shared_ptr<BaseEntityExp> a, std::shared_ptr<BaseEntityExp> b);
	};

	std::priority_queue<std::shared_ptr<BaseEntityExp>, std::vector<std::shared_ptr<BaseEntityExp>>, Comperator> renderSequence;
	
	sf::RenderWindow& window;

	TiledMap tiledForeground;
	TiledMap tiledBackground;
};

