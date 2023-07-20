#include "Tower.h"

Tower::Tower(int discQty, int newNumber, float posX, float height, float width, float top)
{
	number = newNumber;

	discs = 0;

	rec = { posX - width / 2.f, top, width, height };
}

Tower::~Tower()
{
}

void Tower::draw()
{
	Object::draw();
}