#include "Game.h"

const int width = 1920;
const int height = 1080;

void defaults();
void runProgram();

int main()
{
	runProgram();
}

void defaults()
{
	InitWindow(width, height, "TowersOfHanoi");
}

void runProgram()
{
	defaults();
	Game* game = new Game();
	game->run();
	delete game;
}