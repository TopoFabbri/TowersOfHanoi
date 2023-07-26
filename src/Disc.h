#pragma once
#include "Object.h"

class Disc :
	public Object
{
private:
	int number;
	bool grabbed;

public:
	Disc(int newNumber, float height);

	void setPos(Vector2 pos);
	void grab();
};