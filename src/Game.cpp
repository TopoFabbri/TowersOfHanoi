#include "Game.h"

Game::Game()
{
	cursor = new Cursor();

	map = new Map({ 100, 100 });
	towers = new Towers(cursor);
	menu = new Menu();
	stats = new Stats();
	winScreen = new WinScreen(stats);
	resetBtn = new Button(Tools::toConsoleDimensions(Vector2{ 90, 5 }), "R");
	menuBtn = new Button(Tools::toConsoleDimensions(Vector2{ 95, 5 }), ". . .");
	credits = new Credits();

	state = State::Menu;
}

Game::~Game()
{
	delete menuBtn;
	delete resetBtn;
	delete winScreen;
	delete stats;
	delete credits;
	delete menu;
	delete towers;
	delete map;
	delete cursor;
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

		case State::Credits: 
			state = static_cast<State>(credits->getScene());
			break;

		case State::Menu: 
			state = static_cast<State>(menu->updateMenu());

			if (state == State::Game)
				reset();

			break;

		case State::WinScreen:
			winScreen->update();
			if (winScreen->getFinished())
				state = State::Menu;
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

	stats->update();
	stats->setMoves(cursor->getMovements());

	if (resetBtn->isPressed())
		reset();

	if (menuBtn->isPressed())
		state = State::Menu;

	if (towers->won())
		state = State::WinScreen;

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
			resetBtn->draw();
			menuBtn->draw();

			std::string moves = "Movements: " + std::to_string(stats->getMoves());
			std::string time = "Time: " + std::to_string(stats->getTime());

			Text movesTxt = Text(moves.c_str(), 20, Tools::toConsoleDimensions(Vector2{ 50, 2 }), WHITE);
			Text timeTxt = Text(time.c_str(), 20, Tools::toConsoleDimensions(Vector2{ 10, 2 }), WHITE);

			movesTxt.draw();
			timeTxt.draw();
			
			break;
		}

	case State::Credits:
		credits->draw();
		break;

	case State::Menu:
		menu->draw();
		break;

	case State::WinScreen: 
		winScreen->draw();
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
	stats->resetStats();
	winScreen->restartFinished();
}