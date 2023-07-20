#include "Towers.h"

Towers::Towers()
{
	towerSpace = 30.f;
	towerHeight = 50.f;
	towerWidth = 1.f;
	towerTop = 25.f;
	discSpace = 1.f;
	discHeight = 2.f;
	discQty = 5;

	for (int i = 0; i < TOWER_QTY; i++)
	{
		towerPoss[i] = 50.f - towerSpace + towerSpace * static_cast<float>(i);
		towers[i] = new Tower(discQty, i + 1, towerPoss[i], towerHeight, towerWidth, towerTop);
	}

	for (int i = 0; i < MAX_DISCS; i++)
		discs[i] = new Disc(i, discHeight);

	for (int i = discQty - 1; i >= 0; i--)
		moveDisc(i, 0);
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
}

void Towers::draw()
{
	for (Tower* tower : towers)
		tower->draw();

	for (int i = 0; i < discQty; i++)
		discs[i]->draw();
}

void Towers::moveDisc(int discIndex, int toTower)
{
	float posX = towerPoss[toTower];
	float height = towerTop + towerHeight;

	height -= (discHeight + discSpace) * static_cast<float>(towers[toTower]->discs);

	discs[discIndex]->setPos({ posX, height });

	towers[toTower]->discs++;
}