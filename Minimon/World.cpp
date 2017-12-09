#include "World.h"

World::World(sf::RenderWindow& window)
	:mWindow(window)
	, mWorldView(window.getDefaultView())
	, mWorldBounds(
		0.f,
		0.f,
		mWorldView.getSize().x,
		2000.f)
	, mSpawnPosition(
		mWorldView.getSize().x / 2.f,
		mWorldBounds.height - mWorldView.getSize().y),
	tileSize(64)
{
	mWorldView.setCenter(mSpawnPosition);
}


void World::draw()
{
	// Worldview To be centered on player
	mWindow.setView(mWorldView);


	//mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{
	/*
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	
	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if (position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(dt);
	*/
}

void World::resolveCollision()
{

}