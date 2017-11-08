#include "Pathfinding.h"
#include <iostream>



Pathfinding::Pathfinding() : tileSize(1) , amountOfTiles(1,1)
{
}


Pathfinding::~Pathfinding()
{
}

void Pathfinding::resetTiles(int tileSize, sf::Vector2u amountOfTiles)
{
	this->tileSize = tileSize;
	this->amountOfTiles = amountOfTiles;
	nodes.resize(amountOfTiles.x);
	//Build a grid of nodes
	for (int x = 0; x < amountOfTiles.x; x++)
	{
		nodes[x].resize(amountOfTiles.y);
		for (int y = 0; y < amountOfTiles.y; y++)
		{
			nodes[x][y] = std::make_shared<AStarNode>(x, y);
		}
	}
}

void Pathfinding::insertObstacle(sf::IntRect area)
{

	if (checkIntRectBoundaries(area))
	{
	//	std::cout << "boundaries" << std::endl;
		std::cout << area.top << area.left << area.width << area.height << std::endl;
		for(int x = area.left; x < area.left + area.width; x++)
			for (int y = area.top; y < area.top + area.height; y++)
			{
			//	std::cout << "boundaries" << std::endl;
				nodes[x][y]->isObstacle = true;
			}
	}
	for (auto it : nodes)
		for (auto it2 : it)
		{
		//	std::cout << "insertObstacle " << it2->isObstacle << ": " << it2->x << " : " << it2->y << std::endl;
		}
}

//for loops are wrong
void Pathfinding::deleteObstacle(sf::IntRect area)
{
	if (checkIntRectBoundaries(area))
	{
		for (int x = area.top; x < area.top + area.height; x++)
			for (int y = area.width; x < area.left + area.width; y++)
			{
				nodes[x][y]->isObstacle = false;
			}
	}
}

std::list<sf::Vector2f> Pathfinding::getPath(sf::Vector2u start, sf::Vector2u destination)
{
	//std::cout << "tiledPos " << start.x << " " << start.y << " " << destination.x << " " << destination.y << std::endl;

	for(auto it : nodes)
		for (auto it2 : it)
		{
	//		std::cout << "getPath "<< it2->isObstacle << ": " << it2->x << " : " << it2->y << std::endl;
		}

	if (start.x >= 0 && start.x < amountOfTiles.x
		&& start.y >= 0 && start.y < amountOfTiles.y
		&& destination.x >= 0 && destination.x < amountOfTiles.x
		&& destination.y >= 0 && destination.y < amountOfTiles.y)
	{
		nodes[start.x][start.y]->isStart = true;
		nodes[start.x][start.y]->costs = 0;

		nodes[destination.x][destination.y]->isEnd = true;

		nodes[start.x][start.y]->calucalteHeuristic(destination.x, destination.y);
		nodes[start.x][start.y]->inOpenList = true;

		openList.push(nodes[start.x][start.y]);


		while (!openList.top()->isEnd)
		{
			putNeighboursInOpenList(destination);
		}

		//std::cout << openList.top()->x << " " << openList.top()->y << std::endl;

		evaluate(openList.top());

		std::list<sf::Vector2f> ret = waypoints;
		waypoints.clear();

		//delete start posistion 
		//ret.pop_front();
		return ret;
	}

	return std::list<sf::Vector2f>();
}

std::list<sf::Vector2f> Pathfinding::getPathByWorldCoords(sf::Vector2f worldStart, sf::Vector2f worldDestination)
{
	//std::cout << worldStart.x << " " << worldStart.y << " " << worldDestination.x << " " << worldDestination.y << std::endl;
	if (worldStart.x < 0 && worldStart.y < 0 && worldDestination.x < 0 && worldDestination.y < 0)
	{
		std::cout << "negative positions - error" << std::endl;
		return std::list<sf::Vector2f>();
	}

	sf::Vector2u start(0,0);
	sf::Vector2u destination(0,0);
	bool foundStart = false;
	bool foundDestination = false;

	std::shared_ptr<AStarNode> inside;

	for (int x = 0; x < nodes.size(); x++)
	{
		for (int y = 0; y < nodes[x].size(); y++)
		{
			inside = nodes[x][y];

			int insideXWorld = inside->x * tileSize; // correct
			int insideYWorld = inside->y * tileSize; // correct

		//	std::cout << inside->x << " " << inside->y << " : " << insideXWorld << " " << insideYWorld << " : "
		//		<< insideXWorld + tileSize << " : " << insideYWorld + tileSize << std::endl;

			if (!foundStart && worldStart.x > insideXWorld  && worldStart.x < insideXWorld + tileSize
				&& worldStart.y > insideYWorld && worldStart.y < insideYWorld + tileSize)
			{
				start.x = inside->x;
				start.y = inside->y;
				foundStart = true;
			}

			if (!foundDestination && worldDestination.x >= insideXWorld && worldDestination.x <= insideXWorld + tileSize
				&& worldDestination.y >= insideYWorld && worldDestination.y <= insideYWorld + tileSize)
			{
				destination.x = inside->x;
				destination.y = inside->y;
				foundDestination = true;
			}
		}
	//	if (foundStart && foundDestination)
	//		break;
	}
	//std::cout << start.x << " " << start.y << " " << destination.x << " " << destination.y << std::endl;
	return getPath(start, destination);//std::list<sf::Vector2f>();//getPath(start, destination);
}

