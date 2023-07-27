#pragma once
#include "Base.h"
#include "Cursor.h"
#include "Button.h"

class Menu :
    public Base
{
private:
	Button* playBtn;
	Button* credsBtn;
	Button* quitBtn;

public:
	Menu();
	
	int updateMenu();
	void draw() override;
};
