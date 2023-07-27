#include "Cursor.h"

Cursor::Cursor()
{
	clickWav = LoadSound("aud/Click.wav");
	rec = { 0, 0, 1.6f, 4 };
	rot = 0;
	tint = WHITE;
	HideCursor();
	sprite = LoadTexture("res/Cursor.png");

	click = false;
	hasDisk = false;
	grabbedDisc = NULL;
	movements = 0;
}

void Cursor::update()
{
	const Vector2 pos = Tools::toScreenDimensions(GetMousePosition());

	rec.x = pos.x;
	rec.y = pos.y;

	if (grabbedDisc)
		grabbedDisc->setPos(pos);

	click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	if (click)
		PlaySound(clickWav);
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
	movements++;

	return disc;
}

void Cursor::grabDisc(Disc* disc)
{
	hasDisk = true;
	grabbedDisc = disc;
	disc->grab();
}

int Cursor::getMovements()
{
	return movements;
}

void Cursor::resetMovements()
{
	movements = 0;
}

void Cursor::cancelMove(Disc* disc)
{
	movements--;
	grabDisc(disc);
}