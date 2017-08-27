#include "TextureManager.h"
#include <iostream>



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::loadTexture(const std::string & fileName, const std::string & key)
{
	sf::Texture * texture = new sf::Texture();
	texture->loadFromFile(fileName);
	textures.insert(std::pair<std::string, sf::Texture *>(key, texture));
}

sf::Texture * TextureManager::getTexture(std::string key)
{
	auto it = textures.find(key);
	if (it != textures.end())
	{
		return it->second;
	}
	std::cout << "Texture not found" << std::endl;
	return nullptr;
}
