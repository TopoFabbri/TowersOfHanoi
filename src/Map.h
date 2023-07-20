#pragma once
#include "Object.h"

class Map :
    public Object
{
private:
    const char* spritePath = "res/BG.png";

public:
    Map(Vector2 size);
    ~Map() override;
};