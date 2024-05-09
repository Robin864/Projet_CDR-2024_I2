#pragma once

#include <math.h>

class Position
{
private:
public:
    int X, Y;
    Position();
    Position(int x, int y);
    void polToCard(float angle, float distance);
};