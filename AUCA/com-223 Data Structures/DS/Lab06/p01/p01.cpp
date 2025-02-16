#include <iostream>
#include <string>
#include <vector>

#include "AbstractFigure.h"
#include "Utils.h"

using namespace std;

int main()
{
    vector<AbstractFigure*> list;
    
    
    list.push_back(createFigure("Rect 100 100 200 200"));
    list.push_back(createFigure("Circle 50 50 25"));
   

    int x;
    int y;
    while (cin >> x >> y)
    {
        for (int i = 0; i < int(list.size()); ++i)
        {
            if (list[i]->contains(x, y))
            {
                cout << list[i]->toString() << endl;
                break;
            }
        }
    }

    for (int i = 0; i < int(list.size()); ++i)
    {
        delete list[i];
    }
    
    
    return 0;
}