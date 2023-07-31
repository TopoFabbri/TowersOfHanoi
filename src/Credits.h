#pragma once
#include "Object.h"
#include "Text.h"

class Credits :
    public Object
{
private:
    Text* title;
    Text* dev;
    Text* art;
    Text* sound;

public:
    Credits();
    ~Credits() override;

    void draw() override;

    int getScene();
};
