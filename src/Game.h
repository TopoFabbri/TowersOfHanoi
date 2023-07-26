#pragma once
#include <conio.h>
#include "Base.h"
#include "Object.h"
#include "Map.h"
#include "Towers.h"
#include "Cursor.h"

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
	static const int objQty = 2;
	Cursor* cursor;
	Object* objs[objQty];

	bool inGame;
};
