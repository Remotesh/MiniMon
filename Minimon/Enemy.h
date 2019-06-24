#pragma once

#include "GameObject.h"
#include "AnimationContainer.h"

enum EnemyBehavior {
	Peaceful,
	Sleeping,
	Alert,
	Defensive,
	Aggressive
};

class EnemyCommandComponent : public CommandComponent
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

		switch (enemyBehavior)
		{
		case EnemyBehavior::Peaceful :
			break;
		case EnemyBehavior::Sleeping :
			break;
		case EnemyBehavior::Alert :
			break;
		case EnemyBehavior::Defensive :
			break;
		case EnemyBehavior::Aggressive:
			break;
		}
	};

	void changeBehavior(EnemyBehavior behavior)
	{
		enemyBehavior = behavior;
	}

private:
	int enemyBehavior	= EnemyBehavior::Peaceful;
	int enemyTicks		= 0;
};

class EnemyPhysicsComponent : public PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world);
};


class EnemyGraphicsComponent : public GraphicsComponent
{
public:
	EnemyGraphicsComponent(sf::Texture* text)
	{
		enemyTexture = text;
		enemySprite.setTexture(*enemyTexture);
		enemySprite.setTextureRect(enemyRect);
	};
	void update(GameObject& object, sf::Time dt)
	{
		animElapsed += dt.asMilliseconds();
		switch (object.status)
		{
		case 0:
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		case 1:
			enemyAnimations.changeAnimation(DefaultAnimations::Up);
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		case 2:
			enemyAnimations.changeAnimation(DefaultAnimations::Left);
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		case 3:
			enemyAnimations.changeAnimation(DefaultAnimations::Down);
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		case 4:
			enemyAnimations.changeAnimation(DefaultAnimations::Right);
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		default:
			enemyAnimations.update(&enemyRect, &animElapsed);
			break;
		}

		enemySprite.setTextureRect(enemyRect);
	};

	sf::Sprite* draw()
	{
		return &(enemySprite);
	};


private:
	int spriteWidth = 64, spriteHeight = 64, numSpriteRows = 4, numSpriteCols = 4;

	sf::Texture*			enemyTexture		= NULL;
	SpriteSheet				enemySpriteSheet	= SpriteSheet(spriteWidth, spriteHeight, numSpriteRows, numSpriteCols, enemyTexture);
	AnimationContainer		enemyAnimations		= AnimationContainer(&enemySpriteSheet);
	sf::Sprite				enemySprite;
	sf::IntRect				enemyRect			= sf::IntRect(0, 0, spriteWidth, spriteHeight);
	int						animElapsed			= 0;
};
