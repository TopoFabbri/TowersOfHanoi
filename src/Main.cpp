#include "Game.h"
#include "Tools.h"

void defaults();
void runProgram();

int main()
{
	runProgram();
}

void defaults()
{
	InitWindow(Tools::WIDTH, Tools::HEIGHT, "Hell's Hanoi - Topo");
	InitAudioDevice();
	SetTargetFPS(60);
}

void runProgram()
{
	defaults();
	Game* game = new Game();
	game->run();
	delete game;
}