#pragma once

class GameObject;

class CommandComponent {
public:
	virtual ~CommandComponent() {};
	virtual void update(GameObject& object, int command) = 0;
};