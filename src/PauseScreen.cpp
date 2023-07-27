#include "PauseScreen.h"

PauseScreen::PauseScreen(Stats* newStats)
{
	active = false;
	rec = { 40, 20, 20, 60 };
	tint = RED;

	stats = newStats;
	title = new Text("Menu", 50, Tools::toConsoleDimensions(Vector2{ 50, 30 }), BLACK);

	resumeBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 50 }), "Resume");
	quitBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 60 }), "Quit");
	startPauseTime = 0;
}

PauseScreen::~PauseScreen()
{
	delete title;
	delete resumeBtn;
	delete quitBtn;
}

void PauseScreen::draw()
{
	if (!active)
		return;

	Object::draw();

	title->draw();
	resumeBtn->draw();
	quitBtn->draw();
}

void PauseScreen::pause()
{
	active = true;

	startPauseTime = static_cast<int>(GetTime());
}

bool PauseScreen::hasQuit()
{
	resumeBtn->update();
	quitBtn->update();

	if (resumeBtn->isPressed())
	{
		active = false;
		stats->addPausedTime(static_cast<int>(GetTime()) - startPauseTime);
	}

	return quitBtn->isPressed();
}