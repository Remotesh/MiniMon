#pragma once

class World;

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "CommandComponent.h"


class GameObject
{
public:
	int				xCoord = 0, yCoord = 0;
	sf::Vector2i	velocity;

	GameObject(CommandComponent* commands,
		PhysicsComponent* physics,
		GraphicsComponent* graphics)
		: commandComponent(commands),
		physicsComponent(physics),
		graphicsComponent(graphics)
	{}

	void update(World& world, int command) 
	{
		commandComponent->update(*this, command);
		physicsComponent->update(*this, world);
		graphicsComponent->update(*this);
	}

	void setCoords(int x, int y)
	{
		xCoord = x;
		yCoord = y;
	};

private:
	CommandComponent*				commandComponent;
	GraphicsComponent*			graphicsComponent;
	PhysicsComponent*			physicsComponent;

};