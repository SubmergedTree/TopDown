#include "TiledMap.h"
#include <iostream>


TiledMap::TiledMap(int sizeOfTile, int amountOfTiles) : sizeOfTile(sizeOfTile), amountOfTiles(amountOfTiles)
{
	tiledMap.resize(amountOfTiles);
/*	for (auto it : tiledMap)
	{
		it.resize(amountOfTiles);
	}*/
	
	for (int i = 0; i < amountOfTiles; i++)
	{
		tiledMap[i].resize(amountOfTiles);
		for (int j = 0; j < amountOfTiles; j++)
		{
			tiledMap[i][j] = 0;
		}
	}

	keyGenNumber = 1;
}


TiledMap::~TiledMap()
{
}

void TiledMap::insert(std::string key,unsigned int xCoord, unsigned int yCoord,unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles)
{
	if (xCoord + widthAmountOfTiles > amountOfTiles && yCoord + heightAmountOfTiles > amountOfTiles)
	{
		std::cout << "bad Coordinates or Dimension on TiledMap::insert" << std::endl;
		return;
	}

	int insertKey;
	auto itkeyMap = keyMap.find(key);
	if (itkeyMap == keyMap.end())
	{
		insertKey = keyGenNumber;
		keyMap.insert(std::pair<std::string,int>(key,keyGenNumber));
		keyGenNumber++;
	}
	else
	{
		insertKey = itkeyMap->second;
	}

	
	for (int i = 0; i < widthAmountOfTiles; i++)
	{
		int insertX = i + xCoord;

		for (int j = 0; j < heightAmountOfTiles; j++)
		{
			int insertY = j + yCoord;
			tiledMap[insertX][insertY] = insertKey;
		}
	}
}

void TiledMap::insert(std::string key,Coord & coord)
{
	insert(key, coord.x, coord.y, coord.width, coord.height);
}

void TiledMap::deletefromTiledMap(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles)
{
	if (xCoord + widthAmountOfTiles > amountOfTiles && yCoord + heightAmountOfTiles > amountOfTiles)
	{
		std::cout << "bad Coordinates or Dimension on TiledMap::deletefromTiledMap" << std::endl;
		return;
	}

	for (int i = 0; i < widthAmountOfTiles; i++)
	{
		int insertX = i + xCoord;

		for (int j = 0; j < heightAmountOfTiles; j++)
		{
			int insertY = j + yCoord;
			tiledMap[insertX][insertY] = 0;
		}
	}
}

Direction TiledMap::collisionDirection(int xCoord, int yCoord)
{
	return Direction();
}

bool TiledMap::collisionInFieldBool(unsigned int xCoord, unsigned int yCoord)
{
	return (tiledMap[xCoord][yCoord] != 0) ? true : false;
}

bool TiledMap::collisionAroundBool(int xCoord, int yCoord)
{
	return false;
}

std::string TiledMap::collisionWith(int xCoord, int yCoord)
{
	return std::string();
}

Coord TiledMap::getRealCoordinates(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles)
{
	if (xCoord + widthAmountOfTiles > amountOfTiles && yCoord + heightAmountOfTiles > amountOfTiles)
	{
		std::cout << "bad Coordinates or Dimension on TiledMap::getRealCoordinates" << std::endl;
		//return;
	}

	Coord c;
	c.x = sizeOfTile * xCoord;
	c.y = sizeOfTile * yCoord;
	c.width = widthAmountOfTiles * sizeOfTile;
	c.height = heightAmountOfTiles * sizeOfTile;
	return c;
}
