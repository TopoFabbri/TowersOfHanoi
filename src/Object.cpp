#include "Object.h"

Object::Object()
{
	rec = { 0, 0, 10, 10 };
	rot = 0;
	sprite = {};
	tint = WHITE;
}

Object::~Object()
{
}

void Object::start()
{
}

void Object::update()
{
}

void Object::draw()
{
	if (!active)
		return;

	const Rectangle source = { 0.f, 0.f,
static_cast<float>(sprite.width), static_cast<float>(sprite.height) };
	const Vector2 origin = { 0, 0 };

	if (sprite.width != 0)
		DrawTexturePro(sprite, source, Tools::toConsoleDimensions(rec), origin, rot, tint);
	else
		DrawRectanglePro(Tools::toConsoleDimensions(rec), origin, rot, tint);
}