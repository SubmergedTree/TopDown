#pragma once
#include <map>
#include "SFML\Graphics.hpp"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	void loadTexture(const std::string &fileName,const std::string &key);
	sf::Texture * getTexture(std::string key);
private:
	std::map<std::string, sf::Texture *> textures;
};

