#include "Framework.h"
#include "player.h"
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

#include "TextureManager.h"


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
	textureManager.loadTexture("images/dragonAnim.png", "dragon");
	textureManager.loadTexture("images/bild.jpg", "stone");
	EntityManager entityManager(*window);
	std::shared_ptr<Player> p1(std::make_shared<Player>(*textureManager.getTexture("dragon"), sf::Vector2f(3, 3),&entityManager));
	p1->setRenderPos(2);
	std::shared_ptr<Obstacle> p2(std::make_shared<Obstacle>(*textureManager.getTexture("stone"), sf::Vector2f(1, 1), &entityManager));
	p2->setRenderPos(1);

	p2->setPosition(sf::Vector2f(100, 100));

	entityManager.insertEntity(p1);
	entityManager.insertEntity(p2);

	float oldTime = 0;
	float newTime = 0;
	float deltaTime;
	sf::Clock clock;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		oldTime = newTime;
		newTime = clock.getElapsedTime().asMilliseconds();
		deltaTime = newTime - oldTime;
		//std::cout << newTime << std::endl;
		window->clear();
		entityManager.update(deltaTime);
		entityManager.render();
		window->display();
	}
}

void Framework::initializeWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default);
}