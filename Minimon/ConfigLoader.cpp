#include "ConfigLoader.h"

const std::unordered_map<std::string, keyCommandActions> ConfigLoader::keyCommandActionsMap = {
	{ "moveUp", keyCommandActions::moveUp },
	{ "moveLeft", keyCommandActions::moveLeft },
	{ "moveDown", keyCommandActions::moveDown },
	{ "moveRight", keyCommandActions::moveRight },
	{ "inventory", keyCommandActions::inventory },
	{ "pause", keyCommandActions::pause },
	{ "actionOne", keyCommandActions::actionOne },
	{ "actionTwo", keyCommandActions::actionTwo },
	{ "actionThree", keyCommandActions::actionThree },
	{ "actionFour", keyCommandActions::actionFour },
	{ "actionFive", keyCommandActions::actionFive },
	{ "modOne", keyCommandActions::modOne },
	{ "modTwo", keyCommandActions::modTwo },
	{ "modThree", keyCommandActions::modThree }
};

ConfigLoader::ConfigLoader()
{
	// Initialize All Bindings
	keyBindings.insert(std::make_pair(sf::Keyboard::Unknown, keyCommandActions::unknown));
	keyBindings.insert(std::make_pair(sf::Keyboard::A, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::B, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::C, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::D, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::E, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::G, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::H, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::I, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::J, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::K, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::L, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::M, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::N, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::O, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::P, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Q, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::R, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::S, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::T, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::U, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::V, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::W, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::X, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Y, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Z, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num0, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Escape, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LControl, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LShift, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LAlt, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LSystem, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RControl, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RShift, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RAlt, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RSystem, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Menu, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LBracket, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RBracket, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::SemiColon, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Comma, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Period, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Quote, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Slash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::BackSlash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Tilde, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Equal, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Dash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Space, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Return, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::BackSpace, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Tab, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::PageUp, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::PageDown, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::End, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Home, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Insert, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Delete, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Add, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Subtract, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Multiply, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Divide, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Left, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Right, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Up, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Down, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad0, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F10, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F11, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F12, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F13, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F14, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Pause, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	genericBindings();
}

ConfigLoader::ConfigLoader(char* file)
{
	// Initialize All Bindings
	keyBindings.insert(std::make_pair(sf::Keyboard::Unknown, keyCommandActions::unknown));
	keyBindings.insert(std::make_pair(sf::Keyboard::A, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::B, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::C, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::D, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::E, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::G, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::H, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::I, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::J, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::K, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::L, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::M, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::N, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::O, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::P, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Q, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::R, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::S, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::T, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::U, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::V, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::W, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::X, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Y, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Z, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num0, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Num9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Escape, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LControl, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LShift, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LAlt, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LSystem, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RControl, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RShift, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RAlt, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RSystem, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Menu, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::LBracket, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::RBracket, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::SemiColon, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Comma, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Period, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Quote, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Slash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::BackSlash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Tilde, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Equal, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Dash, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Space, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Return, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::BackSpace, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Tab, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::PageUp, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::PageDown, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::End, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Home, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Insert, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Delete, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Add, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Subtract, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Multiply, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Divide, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Left, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Right, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Up, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Down, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad0, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Numpad9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F2, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F3, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F4, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F5, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F6, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F7, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F8, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F9, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F10, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F11, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F12, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F13, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F14, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::Pause, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	keyBindings.insert(std::make_pair(sf::Keyboard::F1, -1));
	loadFile(file);
}

void ConfigLoader::genericBindings()
{
	keyBindings[sf::Keyboard::W] = keyCommandActions::moveUp;
	keyBindings[sf::Keyboard::A] = keyCommandActions::moveLeft;
	keyBindings[sf::Keyboard::S] = keyCommandActions::moveDown;
	keyBindings[sf::Keyboard::D] = keyCommandActions::moveRight;
	keyBindings[sf::Keyboard::I] = keyCommandActions::inventory;
	keyBindings[sf::Keyboard::Escape] = keyCommandActions::pause;
	keyBindings[sf::Keyboard::Num1] = keyCommandActions::actionOne;
	keyBindings[sf::Keyboard::Num2] = keyCommandActions::actionTwo;
	keyBindings[sf::Keyboard::Num3] = keyCommandActions::actionThree;
	keyBindings[sf::Keyboard::Num4] = keyCommandActions::actionFour;
	keyBindings[sf::Keyboard::Num5] = keyCommandActions::actionFive;
	keyBindings[sf::Keyboard::LShift] = keyCommandActions::modOne;
	keyBindings[sf::Keyboard::LControl] = keyCommandActions::modTwo;
	keyBindings[sf::Keyboard::LAlt] = keyCommandActions::modThree;
}

void ConfigLoader::loadFile(char* file)
{
	std::string line;
	fileName = file;
	std::ifstream configFile(file);
	if (configFile.is_open())
	{
		while (std::getline(configFile, line))
		{
			int key = -1;
			std::string config = "";
			config = line.substr(0, line.find(" "));
			//std::cout << config << std::endl;
			key = std::stoi(line.substr(line.find(" ")));
			//std::cout << key << std::endl;

			const auto it = keyCommandActionsMap.find(config);
			if (it != keyCommandActionsMap.end()) {
				rebind(key, it->second);
			}
		}
	}
	else
	{
		genericBindings();
		std::cout << "Issue opening config file" << std::endl;
	}
}

void ConfigLoader::rebind(int key, int command)
{
	keyBindings[key] = command;
}

int ConfigLoader::processInput(sf::Keyboard::Key keyPressed, bool pressed)
{
	int command = -1;

	if (pressed == true)
	{
		command = keyBindings[keyPressed];
	}

	return command;
}