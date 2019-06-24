#pragma once

#include "GameObject.h"
#include "AnimationContainer.h"

class PlayerCommandComponent : public CommandComponent 
{
public:
	virtual void update(GameObject& object, World& world, int command)
	{
		/* Status Breakdown
			0 Not moving - for animation pausing / reset
			1 Moving up
			2 Moving left
			3 Moving down
			4 Moving right
		*/
		object.status = command;
	};
};

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world);
};

class PlayerGraphicsComponent : public GraphicsComponent 
{
public:
	PlayerGraphicsComponent(sf::Texture* text)
	{
		playerTexture = text;
		playerSprite.setTexture(*playerTexture);
		playerSprite.setTextureRect(playerRect);
	};
	void update(GameObject& object, sf::Time dt)
	{
		animElapsed += dt.asMilliseconds();
		switch (object.status)
		{
		case 0:
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		case 1:
			playerAnimations.changeAnimation(DefaultAnimations::Up);
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		case 2:
			playerAnimations.changeAnimation(DefaultAnimations::Left);
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		case 3:
			playerAnimations.changeAnimation(DefaultAnimations::Down);
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		case 4:
			playerAnimations.changeAnimation(DefaultAnimations::Right);
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		default:
			playerAnimations.update(&playerRect, &animElapsed);
			break;
		}

		playerSprite.setTextureRect(playerRect);
	};

	sf::Sprite* draw()
	{
		return &(playerSprite);
	};


private:
	int spriteWidth = 64, spriteHeight = 64, numSpriteRows = 4, numSpriteCols = 4;
	
	sf::Texture*			playerTexture		= NULL;
	SpriteSheet				playerSpriteSheet	= SpriteSheet(spriteWidth, spriteHeight, numSpriteRows, numSpriteCols, playerTexture);
	AnimationContainer		playerAnimations	= AnimationContainer(&playerSpriteSheet);
	sf::Sprite				playerSprite;
	sf::IntRect				playerRect			= sf::IntRect(0,0,spriteWidth, spriteHeight);
	int						animElapsed			= 0;
};

