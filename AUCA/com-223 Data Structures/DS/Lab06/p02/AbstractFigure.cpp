#include "AbstractFigure.h"

AbstractFigure::AbstractFigure(int aX, int aY)
: x(aX), y(aY)
{
}

void AbstractFigure::move(int dx, int dy)
{
    x += dx;
    y += dy;
}