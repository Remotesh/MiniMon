#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "ResourceHolder.h"
#include "World.h"
#include "ConfigLoader.h"

class Game
{
public:
	Game();
	void	run();

private:
	void	processEvents();
	void	update(sf::Time);
	void	render();

	void	updateStatistics(sf::Time elapsedTime);

	void	handleInput(sf::Keyboard::Key, bool);

private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow	mWindow;

	World				mWorld;

	ResourceHolder<sf::Texture, Textures::ID>		textures;

	CommandQueue		commands;

	ConfigLoader		config;

	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;

	std::size_t		mStatisticsNumFrames;

	// Eventually remove this as this should identify player
	int clientEntId = 0;
};