#include <string>
#include <sstream>

#include "Utils.h"
#include "Rect.h"
#include "Circle.h"

using namespace std;

AbstractFigure* createFigure(const string& cmd)
{
    istringstream sinp(cmd);
    string figure; 
    sinp >> figure;
    if (figure == "Rect")
    {
        int x; sinp >> x;
        int y; sinp >> y;
        int w; sinp >> w;
        int h; sinp >> h;
        
        return new Rect(x, y, w, h);
    } 
    else if (figure == "Circle")
    {
        int x; sinp >> x;
        int y; sinp >> y;
        int r; sinp >> r;
        
        return new Circle(x, y, r);
    }
}