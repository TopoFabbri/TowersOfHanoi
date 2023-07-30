#include "PauseScreen.h"

PauseScreen::PauseScreen(Stats* newStats)
{
	active = false;
	rec = { 30, 10, 40, 80 };
	tint = WHITE;
	sprite = LoadTexture("res/Popup.png");

	stats = newStats;
	title = new Text("Menu", 50, Tools::toConsoleDimensions(Vector2{ 50, 35 }), WHITE);

	resumeBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 55 }), "Resume");
	quitBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 65 }), "Quit");
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

	if (quitBtn->isPressed())
	{
		active = false;
		return true;
	}

	return false;
}