#pragma once
#include "World.h"

class GameObject;

class PhysicsComponent
{
public:
	virtual ~PhysicsComponent() {}
	virtual void update(GameObject& object, World& world) = 0;
};