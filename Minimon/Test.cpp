#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "DungeonLevel.h"

void testFunctionality()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	TextureHolder	mTextures;

	mTextures.load(Textures::Grid, "./media/textures/grid.png");
	mTextures.load(Textures::PlayerCharacter, "./media/textures/goodguy.png");
	mTextures.load(Textures::Enemy, "./media/textures/badguy.png");
	mTextures.load(Textures::Tiles, "./media/textures/tiles.png");

	int tileWidth = 64;

	// Woodlands Sprites
	sf::Sprite* woodlands = new sf::Sprite[10];
	for (int i = 0; i < 10; i++)
		woodlands[i].setTexture(mTextures.get(Textures::Tiles));

	woodlands[0].setTextureRect(sf::IntRect(0, 0, 64, 64));
	woodlands[1].setTextureRect(sf::IntRect(63, 0, 64, 64));
	woodlands[2].setTextureRect(sf::IntRect(127, 0, 64, 64));
	woodlands[3].setTextureRect(sf::IntRect(0, 63, 64, 64));
	woodlands[4].setTextureRect(sf::IntRect(63, 63, 64, 64)); // Base Tile
	woodlands[5].setTextureRect(sf::IntRect(127, 63, 64, 64));
	woodlands[6].setTextureRect(sf::IntRect(0, 127, 64, 64));
	woodlands[7].setTextureRect(sf::IntRect(63, 127, 64, 64));
	woodlands[8].setTextureRect(sf::IntRect(127, 127, 64, 64));
	woodlands[9].setTextureRect(sf::IntRect(191, 191, 64, 64)); // Base Wall


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

	sf::View centerPlayer = sf::View(window.getDefaultView());

	sf::Vector2f movement = sf::Vector2f(0.f, 0.f);


	sf::Sprite goodguy;
	goodguy.setTexture(mTextures.get(Textures::PlayerCharacter));

	sf::Sprite badguy;
	badguy.setTexture(mTextures.get(Textures::Enemy));

	int shapex = 4;
	int shapey = 4;

	enum objectid {
		Player = 100,
		Object,
		ObjectIdCount
	};

	DungeonLevel currentLevel = DungeonLevel(20, 30, Dungeons::Woodlands, Dungeons::Square);

	int** world = currentLevel.getLayout();

	for (int i = 0; i < currentLevel.getWidth(); i++)
	{
		for (int j = 0; j < currentLevel.getHeight(); j++)
		{
			std::cout << world[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Width: " << currentLevel.getWidth() << " Height " << currentLevel.getHeight() << std::endl;

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

			if (shapex < currentLevel.getWidth() && shapey < currentLevel.getHeight())
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

			centerPlayer.setCenter(goodguy.getPosition().x, goodguy.getPosition().y);

			movement = sf::Vector2f(0.f, 0.f);
		}
		window.setView(centerPlayer);
		window.clear();

		//Apply the grid to view
		for (int i = 0; i < currentLevel.getWidth(); i++)
		{
			int x = i;
			for (int j = 0; j < currentLevel.getHeight(); j++)
			{
				int y = j;
				if (world[i][j] != -1)
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
						/*
						topright	= 14;
						topmid		= 13;
						topleft		= 12;
						leftmid		= 11;
						bottomleft	= 10;
						bottommid	= 9;
						bottomright	= 8;
						rightmid	= 7;
						*/
					case 0:
						woodlands[4].setPosition(x * 64, y * 64);
						window.draw(woodlands[4]);
						break;
					case 15:
						woodlands[9].setPosition(x * 64, y * 64);
						window.draw(woodlands[9]);
						break;

					case 14:
						woodlands[2].setPosition(x * 64, y * 64);
						window.draw(woodlands[2]);
						break;
					case 13:
						woodlands[1].setPosition(x * 64, y * 64);
						window.draw(woodlands[1]);
						break;
					case 12:
						woodlands[0].setPosition(x * 64, y * 64);
						window.draw(woodlands[0]);
						break;
					case 11:
						woodlands[3].setPosition(x * 64, y * 64);
						window.draw(woodlands[3]);
						break;
					case 10:
						woodlands[6].setPosition(x * 64, y * 64);
						window.draw(woodlands[6]);
						break;
					case 9:
						woodlands[7].setPosition(x * 64, y * 64);
						window.draw(woodlands[7]);
						break;
					case 8:
						woodlands[8].setPosition(x * 64, y * 64);
						window.draw(woodlands[8]);
						break;
					case 7:
						woodlands[5].setPosition(x * 64, y * 64);
						window.draw(woodlands[5]);
						break;
					}
				}


				grid.setPosition(x * 64, y * 64);
				window.draw(grid);
			}
		}

		window.setView(window.getDefaultView());

		statsText = "X: " + std::to_string(shapex + 1) + " Y:" + std::to_string(shapey + 1);
		stats.setString(statsText);
		window.draw(stats);

		window.display();
	}
}