#pragma once

class GameObject;
class World;

class CommandComponent {
public:
	virtual ~CommandComponent() {};
	virtual void update(GameObject& object, World& world, int command) = 0;
	virtual CommandComponent* clone() const = 0;
};