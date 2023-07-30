#include "WinScreen.h"

WinScreen::WinScreen(Stats* newStats)
{
	stats = newStats;
	finished = false;

	movesTxt = new Text(
		"Moves: ",
		35,
		Tools::toConsoleDimensions(Vector2{ 50, 45 }),
		WHITE);


	timeTxt = new Text(
		"Time: ",
		35,
		Tools::toConsoleDimensions(Vector2{ 50, 55 }),
		WHITE);
	rec = { 40, 35, 20, 30 };
}

WinScreen::~WinScreen()
{
	delete movesTxt;
	delete timeTxt;
}

void WinScreen::update()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		finished = true;
}

void WinScreen::draw()
{
	if (!active)
		return;

	Object::draw();

	const std::string moves = "Moves: " + std::to_string(stats->getMoves());
	const std::string time = "Time: " + std::to_string(stats->getTime());

	movesTxt->setText(moves.c_str());
	timeTxt->setText(time.c_str());

	movesTxt->draw();
	timeTxt->draw();
}

bool WinScreen::getFinished()
{
	return finished;
}

void WinScreen::restartFinished()
{
	finished = false;
}