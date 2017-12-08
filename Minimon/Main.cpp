#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");

	sf::View mWorldView = sf::View(window.getDefaultView());

	sf::Vector2f movement = sf::Vector2f(0.f,0.f);

	sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(320.f, 240.f);
	shape.setFillColor(sf::Color::Cyan);

	sf::CircleShape secshape;
	secshape.setRadius(40.f);
	secshape.setPosition(100.f, 100.f);
	secshape.setFillColor(sf::Color::Red);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				movement.x = 1.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				movement.x = -1.f;
			}

			mWorldView.move(movement);

			movement = sf::Vector2f(0.f, 0.f);
		}
		window.setView(mWorldView);
		window.clear();
		window.draw(shape);
		window.setView(window.getDefaultView());
		window.draw(secshape);
		window.display();
	}
	return 1;
}