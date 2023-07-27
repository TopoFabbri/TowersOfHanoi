#pragma once

#include <string>
#include "Base.h"
#include "Credits.h"
#include "Object.h"
#include "Map.h"
#include "Towers.h"
#include "Cursor.h"
#include "Menu.h"
#include "PauseScreen.h"
#include "Stats.h"
#include "Text.h"
#include "WinScreen.h"

enum class State
{
	Quit,
	Game,
	Credits,
	Menu,
	WinScreen,
	PauseScreen
};

class Game :
    public Base
{
public:
	Game();
	~Game() override;

	void run();

protected:
	void start() override;
	void update() override;
	void draw() override;

private:
	static const int objQty = 1;
	Cursor* cursor;
	Map* map;
	Towers* towers;
	Menu* menu;
	Credits* credits;
	Stats* stats;
	WinScreen* winScreen;
	PauseScreen* pauseScreen;
	Button* resetBtn;
	Button* menuBtn;

	State state;

	void reset();
};