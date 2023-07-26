#include "Tower.h"

Tower::Tower(int newNumber, float newDiscSpace, float newDiscHeight, float posX, float height, float width, float top)
{
	number = newNumber;
	discSpace = newDiscSpace;
	discHeight = newDiscHeight;

	this->discQty = 0;

	for (int i = 0; i < MAX_DISCS; i++)
		discs[i] = NULL;

	rec = { posX - width / 2.f, top, width, height };
}

Tower::~Tower()
{
}

int Tower::getDiscQty()
{
	return discQty;
}

bool Tower::addDisc(Disc* disc)
{
	int i = 0;

	while (i < MAX_DISCS && discs[i])
		i++;

	if (i > 0)
	{
		if (discs[i - 1]->getNumber() <= disc->getNumber())
			return false;
	}

	discs[i] = disc;

	float posX = rec.x;
	float height = rec.y + rec.height;

	posX += rec.width / 2.f;
	height -= (discHeight + discSpace) * static_cast<float>(discQty);

	disc->setPos({ posX, height });

	discQty++;

	return true;
}

Disc* Tower::takeDisk()
{
	int i = 0;

	while (i < MAX_DISCS && discs[i])
		i++;

	if (i > 0)
	{
		Disc* disc = discs[i - 1];

		discs[i - 1] = NULL;
		discQty--;

		disc->grab();

		return disc;
	}

	return NULL;
}