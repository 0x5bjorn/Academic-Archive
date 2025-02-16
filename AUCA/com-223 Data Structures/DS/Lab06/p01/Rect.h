#ifndef RECT_H
#define RECT_H

#include "AbstractFigure.h"
#include <string>

class Rect: public AbstractFigure
{
    private:
    int w;
    int h;
    
    public:
    Rect(int aX, int aY, int aW, int aH);
    
    std::string toString() const;
    bool contains(int aX, int aY) const;
};

#endif