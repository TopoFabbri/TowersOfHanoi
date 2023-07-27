#include "WinScreen.h"

WinScreen::WinScreen(Stats* newStats)
{
	stats = newStats;

	moves = "Moves: ";
	time = "Time: ";
	finished = false;

	rec = { 40, 40, 20, 20 };
}

WinScreen::~WinScreen()
{
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

	const std::string movesTmpTxt = moves + std::to_string(stats->getMoves());
	const std::string timeTmpTxt = time + std::to_string(stats->getTime());

	Text movesTxt = Text(
		movesTmpTxt.c_str(),
		20,
		Tools::toConsoleDimensions(Vector2{50, 45}),
		BLACK);


	Text timeTxt = Text(
		timeTmpTxt.c_str(),
		20,
		Tools::toConsoleDimensions(Vector2{50, 55}),
		BLACK);

	movesTxt.draw();
	timeTxt.draw();
}

bool WinScreen::getFinished()
{
	return finished;
}

void WinScreen::restartFinished()
{
	finished = false;
}