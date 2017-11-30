#include <iostream>

#include "Game.hpp"

int main(int argc, char* argv[])
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "/EXCEPTION: " << e.what() << "\n";
	}
	return 0;
}