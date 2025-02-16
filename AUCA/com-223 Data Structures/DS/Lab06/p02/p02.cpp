#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "AbstractFigure.h"
#include "Utils.h"

using namespace std;

int main()
{
    vector<shared_ptr<AbstractFigure>> list;
    
    list.push_back(shared_ptr<AbstractFigure>(createFigure("Rect 100 100 200 200")));
    list.push_back(shared_ptr<AbstractFigure>(createFigure("Circle 50 50 25")));

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
    
    return 0;
}