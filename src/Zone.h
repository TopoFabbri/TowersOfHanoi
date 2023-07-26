#pragma once

#include "Object.h"
#include "Tower.h"
#include "Tools.h"
#include "Cursor.h"

class Tower;

class Zone :
    public Object
{
private:
    Tower* towerAttached;
    Cursor* cursor;
    bool mouseInZone;

public:
    Zone(Tower* tower, Rectangle newRec, Cursor* cursor);

    void update() override;
};
