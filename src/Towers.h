#pragma once

#include "Disc.h"
#include "Object.h"
#include "Tower.h"

class Towers :
    public Object
{
private:
    static constexpr int TOWER_QTY = 3;
    static constexpr int MAX_DISCS = 9;

    float towerSpace;
    float towerHeight;
    float towerWidth;
    float towerTop;
    float discSpace;
    float discHeight;
    int discQty;
    float towerPoss[TOWER_QTY];
    Tower* towers[TOWER_QTY];
    Disc* discs[MAX_DISCS];

public:
    Towers();
    ~Towers() override;

    void update() override;
    void draw() override;

    void moveDisc(int discIndex, int toTower);
};