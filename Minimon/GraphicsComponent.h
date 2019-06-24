#pragma once

#include "SFML\Graphics.hpp"

class GameObject;

enum DefaultAnimations {
	Up,
	Left,
	Down,
	Right,
	Idle
};

class GraphicsComponent 
{
public:
	virtual ~GraphicsComponent() {}
	virtual void update(GameObject& object, sf::Time dt) = 0;
	virtual sf::Sprite* draw() { return &empty; };

private:
	sf::Sprite empty;
};