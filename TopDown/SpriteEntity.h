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
	bool isRenderable();
	void setPosition(int x, int y);

	void setWidthHeight(int width, int height);

	void move(sf::Vector2f distance);
	void move(int distanceX, int distanceY);
	void moveWaypoints(std::list<sf::Vector2f> & waypoints, float deltaTime, float speed);

	sf::Vector2f getPosition();

protected:

	int getWidth();
	int getHeight();

	sf::Sprite sprite;

	Coord worldPosition;
private:
	int renderPos;
};

