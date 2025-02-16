#include <iostream>
#include <string>

#include "MapStrInt.h"

using namespace std;

int main()
{
    MapStrInt m;
    
    string w;
    while (cin >> w)
    {
        ++m[w];
    }
    
    m.printInOrder();
    
    m.clear();
    
    m.printInOrder();
    
    return 0;
}