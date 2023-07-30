#pragma once
#include <string>

#include "Object.h"
#include "Stats.h"
#include "Text.h"

class WinScreen :
    public Object
{
private:
    Stats* stats;
    Text* title;
    Text* movesTxt;
    Text* timeTxt;
    bool finished;

public:
    WinScreen(Stats* newStats);
    ~WinScreen() override;

    void update() override;
    void draw() override;

    bool getFinished();
    void restartFinished();
};