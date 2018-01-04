
#include "Game.h"
#include "CommandQueue.h"

int main(int argc, char* argv[])
{
	Game game;

	game.run();

	std::cout << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 0;

}
