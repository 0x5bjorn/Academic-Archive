// compilation: g++ -std=c++11 *.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include "AbstractFigure.h"
#include "Utils.h"

using namespace std;

// typedef shared_ptr<AbstractFigure> SmartPtrToFigure;

using SmartPtrToFigure = shared_ptr<AbstractFigure>;

void printList(const vector<SmartPtrToFigure>& list);
void showProperties(const vector<SmartPtrToFigure>& list, int x, int y);
void moveFigure(const vector<SmartPtrToFigure>& list, int x, int y, int dx, int dy);

int main()
{
    vector<SmartPtrToFigure> list;
    
    int x;
    int y;
    int dx;
    int dy;
    
    SmartPtrToFigure fig = nullptr;
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string w; sinp >> w;
        
        if (w == "print" and sinp >> ws  and sinp.eof())
        {
            printList(list);
        }
        else if ((w == "rect" or w == "circle") and (fig = createFigure(line)))
        {
            list.emplace_back(fig);
        }
        else if (w == "properties" and sinp >> x >> y >> ws and sinp.eof())
        {
            showProperties(list, x, y);
        }
        else if (w == "move" and sinp >> x >> y  >> dx >> dy >> ws and sinp.eof())
        {
            moveFigure(list, x, y, dx, dy);
        }
        else
        {
            cout << "'" << line << "': incorrect command" << endl;
        }    
    }
    
    return 0;
}

void printList(const vector<SmartPtrToFigure>& list)
{
    for (const auto& f: list)
    {
        cout << f->toString() << endl;
    }
}


void showProperties(const vector<SmartPtrToFigure>& list, int x, int y)
{
    for (const auto& f: list)
    {
        if (f->contains(x, y))
        {
            cout << f->toString() << endl;
        }
    }
}

void moveFigure(const vector<SmartPtrToFigure>& list, int x, int y, int dx, int dy)
{
    SmartPtrToFigure fig = nullptr;
    for (const auto& f: list)
    {
        if (f->contains(x, y))
        {
            fig = f;
        }
    }
    
    if (fig)
    {
        fig->move(dx, dy);
    }
}