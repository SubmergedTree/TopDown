#include <SFML/Graphics.hpp>

//#include "Framework.h"
/*
int main()
{
	Framework framework;
	framework.run();
}
*/

#define AMOUNTOFVERTICES 4

#include <iostream>
#include <string>
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(std::string texture,const int* tiles, int amountOfTiles,int tileSize ,int subtextureSize)
	{
		if (!m_tileset.loadFromFile(texture))
			return false;

		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(amountOfTiles * amountOfTiles * AMOUNTOFVERTICES);

		for (int i = 0; i < amountOfTiles ; ++i)
			for (unsigned int j = 0; j < amountOfTiles; ++j)
			{
				sf::Vertex* quad = &m_vertices[(i + j * amountOfTiles) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
				quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
				quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
				quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

				//quad->color = sf::Color::Blue;

				quad[0].texCoords = sf::Vector2f(0,0);
				quad[1].texCoords = sf::Vector2f(subtextureSize,0);
				quad[2].texCoords = sf::Vector2f(subtextureSize, subtextureSize);
				quad[3].texCoords = sf::Vector2f(0, subtextureSize);


			}
		return true;
	}


private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");

	// define the level with an array of tile indices
	const int level[] =
	{
		1,1,2,
		0,0,0,
		1,0,2
	};


	TileMap tileMap;
	bool c = tileMap.load("images/tileset.png", level, 3, 100,17);

	sf::View v;
	v.setCenter(0, 0);
	v.setSize(1000, 1000);

	//window.setView(v);
	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(tileMap);
		window.display();
	}

	return 0;
}