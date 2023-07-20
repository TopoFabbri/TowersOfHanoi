#include "Game.h"

Game::Game()
{
	input = 0;
	objs[0] = new Map({100, 100});
	objs[1] = new Towers();
}

Game::~Game()
{
	for (Object* obj : objs)
		delete obj;
}

void Game::run()
{
	start();

	while (active)
	{
		update();
		draw();
	}
}

void Game::start()
{
}

void Game::update()
{
	if (WindowShouldClose())
		active = false;

	takeInput();
}

void Game::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (Object* obj : objs)
		obj->draw();

	EndDrawing();
}

void Game::takeInput()
{
	if (_kbhit())
		input = _getch();
}