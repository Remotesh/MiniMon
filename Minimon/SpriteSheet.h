#pragma once

#include <SFML/Graphics.hpp>

class SpriteSheet
{
public:
	SpriteSheet(int w, int h, int r, int c, sf::Texture* text);

	sf::Sprite getSprite(int, int);

	void setupSpriteSheet(int w, int h, int r, int c, sf::Texture*);
	
	sf::Texture* spriteSheet;
	int width, height, rows, cols;

};