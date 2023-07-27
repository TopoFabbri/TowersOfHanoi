#pragma once
#include <raylib.h>

class Text
{
public:
	const char* text;
	int size;
	int x;
	int y;

	Color color;

	Text(const char* newText, int newSize, Vector2 pos, Color color);
	~Text();

	void setPos(int x, int y);
	int measure();
	int textSize();
	void draw();
};

