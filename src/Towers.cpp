#include "Towers.h"

Towers::Towers()
{
	towerSpace = 30.f;
	towerHeight = 50.f;
	towerWidth = 1.f;
	towerBase = 25.f;
	discQty = 5;

	for (int i = 0; i < TOWER_QTY; i++)
		towers[i] = new Tower(discQty, i + 1, 50.f - towerSpace + towerSpace * i, towerHeight, towerWidth, towerBase);
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
}