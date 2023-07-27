#pragma once

#include <raylib.h>
#include "Object.h"

class Button :
	public Object
{
private:
	Color normal;
	Color hovered;
	Color txtColor;
	float size;
	float txtSpacing;
	const char* text;
	float indent;
	Font font;

public:
	Button();
	Button(Vector2 pos, const char* newText);
	
	void draw() override;

	bool isPressed();
	void setTxt(const char* txt);
	void setPos(Vector2 newPos);
};