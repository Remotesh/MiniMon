#pragma once

#include "GameObject.h"
#include "AnimationContainer.h"

class ActiveCommandComponent : public CommandComponent 
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

	ActiveCommandComponent* ActiveCommandComponent::clone() const
	{
		return new ActiveCommandComponent(*this);
	}
};

class ActivePhysicsComponent : public PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world);
	
	ActivePhysicsComponent* ActivePhysicsComponent::clone() const
	{
		return new ActivePhysicsComponent(*this);
	}

};

class ActiveGraphicsComponent : public GraphicsComponent 
{
public:
	ActiveGraphicsComponent(sf::Texture* text)
	{
		objTexture = text;
		objSprite.setTexture(*objTexture);
		objSprite.setTextureRect(objRect);
	};
	
	void update(GameObject& object, sf::Time dt)
	{
		animElapsed += dt.asMilliseconds();
		switch (object.status)
		{
		case 0:
			objAnimations.update(&objRect, &animElapsed);
			break;
		case 1:
			objAnimations.changeAnimation(DefaultAnimations::Up);
			objAnimations.update(&objRect, &animElapsed);
			break;
		case 2:
			objAnimations.changeAnimation(DefaultAnimations::Left);
			objAnimations.update(&objRect, &animElapsed);
			break;
		case 3:
			objAnimations.changeAnimation(DefaultAnimations::Down);
			objAnimations.update(&objRect, &animElapsed);
			break;
		case 4:
			objAnimations.changeAnimation(DefaultAnimations::Right);
			objAnimations.update(&objRect, &animElapsed);
			break;
		default:
			objAnimations.update(&objRect, &animElapsed);
			break;
		}

		objSprite.setTextureRect(objRect);
	};

	sf::Sprite* draw()
	{
		return &(objSprite);
	};

	ActiveGraphicsComponent* ActiveGraphicsComponent::clone() const
	{
		return new ActiveGraphicsComponent(*this);
	}


private:
	int spriteWidth = 64, spriteHeight = 64, numSpriteRows = 4, numSpriteCols = 4;
	
	sf::Texture*			objTexture		= NULL;
	SpriteSheet				objSpriteSheet	= SpriteSheet(spriteWidth, spriteHeight, numSpriteRows, numSpriteCols, objTexture);
	AnimationContainer		objAnimations	= AnimationContainer(&objSpriteSheet);
	sf::Sprite				objSprite;
	sf::IntRect				objRect			= sf::IntRect(0,0,spriteWidth, spriteHeight);
	int						animElapsed		= 0;
};

