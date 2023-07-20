#pragma once
#include <raylib.h>

class Tools
{
public:
	static constexpr int WIDTH = 1366;
	static constexpr int HEIGHT = 768;

	static Vector2 toConsoleDimensions(Vector2 v);
	static Rectangle toConsoleDimensions(Rectangle r);
};