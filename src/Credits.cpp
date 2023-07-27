#include "Credits.h"

Credits::Credits()
{
	rec = { 0, 0, 100, 100 };
}

int Credits::getScene()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 3;

	return 2;
}