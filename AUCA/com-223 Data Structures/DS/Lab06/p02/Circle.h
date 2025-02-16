#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "AbstractFigure.h"

class Circle: public AbstractFigure
{
    private:
    int r;
    
    public:
    Circle(int aX, int aY, int aR);
    
    std::string toString() const;
    bool contains(int aX, int aY) const;
};

#endif