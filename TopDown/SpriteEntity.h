#pragma once
#include "BaseEntity.h"

class SpriteEntity : public BaseEntityExp
{
public:
	SpriteEntity();
	virtual ~SpriteEntity();

	sf::Sprite* getSprite();
	int getRenderPos();
	void setTexture(const sf::Texture  & texture);

	void setRenderPos(int renderPos);
	void setTiledPosition(unsigned int xCoord, unsigned int yCoord, unsigned int widthAmountOfTiles, unsigned int heightAmountOfTiles);
	bool isRenderable();
	void setIsOnTileMap();
	bool getIsOnTileMap();
	sd
	Coord& getTiledMapPosition();
protected:
	void setWidthHeight(int width, int height);

	int getWidth();
	int getHeight();

	sf::Sprite sprite;

	Coord worldPosition;
	Coord tiledPosition;

private:
	int renderPos;
	bool isOnTileMap;
};

