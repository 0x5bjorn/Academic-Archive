#include <iostream>
#include <stdexcept>

using namespace std;

int gcdAux(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a == 0)
    {
        return b;
    }
    return gcdAux(b, a % b);
}

int gcd(int a, int b)
{
    if (a == 0 and b == 0)
    {
        throw invalid_argument("gcd(0, 0) is not defined");
    }
    return gcdAux(a, b);
}

int main()
{
    int a;
    int b;
    while (cin >> a >> b)
    {
        try
        {
            cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}
