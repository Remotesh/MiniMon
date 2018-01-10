#pragma once

#include "SpriteSheet.h"

class Animation
{
public:
	Animation()
	{
		animationFrames = 0;
	};

	Animation(int frames)
	{
		animationFrames = frames;
	};

	Animation(int frames, int delay)
	{
		animationFrames = frames;
		animationDelay = delay;
	};

	Animation(int frames, int delay, int w, int h, int r)
	{
		animationFrames = frames;
		animationDelay	= delay;

		setupAnimation(w, h, r);
	};

	void setupAnimation(int w, int h, int r)
	{
		sf::IntRect* newAnimation = new sf::IntRect[animationFrames];
		for (int i = 0; i < animationFrames; i++)
		{
			sf::IntRect rect((r * h), (i * w), w, h);
			newAnimation[i] = rect;
		}
		animation = newAnimation;
	};

	void setAnimationFrames(int frames)
	{
		animationFrames = frames;
	}

	void setDelay(int delay)
	{
		animationDelay = delay;
	}

	void resetAnimation()
	{
		curAnimationFrame = 0;
	}

	void update(sf::IntRect* rect, int* dt)
	{
		if ((*dt) > animationDelay)
		{
			if (curAnimationFrame == (animationFrames - 1))
				resetAnimation();
			else
			{
				curAnimationFrame++;
				*dt = 0;
			}
		}

		*rect = animation[curAnimationFrame];
	};

	/** Debug remove later
	void update(sf::IntRect* rect, int dt)
	{
		if (dt >= animationDelay)
		{
			if (curAnimationFrame == (animationFrames - 1))
				resetAnimation();
			else
				curAnimationFrame++;
		}

		rect = &(animation[curAnimationFrame]);
	};
	**/

	// Debug Remove Later
	int getFrame()
	{
		return curAnimationFrame;
	};

	sf::IntRect getFrameRect()
	{
		return animation[curAnimationFrame];
	};


private:
	int animationFrames		= 0;
	int curAnimationFrame	= 0;
	// Delay in milliseconds
	int animationDelay		= 100;
	sf::IntRect* animation;
};


class AnimationContainer
{
public:
	AnimationContainer(SpriteSheet* sheet)
	{
		animationSpriteSheet = sheet;
		setupAnimations();
	};

	void setupAnimations()
	{
		numAnimations = (*animationSpriteSheet).rows;

		if ((*animationSpriteSheet).rows > 0 && (*animationSpriteSheet).cols > 0)
		{
			Animation* newAnimations = new Animation[(*animationSpriteSheet).rows];

			for (int i = 0; i < (*animationSpriteSheet).rows; i++)
			{
				newAnimations[i].setAnimationFrames((*animationSpriteSheet).cols);
				newAnimations[i].setupAnimation((*animationSpriteSheet).width, (*animationSpriteSheet).height, i);
			}

			animations = newAnimations;
		}
		
	};

	void update(sf::IntRect* rect, int* dt)
	{
		animations[currentAnimation].update(rect, dt);
	};

	/** Debug Remove Later

	void update(sf::IntRect* rect, int dt)
	{
		animations[currentAnimation].update(rect, dt);
	};
	**/

	// Debug remove Later
	int getAnimationFrame()
	{
		return animations[currentAnimation].getFrame();
	}
	sf::IntRect getFrameRect()
	{
		return animations[currentAnimation].getFrameRect();
	}

	void changeAnimation(int animNum)
	{
		if (animNum != currentAnimation)
		{
			if (animNum >= 0 && animNum < numAnimations)
				currentAnimation = animNum;
		}
	};
	

private:
	SpriteSheet* animationSpriteSheet;
	Animation* animations;
	int currentAnimation = 0, numAnimations = 0;
	
};