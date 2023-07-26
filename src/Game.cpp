#include "Game.h"

Game::Game()
{
	cursor = new Cursor();

	objs[0] = new Map({100, 100});
	objs[1] = new Towers(cursor);

	inGame = false;
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

	for (Object* obj : objs)
		obj->update();

	cursor->update();

	if (static_cast<Towers*>(objs[1])->won())
		inGame = false;
}

void Game::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (Object* obj : objs)
		obj->draw();

	cursor->draw();

	EndDrawing();
}