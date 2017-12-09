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
	mTextures.load(Textures::PlayerCharacter, "./media/textures/goodguy.png");
	mTextures.load(Textures::Enemy, "./media/textures/badguy.png");

	sf::Font font;
	font.loadFromFile("./media/fonts/arial.ttf");

	sf::Text stats;
	stats.setFont(font);
	stats.setCharacterSize(30);
	stats.setPosition(50, 50);
	stats.setFillColor(sf::Color::White);

	std::string statsText;

	sf::Sprite grid;

	sf::Texture& texture = mTextures.get(Textures::Grid);

	grid.setTexture(texture);

	sf::View mWorldView = sf::View(window.getDefaultView());

	sf::Vector2f movement = sf::Vector2f(0.f,0.f);


	sf::Sprite goodguy;
	goodguy.setTexture(mTextures.get(Textures::PlayerCharacter));

	sf::Sprite badguy;
	badguy.setTexture(mTextures.get(Textures::Enemy));

	int shapex = 4;
	int shapey = 4;

	enum objectid {
		Tile,
		Player,
		Object,
		ObjectIdCount
	};

	int world[20][16];

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

			world[shapex][shapey] = 0;

			if (shapex < 20 && shapey < 16)
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

			mWorldView.move(movement.x * 64, movement.y * 64);

			movement = sf::Vector2f(0.f, 0.f);
		}
		window.setView(mWorldView);
		window.clear();
		
		//Apply the grid to view
		for (int i = 0; i < 20; i++)
		{
			int x = i;
			for (int j = 0; j < 16; j++)
			{
				int y = j;

				if (world[i][j] != 0)
				{
					switch (world[i][j]) {
					case objectid::Player:
						goodguy.setPosition(x * 64, y * 64);
						window.draw(goodguy);
						break;
					case objectid::Object:
						badguy.setPosition(x * 64, y * 64);
						window.draw(badguy);
						break;
					}

				}


				grid.setPosition(x*64, y*64);
				window.draw(grid);
			}
		}

		window.setView(window.getDefaultView());

		statsText = "X: " + std::to_string(shapex) + " Y:" + std::to_string(shapey);
		stats.setString(statsText);
		window.draw(stats);

		window.display();
	}
	return 1;
}