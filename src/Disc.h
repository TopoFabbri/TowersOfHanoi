#pragma once
#include "Object.h"

class Disc :
	public Object
{
private:
	Sound dropWav;
	Sound grabWav;
	Color selected;
	int number;
	bool grabbed;

public:
	Disc(int newNumber, float height);

	void placeDisc(Vector2 pos);
	void setPos(Vector2 pos);
	void grab();
	int getNumber();
};