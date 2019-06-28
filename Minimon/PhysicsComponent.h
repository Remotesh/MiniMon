#pragma once

class World;

class GameObject;

class PhysicsComponent
{
public:
	virtual ~PhysicsComponent() {}
	virtual void update(GameObject& object, World& world) = 0;
	virtual PhysicsComponent* clone() const = 0;
};