#pragma once
#include <vector>
#include <map>
#include <string>

#include "Orientation.h"

class TiledMap
{
public:
	TiledMap(int sizeOfTile, int amountOfTiles);
	~TiledMap();

	void insert(std::string key, unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles);
	void insert(std::string key,Coord& coord);

	void deletefromTiledMap(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles);

	Direction collisionDirection(int xCoord, int yCoord);
	bool collisionInFieldBool(unsigned int xCoord,unsigned int yCoord);
	bool collisionAroundBool(int xCoord, int yCoord);
	std::string collisionWith(int xCoord,int yCoord);

	Coord getRealCoordinates(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles);

private:
	 const int sizeOfTile;
	 const int amountOfTiles;
	 std::vector<std::vector<unsigned int>> tiledMap;
	 std::map<std::string, int> keyMap;
	 int keyGenNumber;
};

