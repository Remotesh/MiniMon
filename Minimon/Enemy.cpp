#include "Enemy.h"
#include "World.h"

void EnemyPhysicsComponent::update(GameObject& object, World& world)
{
	switch (object.status)
	{
	case 0:
		break;
	case 1:
		// Check to see if object or wall exists above if so have the world resolve collisions
		object.setCoords(object.xCoord, (object.yCoord - 1));
		world.resolveCollision(&object);
		break;
	case 2:
		// Check to see if object or wall exists to the left if so have the world resolve collisions
		object.setCoords((object.xCoord - 1), object.yCoord);
		world.resolveCollision(&object);
		break;
	case 3:
		// Check to see if object or wall exists below if so have the world resolve collisions
		object.setCoords(object.xCoord, (object.yCoord + 1));
		world.resolveCollision(&object);
		break;
	case 4:
		// Check to see if object or wall exists to the right if so have the world resolve collisions
		object.setCoords((object.xCoord + 1), object.yCoord);
		world.resolveCollision(&object);
		break;
	default:
		break;
	}
}