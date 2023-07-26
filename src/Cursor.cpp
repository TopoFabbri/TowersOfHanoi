#include "Cursor.h"

Cursor::Cursor()
{
	rec = { 0, 0, 1.6f, 4 };
	rot = 0;
	tint = WHITE;
	HideCursor();
	sprite = LoadTexture("res/Cursor.png");

	click = false;
	hasDisk = false;
	grabbedDisc = NULL;
}

void Cursor::update()
{
	const Vector2 pos = Tools::toScreenDimensions(GetMousePosition());

	rec.x = pos.x;
	rec.y = pos.y;

	if (grabbedDisc)
		grabbedDisc->setPos(pos);

	click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool Cursor::getClick()
{
	return click;
}

bool Cursor::getHasDisk()
{
	return hasDisk;
}

Vector2 Cursor::getPos()
{
	return { rec.x, rec.y };
}

Disc* Cursor::dropDisc()
{
	Disc* disc = grabbedDisc;

	grabbedDisc = NULL;
	hasDisk = false;

	return disc;
}

void Cursor::grabDisc(Disc* disc)
{
	hasDisk = true;
	grabbedDisc = disc;
}