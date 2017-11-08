#pragma once

#include <cmath>
#include <SFML\Graphics.hpp>
#include <list>
#include <queue>
#include <memory>
#include <functional>

class Pathfinding
{
public:
	//TODO: move resetTiles functionality into constructor
	Pathfinding();
	~Pathfinding();

	void resetTiles (int tileSize, sf::Vector2u amountOfTiles);

	void insertObstacle(sf::IntRect area);
	void deleteObstacle(sf::IntRect area);

	std::list<sf::Vector2f> getPath(sf::Vector2u start, sf::Vector2u destination);
	std::list<sf::Vector2f> getPathByWorldCoords(sf::Vector2f worldStart, sf::Vector2f worldDestination);

private:
	int tileSize;
	sf::Vector2u amountOfTiles;

	bool checkOpenListInsertConditions(int x, int y);
	void putNeighboursInOpenList(sf::Vector2u const& destination);

	bool checkIntRectBoundaries(sf::IntRect const& area);

	struct AStarNode
	{
		unsigned formerCosts = 0;
		unsigned costs = 1;
		unsigned heuristic = 0;
		bool isEnd = false;
		bool isStart = false;
		bool isObstacle = false;
		bool inClosedList = false;
		bool inOpenList = false;
		int x, y;

		std::shared_ptr<AStarNode> formerNode;

		AStarNode(int x, int y) : x(x), y(y)
		{}

		void calucalteHeuristic(int endPosX, int endPosY);

		unsigned getCompleteCosts();
	};

	class OpenListComperator
	{
	public:
		bool operator()(std::shared_ptr<AStarNode> lhs, std::shared_ptr<AStarNode> rhs)
		{
			return lhs->getCompleteCosts() > rhs->getCompleteCosts();
		}
	};

	std::priority_queue < std::shared_ptr<AStarNode>, std::vector<std::shared_ptr<AStarNode>>, OpenListComperator > openList;

	std::vector<std::vector<std::shared_ptr<AStarNode>>> nodes;


	void evaluate(std::shared_ptr<AStarNode> node);

	std::list<sf::Vector2f> waypoints;
};

