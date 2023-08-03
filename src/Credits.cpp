#include "Credits.h"

Credits::Credits()
{
	rec = { 0, 0, 100, 100 };
	sprite = LoadTexture("res/BG2.png");

	title = new Text("CREDITS", 50, Tools::toConsoleDimensions(Vector2{ 50, 20 }), YELLOW, true);
	dev = new Text("Development by: Mateo Fabbri", 30, Tools::toConsoleDimensions(Vector2{ 50, 45 }), WHITE, true);
	art = new Text("Art by: Mariano Tanides", 30, Tools::toConsoleDimensions(Vector2{ 50, 60 }), WHITE, true);
	sound = new Text("Sound by: Mateo Fabbri", 30, Tools::toConsoleDimensions(Vector2{ 50, 75 }), WHITE, true);

	rec2 = { 0, 0, 100, 100 };
	image = LoadTexture("res/Credits.png");
}

Credits::~Credits()
{
	delete sound;
	delete art;
	delete dev;
	delete title;
}

void Credits::draw()
{
	Object::draw();

	Rectangle source{ 0, 0, static_cast<float>(image.width), static_cast<float>(image.height) };

	DrawTexturePro(image, source, Tools::toConsoleDimensions(rec2), { 0, 0 }, 0, WHITE);

	title->draw();
	dev->draw();
	art->draw();
	sound->draw();
}

int Credits::getScene()
{
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		return 3;

	return 2;
}