#include "Button.h"

void Button::startHovered()
{
	isHovered = true;
	PlaySound(hoverWav);
	rot = 0;
	text->setRot(rot);
}

void Button::endHovered()
{
	isHovered = false;
	rot = 0;
	text->setRot(rot);
}

Button::Button()
{
	sprite = LoadTexture("res/Button.png");

	rec = { 0, 0, 10, 5 };
	hoverWav = LoadSound("aud/Hover.Wav");
	normal = WHITE;
	hovered = GRAY;
	txtColor = BLACK;
	size = 60;
	txtSpacing = 1;
	text = new Text("Button", size, {rec.x + rec.width / 2.f, rec.y + rec.height / 2.f}, BLACK, false);
	indent = 10;
	font = LoadFont("fon/CreepyFont.ttf");
	isHovered = false;
	rot = 0;
}

Button::Button(Vector2 pos, const char* newText)
{
	sprite = LoadTexture("res/Button.png");

	rec.x = pos.x;
	rec.y = pos.y;
	hoverWav = LoadSound("aud/Hover.Wav");
	normal = WHITE;
	hovered = GRAY;
	txtColor = BLACK;
	size = 40;
	txtSpacing = 1;
	text = new Text(newText, size, pos, BLACK, false);
	indent = 10;
	font = LoadFont("fon/CreepyFont.ttf");
	isHovered = false;
	rot = 0;
	
	rec.height = text->measure().y + 2.f * indent;
	rec.width = rec.height * 3.f;
	rec.x -= rec.width / 2.f;
	rec.y -= rec.height / 2.f;
}

Button::Button(Vector2 pos, const char* newText, const char* path)
{
	sprite = LoadTexture(path);

	rec.x = pos.x;
	rec.y = pos.y;
	hoverWav = LoadSound("aud/Hover.Wav");
	normal = WHITE;
	hovered = GRAY;
	txtColor = BLACK;
	size = 40;
	txtSpacing = 1;
	text = new Text(newText, size, pos, BLACK, false);
	indent = 10;
	font = LoadFont("fon/CreepyFont.ttf");
	isHovered = false;
	rot = 0;

	rec.width = text->measure().x + 2.f * indent;
	rec.height = text->measure().y + 2.f * indent;
	rec.x -= rec.width / 2.f;
	rec.y -= rec.height / 2.f;
}

Button::~Button()
{
	delete text;
}

void Button::update()
{
	if (!isHovered && CheckCollisionPointRec(GetMousePosition(), rec))
		startHovered();
	else if (isHovered && !CheckCollisionPointRec(GetMousePosition(), rec))
		endHovered();
}

void Button::draw()
{
	const Rectangle source{ 0, 0, static_cast<float>(sprite.width), static_cast<float>(sprite.height) };

	if (isHovered)
	{
		DrawTexturePro(sprite, source, rec, { 0, 0 }, rot, hovered);
		text->draw();
	}
	else
	{
		DrawTexturePro(sprite, source, rec, { 0, 0 }, rot, normal);
		text->draw();
	}

}

bool Button::isPressed()
{
	return (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
		CheckCollisionPointRec(GetMousePosition(), rec));
}

void Button::setTxt(const char* txt)
{
	text->setText(txt);
}

void Button::setPos(Vector2 newPos)
{
	rec.x = newPos.x;
	rec.y = newPos.y;
}