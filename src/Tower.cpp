#include "Tower.h"

Tower::Tower(int discQty, int newNumber, float posX, float height, float width, float base)
{
	number = newNumber;

	discs = newNumber == 1 ? discQty : 0;

	rec = { posX - width / 2.f, height, width, base };
}

Tower::~Tower()
{
}

void Tower::draw()
{
	Object::draw();
}