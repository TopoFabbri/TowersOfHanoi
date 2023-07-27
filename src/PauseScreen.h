#pragma once

#include "Button.h"
#include "Object.h"
#include "Stats.h"
#include "Text.h"

class PauseScreen :
    public Object
{
private:
    Text* title;
    Button* resumeBtn;
    Button* quitBtn;
    Stats* stats;

    int startPauseTime;

public:
    PauseScreen(Stats* newStats);
    ~PauseScreen() override;

    void draw() override;

    void pause();
    bool hasQuit();
};