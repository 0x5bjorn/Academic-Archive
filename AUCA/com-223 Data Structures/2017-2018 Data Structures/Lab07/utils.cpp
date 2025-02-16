#include <string>
#include <sstream>
#include <memory>

#include "Utils.h"
#include "Rect.h"
#include "Circle.h"

using namespace std;

shared_ptr<AbstractFigure> createFigure(const string& cmd)
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
        return make_shared<Rect>(t1, t2, t3, t4);
    } 
    else if (figure == "circle" and sinp >> t1 >> t2 >> t3 >> ws and sinp.eof())
    {
        return make_shared<Circle>(t1, t2, t3);
    }

    return 0;
}