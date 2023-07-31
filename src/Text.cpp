#include "Text.h"

Text::Text(const char* newText, float newSize, Vector2 newPos, Color color, bool newShadow)
{
	font = LoadFont("fon/CreepyFont.ttf");
	text = newText;
	size = newSize;
	spacing = 0;
	rot = 0;
	shadow = newShadow;
	pos = newPos;
	this->color = color;
}

Text::~Text()
{
}

void Text::setText(const char* newText)
{
	text = newText;
}

void Text::setPos(int newX, int newY)
{
	pos.x = static_cast<float>(newX);
	pos.y = static_cast<float>(newY);
}

void Text::setRot(float newRot)
{
	rot = newRot;
}

Vector2 Text::measure()
{
	return MeasureTextEx(font, text, size, spacing);
}

int Text::textSize()
{
	return MeasureText(text, static_cast<int>(size));
}

void Text::draw()
{
	Vector2 tmpPos = pos;

	if (shadow)
	{
		tmpPos.x -= measure().x / 2.f;
		tmpPos.y -= measure().y / 2.f;
		tmpPos.x += 3.f;
		tmpPos.y += 3.f;

		DrawTextPro
		(
			font,
			text,
			tmpPos,
			{ 0, 0 },
			rot,
			size,
			spacing,
			BLACK
		);

		tmpPos = pos;
	}

	tmpPos.x -= measure().x / 2.f;
	tmpPos.y -= measure().y / 2.f;

	DrawTextPro
	(
		font,
		text,
		tmpPos,
		{ 0, 0 },
		rot,
		size,
		spacing,
		color
	);
}