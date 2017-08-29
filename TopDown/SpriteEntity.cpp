#include "SpriteEntity.h"


SpriteEntity::SpriteEntity() : renderPos(0), isOnTileMap(false)
{
}


SpriteEntity::~SpriteEntity()
{
}

sf::Sprite * SpriteEntity::getSprite()
{
	return &sprite;
}

int SpriteEntity::getRenderPos()
{
	return renderPos;
}

void SpriteEntity::setTexture(const sf::Texture & texture)
{
	sprite.setTexture(texture);
}

void SpriteEntity::setRenderPos(int renderPos)
{
	this->renderPos = renderPos;
}
#include <iostream>
void SpriteEntity::setTiledPosition(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles)
{
	tiledPosition.x = xCoord;
	tiledPosition.y = yCoord;
	tiledPosition.width = widthAmountOfTiles;
	tiledPosition.height = heightAmountOfTiles;

	worldPosition = entityManager->fromTiledToWorldCoordinates(xCoord, yCoord, widthAmountOfTiles, heightAmountOfTiles);
	
	/*
	std::cout << "tiledPosition: " << "\n"
		<< "x: " << tiledPosition.x << "\n"
		<< "y: " << tiledPosition.y << "\n"
		<< "w: " << tiledPosition.width << "\n"
		<< "h: " << tiledPosition.height << "\n"
		<< "worldPosition: " << "\n"
		<< "x: " << worldPosition.x << "\n"
		<< "y: " << worldPosition.y << "\n"
		<< "w: " << worldPosition.width << "\n"
		<< "h: " << worldPosition.height << std::endl;
	*/
	
	sprite.setPosition(worldPosition.x, worldPosition.y);
	setWidthHeight(worldPosition.width, worldPosition.height);

	//std::cout << "dimensions from sprite" << getWidth() << " " << getHeight() << std::endl;
}



bool SpriteEntity::isRenderable()
{
	return true;
}

void SpriteEntity::setIsOnTileMap()
{
	isOnTileMap = true;
}

bool SpriteEntity::getIsOnTileMap()
{
	return isOnTileMap;
}
Coord & SpriteEntity::getTiledMapPosition()
{
	return tiledPosition;
}
void SpriteEntity::setWidthHeight(int width, int height)
{
	sprite.setScale(
		width / getSprite()->getLocalBounds().width,
		height / getSprite()->getLocalBounds().height);
}

int SpriteEntity::getWidth()
{
	return getSprite()->getGlobalBounds().width;
}

int SpriteEntity::getHeight()
{
	return getSprite()->getGlobalBounds().height;
}
