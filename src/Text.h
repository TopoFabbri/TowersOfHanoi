#pragma once
#include <raylib.h>

#include "Tools.h"

class Text
{
public:
	const char* text;
	float size;
	float spacing;
	Vector2 pos;
	Font font;

	Color color;

	Text(const char* newText, float newSize, Vector2 pos, Color color);
	~Text();

	void setText(const char* newText);
	void setPos(int x, int y);
	Vector2 measure();
	int textSize();
	void draw();
};