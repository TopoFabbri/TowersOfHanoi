#include "Disc.h"

Disc::Disc(int newNumber, float height)
{
	number = newNumber;
	grabbed = false;

	rec = { 0, 0, 2.f + static_cast<float>(number) * 2.5f, height };
}

void Disc::setPos(Vector2 pos)
{
	rec.x = pos.x - rec.width / 2.f;
	rec.y = pos.y - rec.height / 2.f;
}

void Disc::grab()
{
	grabbed = true;
}

int Disc::getNumber()
{
	return number;
}