#pragma once
#include "InputComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	virtual void update(GameObject& object)
	{
		/**switch (Controller::getJoystickDirection())
		{
		case DIR_LEFT:
			object.velocity -= WALK_ACCELERATION;
			break;

		case DIR_RIGHT:
			object.velocity += WALK_ACCELERATION;
			break;
		}**/
	}

private:
	static const int WALK_ACCELERATION = 1;
};