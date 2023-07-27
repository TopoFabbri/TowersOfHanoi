#pragma once

#include <raylib.h>
#include "Object.h"

class Button :
	public Object
{
private:
	Sound hoverWav;
	Color normal;
	Color hovered;
	Color txtColor;
	float size;
	float txtSpacing;
	const char* text;
	float indent;
	Font font;
	bool isHovered;

	void startHovered();
	void endHovered();

public:
	Button();
	Button(Vector2 pos, const char* newText);
	
	void update() override;
	void draw() override;

	bool isPressed();
	void setTxt(const char* txt);
	void setPos(Vector2 newPos);
};