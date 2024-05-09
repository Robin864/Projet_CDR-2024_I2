#include "Position.h"

Position::Position()
{
    X = 0;
    Y = 0;
}

Position::Position(int x, int y)
{
    X = x;
    Y = y;
}

void Position::polToCard(float angle, float distance)
{
    X = distance * cos(angle);
    Y = distance * sin(distance);
}