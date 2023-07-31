#include "Menu.h"

Menu::Menu()
{
	title = new Text("MENU", 50, Tools::toConsoleDimensions(Vector2{ 50, 20 }), YELLOW, true);
	rec = { 0, 0, 100, 100 };
	sprite = LoadTexture("res/BG2.png");

	playBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 50 }), "PLAY");
	credsBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 65 }), "CREDITS");
	quitBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 80 }), "QUIT");
}

Menu::~Menu()
{
	delete quitBtn;
	delete credsBtn;
	delete playBtn;
	delete title;
}

int Menu::updateMenu()
{
	playBtn->update();
	credsBtn->update();
	quitBtn->update();

	if (quitBtn->isPressed())
		return 0;

	if (playBtn->isPressed())
		return 1;

	if (credsBtn->isPressed())
		return 2;

	return 3;
}

void Menu::draw()
{
	Object::draw();

	title->draw();
	playBtn->draw();
	credsBtn->draw();
	quitBtn->draw();
}