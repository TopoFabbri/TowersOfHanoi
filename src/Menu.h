#pragma once
#include "Base.h"
#include "Cursor.h"
#include "Button.h"
#include "Text.h"

class Menu :
    public Object
{
private:
	Text* title;
	Button* playBtn;
	Button* credsBtn;
	Button* quitBtn;

public:
	Menu();
	~Menu() override;
	
	int updateMenu();
	void draw() override;
};
