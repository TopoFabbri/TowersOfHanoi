#pragma once
#include <raylib.h>

#include "Tools.h"

class Text
{
private:
	const char* text;
	float size;
	float spacing;
	float rot;
	bool shadow;
	Vector2 pos;
	Font font;

	Color color;

public:
	Text(const char* newText, float newSize, Vector2 pos, Color, bool newShadow);
	~Text();

	void setText(const char* newText);
	void setPos(int x, int y);
	void setRot(float newRot);
	Vector2 measure();
	int textSize();
	void draw();
};