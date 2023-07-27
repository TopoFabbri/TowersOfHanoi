#pragma once
#include "Object.h"
#include "Disc.h"

class Tower :
	public Object
{
public:
	static const int MAX_DISCS = 9;

	Tower(int newNumber, float discSpace, float discHeight, float posX, float height, float width, float top);
	~Tower() override;

	int getDiscQty();

	bool addDisc(Disc* disc);
	Disc* takeDisk();
	Disc* lastDisc();

private:
	int number;
	int discQty;
	float discSpace;
	float discHeight;
	Disc* discs[MAX_DISCS];
};