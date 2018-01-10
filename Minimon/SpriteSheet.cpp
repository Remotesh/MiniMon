#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(int w, int h, int r, int c, sf::Texture* text)
	:width(w),
	height(h),
	rows(r),
	cols(c),
	spriteSheet(text)
{
}

sf::Sprite SpriteSheet::getSprite(int r, int c)
{
	sf::Sprite returnSprite;
	if ((r <= rows && r >= 0) && (c <= cols && c >= 0))
	{
		returnSprite.setTexture(*spriteSheet);

		returnSprite.setTextureRect(sf::IntRect(r*width, c*cols, width, height));
	}

	return returnSprite;
}

void SpriteSheet::setupSpriteSheet(int w, int h, int r, int c, sf::Texture* text)
{
	spriteSheet = text;

	width = w;
	height = h;
	rows = r;
	cols = c;
}