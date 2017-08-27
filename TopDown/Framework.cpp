#include "Framework.h"
#include "player.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>



Framework::Framework()
{
	initializeWindow();
}


Framework::~Framework()
{
	delete window;
	window = nullptr;
}

void Framework::run()
{
	TextureManager textureManager;
	textureManager.loadTexture("images/image.png", "dragon");
	textureManager.loadTexture("images/stone.png", "stone");

	std::shared_ptr<Player> p1(std::make_shared<Player>(*textureManager.getTexture("dragon"), sf::Vector2f(0.3, 0.3)));
	p1->setRenderPos(2);
	std::shared_ptr<Player> p2(std::make_shared<Player>(*textureManager.getTexture("stone"), sf::Vector2f(0.3, 0.3)));
	p2->setRenderPos(1);

	EntityManager entityManager(*window);
	entityManager.insertEntity(p1);
	entityManager.insertEntity(p2);

	sf::Clock clock;
	sf::Time start = clock.getElapsedTime();
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		float deltaTime = clock.getElapsedTime().asMilliseconds() - start.asMilliseconds();
		entityManager.update(deltaTime);
		entityManager.render();
		window->display();
	}
}

void Framework::initializeWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default);
}