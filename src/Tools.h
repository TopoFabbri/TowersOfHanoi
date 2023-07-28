#pragma once
#include <raylib.h>

class Tools
{
public:
	static const int WIDTH = 1366;
	static const int HEIGHT = 768;

	static Vector2 toConsoleDimensions(Vector2 v);
	static Rectangle toConsoleDimensions(Rectangle r);
	static Vector2 toScreenDimensions(Vector2 v);
};