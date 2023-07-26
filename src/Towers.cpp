#include "Towers.h"

Towers::Towers(Cursor* cursor)
{
	towerSpace = 30.f;
	towerHeight = 50.f;
	towerWidth = 1.f;
	towerTop = 25.f;
	discSpace = 1.f;
	discHeight = 2.f;
	discQty = 5;

	float zoneSize = 10.f;

	for (int i = 0; i < TOWER_QTY; i++)
	{
		towerPoss[i] = 50.f - towerSpace + towerSpace * static_cast<float>(i);
		Rectangle zone = 
		{
			towerPoss[i] - zoneSize / 2.f - towerWidth / 2.f,
			towerTop,
			towerWidth + zoneSize,
			towerHeight
		};

		towers[i] = new Tower(i + 1, discSpace, discHeight, towerPoss[i], towerHeight, towerWidth, towerTop);
		zones[i] = new Zone(towers[i], zone, cursor);
	}

	for (int i = 0; i < Tower::MAX_DISCS; i++)
		discs[i] = new Disc(i, discHeight);

	for (int i = discQty - 1; i >= 0; i--)
		towers[0]->addDisc(discs[i]);
}

Towers::~Towers()
{
	for (Tower* tower : towers)
		delete tower;
}

void Towers::update()
{
	for (Tower* tower : towers)
		tower->update();

	for (Zone* zone : zones)
		zone->update();
}

void Towers::draw()
{
	for (Tower* tower : towers)
		tower->draw();

	for (int i = 0; i < discQty; i++)
		discs[i]->draw();
}

bool Towers::won()
{
	int discCount = 0;

	while (discs[discCount])
		discCount++;

	return discCount >= discQty;
}