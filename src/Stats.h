#pragma once
#include "Base.h"
#include "Cursor.h"

class Stats :
    public Base
{
private:
    int moves;
    int time;

    int startTime;

public:
    Stats();

    void update() override;

    void resetStats();
    void setMoves(int newMoves);
    int getTime();
    int getMoves();
    void addPausedTime(int pausedTime);
};