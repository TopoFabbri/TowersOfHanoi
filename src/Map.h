#pragma once
#include "Object.h"

class Map :
    public Object
{
public:
    Map(Vector2 size);
    ~Map() override;

    void start() override;
    void update() override;
};