#include "BaseEntity.h"



BaseEntity::BaseEntity(const sf::Texture  & texture, sf::Vector2f &size) : sprite(texture), tag("")
{
	sprite.scale(size);
}


BaseEntity::~BaseEntity()
{
}

sf::Vector2f BaseEntity::getPosition()
{
	return sprite.getPosition();
}

void BaseEntity::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void BaseEntity::setRenderPos(int rPos)
{
	renderPos = rPos;
}

sf::Sprite BaseEntity::getSprite()
{
	return sprite;
}

int BaseEntity::getRenderPos()
{
	return renderPos;
}

std::string BaseEntity::getTag()
{
	return tag;
}

