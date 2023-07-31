#include "Game.h"

Game::Game()
{
	cursor = new Cursor();

	map = new Map({ 100, 100 });
	towers = new Towers(cursor);
	menu = new Menu();
	stats = new Stats();
	winScreen = new WinScreen(stats);
	pauseScreen = new PauseScreen(stats);
	resetBtn = new Button(Tools::toConsoleDimensions(Vector2{ 88, 5 }), "    ", "res/RestartBtn.png");
	menuBtn = new Button(Tools::toConsoleDimensions(Vector2{ 95, 5 }), "    ", "res/PauseBtn.png");
	credits = new Credits();
	movesTxt = new Text("Movements: ", 40, Tools::toConsoleDimensions(Vector2{ 50, 2 }), WHITE, true);
	timeTxt = new Text("Time: ", 40, Tools::toConsoleDimensions(Vector2{ 10, 2 }), WHITE, true);

	state = State::Menu;
}

Game::~Game()
{
	delete timeTxt;
	delete movesTxt;
	delete credits;
	delete menuBtn;
	delete resetBtn;
	delete pauseScreen;
	delete winScreen;
	delete stats;
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
	if (pauseScreen->getActive())
	{
		if (pauseScreen->hasQuit())
			state = State::Menu;
		return;
	}

	towers->update();

	resetBtn->update();
	menuBtn->update();

	stats->update();
	stats->setMoves(cursor->getMovements());

	if (resetBtn->isPressed())
		reset();

	if (menuBtn->isPressed())
		pauseScreen->pause();

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

			if (pauseScreen->getActive())
			{
				pauseScreen->draw();
				break;
			}

			resetBtn->draw();
			menuBtn->draw();

			std::string moves = "Movements: " + std::to_string(stats->getMoves());
			std::string time = "Time: " + std::to_string(stats->getTime());

			movesTxt->setText(moves.c_str());
			timeTxt->setText(time.c_str());

			movesTxt->draw();
			timeTxt->draw();
			
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
	
	cursor->reset();
	stats->resetStats();
	winScreen->restartFinished();
}