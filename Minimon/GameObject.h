#pragma once

class World;

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "CommandComponent.h"

class GameObject
{
public:
	int				xCoord = 0, yCoord = 0, prevX, prevY;
	int				status = 0, weight = -1;

	GameObject(CommandComponent* commands,
		PhysicsComponent* physics,
		GraphicsComponent* graphics)
		: commandComponent(commands),
		physicsComponent(physics),
		graphicsComponent(graphics)
	{};

	void update(World& world, int command, sf::Time dt)
	{
		commandComponent->update(*this, world, command);
		physicsComponent->update(*this, world);
		graphicsComponent->update(*this, dt);
	};

	void update(World& world, int command)
	{
		commandComponent->update(*this, world, command);
		physicsComponent->update(*this, world);
	};

	sf::Sprite draw()
	{
		return *(graphicsComponent->draw());
	};

	void setCoords(int x, int y)
	{
		prevX = xCoord;
		xCoord = x;
		prevY = yCoord;
		yCoord = y;
	};


private:
	CommandComponent*			commandComponent	= NULL;
	GraphicsComponent*			graphicsComponent	= NULL;
	PhysicsComponent*			physicsComponent	= NULL;

};

struct GObjectPointer
{
	GameObject* object = NULL;
	int* xCoord = &(object->xCoord);
	int* yCoord = &(object->yCoord);
};

struct GObjectPointerArray
{
	GObjectPointer* gOPArray = NULL;
	int size = 0;

	void add(GObjectPointer gOPtr)
	{
		size++;
		GObjectPointer* newArray = new GObjectPointer[size];
		for (int i = 0; i < (size - 1); i++)
		{
			newArray[i] = gOPArray[i];
		}
		newArray[(size - 1)] = gOPtr;
		gOPArray = newArray;
	}
};