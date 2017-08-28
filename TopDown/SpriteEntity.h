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
	void setPosition(sf::Vector2f pos);
	bool isRenderable();

protected:
	void setWidthHeight(int width, int height);

	int getWidth();
	int getHeight();

	sf::Sprite sprite;
private:
	int renderPos;

};

