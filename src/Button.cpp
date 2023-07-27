#include "Button.h"

Button::Button()
{
	rec = { 0, 0, 10, 5 };
	normal = WHITE;
	hovered = GRAY;
	txtColor = BLACK;
	sprite = {};
	size = 60;
	txtSpacing = 1;
	text = "Button";
	indent = 10;
	font = GetFontDefault();
}

Button::Button(Vector2 pos, const char* newText)
{
	rec.x = pos.x;
	rec.y = pos.y;
	normal = WHITE;
	hovered = GRAY;
	txtColor = BLACK;
	sprite = {};
	size = 40;
	txtSpacing = 1;
	text = newText;
	indent = 10;
	font = GetFontDefault();

	rec.width = MeasureTextEx(font, text, size, 0).x + 2.f * indent;
	rec.height = MeasureTextEx(font, text, size, 0).y + 2.f * indent;
	rec.x -= rec.width / 2.f;
	rec.y -= rec.height / 2.f;
}

void Button::draw()
{
	const Rectangle source{ 0, 0, static_cast<float>(sprite.width), static_cast<float>(sprite.height) };

	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		const float rot = 10;

		DrawRectanglePro(rec, { 0, 0 }, rot, hovered);
		DrawTextPro
		(
			font, 
			text, 
			{ rec.x + indent,rec.y + indent },
			{ 0, 0 },
			rot,
			size, 
			txtSpacing, 
			txtColor
		);
	}
	else
	{
		DrawRectanglePro(rec, { 0, 0 }, 0, normal);
		DrawTextPro
		(
			font,
			text, 
			{ rec.x + indent,rec.y + indent },
			{ 0, 0 },
			0, 
			size, 
			txtSpacing, 
			txtColor
		);
	}

}

bool Button::isPressed()
{
	return (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
		CheckCollisionPointRec(GetMousePosition(), rec));
}

void Button::setTxt(const char* txt)
{
	text = txt;
}

void Button::setPos(Vector2 newPos)
{
	rec.x = newPos.x;
	rec.y = newPos.y;
}