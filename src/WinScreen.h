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
    std::string moves;
    std::string time;
    bool finished;

public:
    WinScreen(Stats* newStats);
    ~WinScreen() override;

    void update() override;
    void draw() override;

    bool getFinished();
    void restartFinished();
};