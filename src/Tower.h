#pragma once
#include "Object.h"

class Tower :
    public Object
{
private:
    int number;

public:
    int discs;

    Tower(int discQty, int newNumber, float posX, float height, float width, float base);
    ~Tower() override;

    void draw() override;
};