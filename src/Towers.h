#pragma once

#include "Object.h"
#include "Tower.h"

class Towers :
    public Object
{
private:
    static constexpr int TOWER_QTY = 3;

    float towerSpace;
    float towerHeight;
    float towerWidth;
    float towerBase;
    int discQty;
    Tower* towers[TOWER_QTY];

public:
    Towers();
    ~Towers() override;

    void update() override;
    void draw() override;
};