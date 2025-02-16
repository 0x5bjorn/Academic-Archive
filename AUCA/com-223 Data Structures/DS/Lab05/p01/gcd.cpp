#include <stdexcept>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0 and b == 0)
    {
        throw runtime_error("gcd(0, 0) is not defined");
    }
    
    a = abs(a);
    b = abs(b);
    
    if (a == 0)
    {
        return b;
    }
    
    if (b == 0)
    {
        return a;
    }
    
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}