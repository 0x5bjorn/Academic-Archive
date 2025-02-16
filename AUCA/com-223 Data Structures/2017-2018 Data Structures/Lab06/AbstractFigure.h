#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <string>

class AbstractFigure
{
    protected:
    int x;
    int y;

    public:
    
    AbstractFigure(int aX, int aY);
    virtual ~AbstractFigure()
    {
    }
    
    void move(int dx, int dy);
    
    virtual std::string toString() const = 0;
    virtual bool contains(int aX, int aY) const = 0; 
};

#endif