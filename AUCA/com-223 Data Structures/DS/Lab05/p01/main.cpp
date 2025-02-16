// separate compilation

#include <iostream>
#include <stdexcept>

#include "mathutils.h"

using namespace std;

int main()
{
    int a;
    int b;
    while (cin >> a >> b)
    {
        try
        {
            int d = gcd(a, b);
            cout << d << endl;
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
        }
        
    }
}

