// compilation: g++ -std=c++03 *.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "AbstractFigure.h"
#include "Utils.h"

using namespace std;

void printList(const vector<AbstractFigure*>& list);
void showProperties(const vector<AbstractFigure*>& list, int x, int y);
void moveFigure(const vector<AbstractFigure*>& list, int x, int y, int dx, int dy);

int main()
{
    vector<AbstractFigure*> list;
    
    int x;
    int y;
    int dx;
    int dy;
    AbstractFigure* fig = 0;
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string w; sinp >> w;
        
        if (w == "print" and sinp >> ws  and sinp.eof())
        {
            printList(list);
        }
        else if ((w == "rect" or w == "circle") and (fig = createFigure(line)) != 0)
        {
            list.push_back(fig);
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

    for (int i = 0; i < int(list.size()); ++i)
    {
        delete list[i];
    }
    
    return 0;
}

void printList(const vector<AbstractFigure*>& list)
{
    for (int i = 0; i < int(list.size()); ++i)
    {
        cout << list[i]->toString() << endl;
    }
}


void showProperties(const vector<AbstractFigure*>& list, int x, int y)
{
    for (int i = 0; i < int(list.size()); ++i)
    {
        if (list[i]->contains(x, y))
        {
            cout << list[i]->toString() << endl;
        }
    }
}

void moveFigure(const vector<AbstractFigure*>& list, int x, int y, int dx, int dy)
{
    AbstractFigure* fig = 0;
    for (int i = 0; i < int(list.size()); ++i)
    {
        if (list[i]->contains(x, y))
        {
            fig = list[i];
        }
    }
    if (fig)
    {
        fig->move(dx, dy);
    }
}