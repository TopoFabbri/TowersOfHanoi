#include "Menu.h"

Menu::Menu()
{
	playBtn = new Button(Tools::toConsoleDimensions(Vector2{50, 20}), "PLAY");
	credsBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 40 }), "CREDITS");
	quitBtn = new Button(Tools::toConsoleDimensions(Vector2{ 50, 80 }), "QUIT");
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
	playBtn->draw();
	credsBtn->draw();
	quitBtn->draw();
}