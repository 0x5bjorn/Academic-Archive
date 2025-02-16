#include <sstream>
#include "Rect.h"

using namespace std;

Rect::Rect(int aX, int aY, int aW, int aH)
: AbstractFigure(aX, aY), w(aW), h(aH)
{
}

string Rect::toString() const
{
    ostringstream sout;
    sout << "Rect[" << x << ", " << y << ", " << w << ", " << h << "]";
    
    return sout.str();
}

bool Rect::contains(int aX, int aY) const
{
    int bx = x <= aX and aX <= x + w;
    int by = y <= aY and aY <= y + h;
    
    return bx and by;
}