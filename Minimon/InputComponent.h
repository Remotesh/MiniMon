#pragma once

class GameObject;

class InputComponent
{
public:
	virtual ~InputComponent() {}
	virtual void update(GameObject& object) = 0;
};