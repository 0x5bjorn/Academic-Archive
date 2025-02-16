#include <sstream>
#include "Circle.h"

using namespace std;

Circle::Circle(int aX, int aY, int aR)
: AbstractFigure(aX, aY), r(aR)
{
}

string Circle::toString() const
{
    ostringstream sout;
    sout << "Circle[" << x << ", " << y << ", " << r << "]";
    
    return sout.str();
}


bool Circle::contains(int aX, int aY) const
{
    int dx = x - aX;
    int dy = y - aY;
    return dx * dx + dy * dy <= r * r;
}
