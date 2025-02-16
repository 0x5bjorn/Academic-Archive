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
    int t1;
    int t2;
    int t3;
    int t4;
    sinp >> figure;
    if (figure == "rect" and sinp >> t1 >> t2 >> t3 >> t4 >> ws and sinp.eof())
    {
        return new Rect(t1, t2, t3, t4);
    } 
    else if (figure == "circle" and sinp >> t1 >> t2 >> t3 >> ws and sinp.eof())
    {
        return new Circle(t1, t2, t3);
    }

    return 0;
}