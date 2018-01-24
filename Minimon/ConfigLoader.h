#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>

enum keyCommandActions {
					// Typical Keys to the Right
	unknown = 0,
	moveUp,			// W
	moveLeft,		// A
	moveDown,		// S
	moveRight,		// D
	actionOne,		// 1
	actionTwo,		// 2
	actionThree,	// 3
	actionFour,		// 4
	actionFive,		// 5
	modOne,			// Shift
	modTwo,			// Cntrl
	modThree,		// Alt
	inventory,		// i
	pause,			// esc
	numActions
};

class ConfigLoader {
public:
	ConfigLoader();

	ConfigLoader(char* file);

	void genericBindings();

	void loadFile(char* file);

	void rebind(int key, int command);

	int processInput(sf::Keyboard::Key, bool);


private:
	char*				fileName = NULL;
	std::map<int, int>	keyBindings;
	const static std::unordered_map<std::string, keyCommandActions> keyCommandActionsMap;
	
};