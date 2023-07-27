#include "Game.h"

Game::Game()
{
	cursor = new Cursor();

	map = new Map({ 100, 100 });
	towers = new Towers(cursor);
	menu = new Menu();

	state = State::Menu;
	movements = 0;
	startTime = 0;
}

Game::~Game()
{
	delete cursor;
	delete map;
	delete towers;
}

void Game::run()
{
	start();

	while (active)
	{
		cursor->update();

		switch (state)
		{
		case State::Quit: 
			active = false;
			break;

		case State::Game:
			update();
			break;

		case State::Credits: break;

		case State::Menu: 
			state = static_cast<State>(menu->updateMenu());

			if (state == State::Game)
				reset();

			break;

		default:;
		}

		if (WindowShouldClose())
			active = false;

		draw();
	}
}

void Game::start()
{
}

void Game::update()
{
	towers->update();

	movements = cursor->getMovements();

	if (towers->won())
		state = State::Menu;

	cursor->update();
}

void Game::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	map->draw();

	switch (state)
	{
	case State::Quit: break;

	case State::Game:
		{
			towers->draw();

			std::string moves = "Movements: " + std::to_string(movements);
			std::string time = "Time: " + std::to_string(static_cast<int>(GetTime()) - startTime);

			Text movesTxt = Text(moves.c_str(), 20, Tools::toConsoleDimensions(Vector2{ 50, 2 }), WHITE);
			Text timeTxt = Text(time.c_str(), 20, Tools::toConsoleDimensions(Vector2{ 10, 2 }), WHITE);

			movesTxt.draw();
			timeTxt.draw();
			break;
		}

	case State::Credits: break;

	case State::Menu:
		menu->draw();
		break;

	default:;
	}

	cursor->draw();

	EndDrawing();
}

void Game::reset()
{
	delete towers;
	
	towers = new Towers(cursor);
	
	cursor->resetMovements();
	startTime = static_cast<int>(GetTime());
}