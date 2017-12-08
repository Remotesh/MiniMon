#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	// 64pixels 10 by 7.5 
	TextureHolder	mTextures;

	mTextures.load(Textures::Grid, "./media/textures/grid.png");

	sf::Sprite grid;

	sf::Texture& texture = mTextures.get(Textures::Grid);

	grid.setTexture(texture);

	sf::View mWorldView = sf::View(window.getDefaultView());

	sf::Vector2f movement = sf::Vector2f(0.f,0.f);

	sf::CircleShape shape;
	shape.setRadius(20.f);
	shape.setPosition(320.f, 240.f);
	shape.setFillColor(sf::Color::Cyan);

	int shapex = 5;
	int shapey = 5;

	sf::CircleShape secshape;
	secshape.setRadius(20.f);
	secshape.setPosition(100.f, 100.f);
	secshape.setFillColor(sf::Color::Red);

	enum objectid {
		Tile,
		Player,
		Object,
		ObjectIdCount
	};

	int world[10][8];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			world[i][j] = 0;
		}
	}

	world[shapex][shapey] = objectid::Player;

	world[7][1] = objectid::Object;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				movement.x = -1.f;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				movement.x = 1.f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				movement.y = -1.f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				movement.y = 1.f;
			}

			//mWorldView.move(movement);
			world[shapex][shapey] = 0;
			if (shapex < 10 && shapey < 8)
			{
				shapex += movement.x;
				shapey += movement.y;
			}
			else
			{
				shapex -= movement.x;
				shapey -= movement.y;
			}
			world[shapex][shapey] = objectid::Player;

			movement = sf::Vector2f(0.f, 0.f);
		}
		//window.setView(mWorldView);
		window.clear();
		window.setView(window.getDefaultView());
		
		//Apply the grid to view
		for (int i = 0; i < 10; i++)
		{
			int x = i;
			for (int j = 0; j < 8; j++)
			{
				int y = j;

				if (world[i][j] != 0)
				{
					switch (world[i][j]) {
					case objectid::Player:
						shape.setPosition(x * 64, y * 64);
						window.draw(shape);
						break;
					case objectid::Object:
						secshape.setPosition(x * 64, y * 64);
						window.draw(secshape);
						break;
					}

				}


				grid.setPosition(x*64, y*64);
				window.draw(grid);
			}
		}
		window.display();
	}
	return 1;
}