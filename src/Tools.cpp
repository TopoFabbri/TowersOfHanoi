#include "Tools.h"

Vector2 Tools::toConsoleDimensions(Vector2 v)
{
	v.x = v.x / 100.f * WIDTH;
	v.y = v.y / 100.f * HEIGHT;

	return v;
}

Rectangle Tools::toConsoleDimensions(Rectangle r)
{
	r.x = r.x / 100.f * WIDTH;
	r.y = r.y / 100.f * HEIGHT;

	r.width = r.width / 100.f * WIDTH;
	r.height = r.height / 100.f * HEIGHT;

	return r;
}

Vector2 Tools::toScreenDimensions(Vector2 v)
{
	v.x = v.x / WIDTH * 100.f;
	v.y = v.y / HEIGHT * 100.f;

	return v;
}