bool Pathfinding::checkOpenListInsertConditions(int x, int y)
{
	return (x < amountOfTiles.x && x > 0
		&& y < amountOfTiles.y && y > 0
		&& !nodes[x][y]->inClosedList
		&& !nodes[x][y]->inOpenList
		&& !nodes[x][y]->isObstacle);
}

void Pathfinding::putNeighboursInOpenList(sf::Vector2u const& destination)
{
	std::shared_ptr<AStarNode> topNode = openList.top();
	openList.pop();

	int x = topNode->x;
	int y = topNode->y;

	std::cout << topNode->isObstacle << topNode->x << topNode->y << std::endl;

	if (checkOpenListInsertConditions(x + 1, y))
	{
		nodes[x + 1][y]->formerCosts = topNode->getCompleteCosts();
		nodes[x + 1][y]->calucalteHeuristic(destination.x, destination.y);
		nodes[x + 1][y]->formerNode = topNode;
		nodes[x + 1][y]->inOpenList = true;
		openList.push(nodes[x + 1][y]);
	}

	if (checkOpenListInsertConditions(x, y + 1))
	{
		nodes[x][y + 1]->formerCosts = topNode->getCompleteCosts();
		nodes[x][y + 1]->calucalteHeuristic(destination.x, destination.y);
		nodes[x][y + 1]->formerNode = topNode;
		nodes[x][y + 1]->inOpenList = true;
		openList.push(nodes[x][y + 1]);
	}

	if (checkOpenListInsertConditions(x - 1, y))
	{
		nodes[x - 1][y]->formerCosts = topNode->getCompleteCosts();
		nodes[x - 1][y]->calucalteHeuristic(destination.x, destination.y);
		nodes[x - 1][y]->formerNode = topNode;
		nodes[x - 1][y]->inOpenList = true;
		openList.push(nodes[x - 1][y]);
	}

	if (checkOpenListInsertConditions(x, y - 1))
	{
		nodes[x][y - 1]->formerCosts = topNode->getCompleteCosts();
		nodes[x][y - 1]->calucalteHeuristic(destination.x, destination.y);
		nodes[x][y - 1]->formerNode = topNode;
		nodes[x][y - 1]->inOpenList = true;
		openList.push(nodes[x][y - 1]);
	}
	topNode->inClosedList = true;
}

bool Pathfinding::checkIntRectBoundaries(sf::IntRect const & area)
{
	return area.top > 0 && area.top < amountOfTiles.y
		&& area.left > 0 && area.left < amountOfTiles.x
		&& area.top + area.height > 0 && area.top + area.height < amountOfTiles.y
		&& area.left + area.width > 0 && area.top + area.height < amountOfTiles.x;
}

void Pathfinding::evaluate(std::shared_ptr<AStarNode> node)
{
	if (node != nullptr)
	{
		sf::Vector2f insertValues;
		insertValues.x = node->x * tileSize;
		insertValues.y = node->y * tileSize;
		waypoints.push_front(insertValues);
		if (!node->isStart)
		{
			evaluate(node->formerNode);
		}
	}
}

void Pathfinding::AStarNode::calucalteHeuristic(int endPosX, int endPosY)
{
	int distanceX = std::abs(endPosX - x);
	int distanceY = std::abs(endPosY - y);

	heuristic = distanceX + distanceY;
}

unsigned Pathfinding::AStarNode::getCompleteCosts()
{
	return formerCosts + costs + heuristic;
}
