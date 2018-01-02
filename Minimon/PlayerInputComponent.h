#pragma once
#include "InputComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	virtual void update(GameObject& object)
	{

	}

private:
	static const int WALK_ACCELERATION = 1;
};