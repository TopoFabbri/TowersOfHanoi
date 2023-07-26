#pragma once
#include "Object.h"
#include "Disc.h"

class Cursor :
    public Object
{
private:
	bool hasDisk;
	Disc* grabbedDisc;
	bool click;

public:
	Cursor();

	void update() override;

	bool getClick();
	bool getHasDisk();
	Vector2 getPos();
	Disc* dropDisc();
	void grabDisc(Disc* disc);
};
