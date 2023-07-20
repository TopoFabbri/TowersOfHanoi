#include "Map.h"

Map::Map(Vector2 size)
{
	rec = { 0, 0, size.x, size.y };
	rot = 0;
	sprite = LoadTexture(spritePath);
}

Map::~Map()
{
}