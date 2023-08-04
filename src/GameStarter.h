#pragma once

#include <raylib.h>

#include "Tools.h"
#include "Game.h"

class GameStarter
{
private:
	static void defaults();
	static void close();

public:
	static void runProgram();
};