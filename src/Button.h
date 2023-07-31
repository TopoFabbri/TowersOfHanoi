#pragma once

#include <raylib.h>
#include "Object.h"
#include "Text.h"

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
	Text* text;
	float indent;
	Font font;
	bool isHovered;

	void startHovered();
	void endHovered();

public:
	Button();
	Button(Vector2 pos, const char* newText);
	Button(Vector2 pos, const char* newText, const char* path);
	~Button() override;
	
	void update() override;
	void draw() override;

	bool isPressed();
	void setTxt(const char* txt);
	void setPos(Vector2 newPos);
};
