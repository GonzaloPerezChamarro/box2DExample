
#include "Game.hpp"


using namespace example;

int main()
{
	Game * game = new Game("Box2D Example", 1280, 720);
	game->start();

	return 0;
}