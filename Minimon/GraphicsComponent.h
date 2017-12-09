#pragma once

class GameObject;

class GraphicsComponent 
{
public:
	virtual ~GraphicsComponent() {}
	virtual void update(GameObject& object) = 0;
};