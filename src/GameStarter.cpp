#include "GameStarter.h"

void GameStarter::defaults()
{
	InitWindow(Tools::WIDTH, Tools::HEIGHT, "Hell's Hanoi - Topo");
	InitAudioDevice();
	SetTargetFPS(60);
}

void GameStarter::runProgram()
{
	defaults();

	Game* game = new Game();
	game->run();
	delete game;
}