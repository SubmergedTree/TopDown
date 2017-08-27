#pragma once
#include <map>
#include <memory>
#include <string>
#include <tuple>

#include "BaseEntity.h"
#include <queue>
#include <SFML\Window.hpp>
#include "Framework.h"


class EntityManager
{
	friend class Framework;
public:
	EntityManager(sf::RenderWindow & window);
	~EntityManager();

	void insertEntity(std::shared_ptr<BaseEntity> toInsert);

	//bool collideWith(std::shared_ptr<BaseEntity> entity);
	//bool collideWith(std::shared_ptr<BaseEntity> entity);

private:

	void render();
	void update(float deltaTime);

	std::map<std::string, std::vector<std::shared_ptr<BaseEntity>>> entities;

	struct Comperator
	{
		bool operator()(std::shared_ptr<BaseEntity> a, std::shared_ptr<BaseEntity> b)
		{
			return a->getRenderPos() > b->getRenderPos();
		}
	};

	std::priority_queue<std::shared_ptr<BaseEntity>, std::vector<std::shared_ptr<BaseEntity>>, Comperator> renderSequence;

	sf::RenderWindow& window;
};

