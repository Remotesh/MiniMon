#pragma once

class World;

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"

class GameObject
{
public:
	int				xCoord, yCoord;
	sf::Vector2i	velocity;

	GameObject(InputComponent* input,
		PhysicsComponent* physics,
		GraphicsComponent* graphics)
		: inputComponent(input),
		physicsComponent(physics),
		graphicsComponent(graphics)
	{}

	void update(World& world) {
		inputComponent->update(*this);
		physicsComponent->update(*this, world);
		graphicsComponent->update(*this);
	}

private:
	InputComponent*				inputComponent;
	GraphicsComponent*			graphicsComponent;
	PhysicsComponent*			physicsComponent;

};