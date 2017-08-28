#include "SpriteEntity.h"


SpriteEntity::SpriteEntity()
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

void SpriteEntity::setPosition(sf::Vector2f pos)
{

}

bool SpriteEntity::isRenderable()
{
	return true;
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
