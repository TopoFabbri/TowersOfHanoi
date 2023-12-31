#pragma once
#include "Object.h"
#include "Disc.h"

class Cursor :
    public Object
{
private:
	Sound clickWav;
	Disc* grabbedDisc;
	bool hasDisk;
	bool click;
	int movements;

public:
	Cursor();

	void update() override;
	void draw() override;

	bool getClick();
	bool getHasDisk();
	Vector2 getPos();
	Disc* dropDisc();
	void grabDisc(Disc* disc);
	int getMovements();
	void reset();
	void cancelMove(Disc* disc);
};