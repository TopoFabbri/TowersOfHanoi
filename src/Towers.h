#pragma once

#include "Disc.h"
#include "Object.h"
#include "Tower.h"
#include "Zone.h"

class Towers :
    public Object
{
private:
    static constexpr int TOWER_QTY = 3;

    float towerSpace;
    float towerHeight;
    float towerWidth;
    float towerTop;
    float discSpace;
    float discHeight;
    int discQty;
    float towerPoss[TOWER_QTY];
    Tower* towers[TOWER_QTY];
    Zone* zones[TOWER_QTY];
    Disc* discs[Tower::MAX_DISCS];

public:
    Towers(Cursor* cursor);
    ~Towers() override;

    void update() override;
    void draw() override;

    bool won();
};