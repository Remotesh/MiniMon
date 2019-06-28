#pragma once

class World;

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "CommandComponent.h"
#include <iostream>

class GameObject
{
public:
	int				xCoord = 0, yCoord = 0, prevX, prevY;
	int				status = 0, weight = -1;
	int				objectId = -1;

	GameObject(CommandComponent* commands,
		PhysicsComponent* physics,
		GraphicsComponent* graphics,
		int id = -1,
		int x = 0,
		int y = 0,
		int w = -1)
		: commandComponent(commands),
		physicsComponent(physics),
		graphicsComponent(graphics),
		objectId(id),
		xCoord(x),
		yCoord(y),
		weight(w)

	{};

	GameObject(const GameObject& that) : 
		xCoord(that.xCoord),
		yCoord(that.yCoord),
		prevX(that.prevX),
		prevY(that.prevY),
		status(that.status),
		weight(that.weight),
		objectId(that.objectId),
		commandComponent(that.commandComponent->clone()),
		physicsComponent(that.physicsComponent->clone()),
		graphicsComponent(that.graphicsComponent->clone())
	{
		std::cout << "GObject Copy Constructor called " << objectId << std::endl;
		std::cout << commandComponent << " " << that.commandComponent << std::endl;
		std::cout << physicsComponent << " " << that.physicsComponent << std::endl;
		std::cout << graphicsComponent << " " << that.graphicsComponent << std::endl;
	}

	GameObject& operator=(const GameObject& that)
	{
		std::cout << "GObject Assignment Operator called " << objectId << std::endl;
		if (this != &that)
		{
			xCoord = that.xCoord;
			yCoord = that.yCoord;
			prevX = that.prevX;
			prevY = that.prevY;
			status = that.status;
			weight = that.weight;
			objectId = that.objectId;

			if (that.commandComponent != nullptr)
			{
				CommandComponent* c2 = that.commandComponent->clone();
				delete commandComponent;
				commandComponent = c2;
			}
			if (that.physicsComponent != nullptr)
			{
				PhysicsComponent* p2 = that.physicsComponent->clone();
				delete physicsComponent;
				physicsComponent = p2;
			}
			if (that.graphicsComponent != nullptr)
			{
				GraphicsComponent* p2 = that.graphicsComponent->clone();
				delete graphicsComponent;
				graphicsComponent = p2;
			}
		}
		return *this;
	}

	~GameObject()
	{
		std::cout << "GObject Destructor called " << objectId << std::endl;
		
		if (commandComponent != nullptr)
		{
			delete commandComponent;
		}
		if (physicsComponent != nullptr)
		{
			delete physicsComponent;
		}
		if (graphicsComponent != nullptr)
		{
			delete graphicsComponent;
		}	
	};

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

	sf::Sprite* draw()
	{
		return graphicsComponent->draw();
	};

	void setCoords(int x, int y)
	{
		prevX = xCoord;
		xCoord = x;
		prevY = yCoord;
		yCoord = y;
	};

	void setId(int newId)
	{
		objectId = newId;
	};


private:
	CommandComponent*			commandComponent	= nullptr;
	GraphicsComponent*			graphicsComponent	= nullptr;
	PhysicsComponent*			physicsComponent	= nullptr;

};

struct GObjectPointer
{
	GameObject* object = nullptr;
	int* xCoord = &(object->xCoord);
	int* yCoord = &(object->yCoord);
};

struct GObjectPointerArray
{
	GObjectPointer* gOPArray = nullptr;
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
		delete[] gOPArray;
		gOPArray = newArray;
	}
};