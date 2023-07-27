#pragma once
#include "Object.h"

class Disc :
	public Object
{
private:
	Sound dropWav;
	Sound grabWav;
	Color selected;
	Color base;
	int number;
	bool grabbed;
	float selectedRot;

public:
	Disc(int newNumber, float height);

	void placeDisc(Vector2 pos);
	void setPos(Vector2 pos);
	void grab();
	int getNumber();
	void setSelected();
	void quitSelected();
};