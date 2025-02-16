#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdexcept>

using namespace std;


int gcd(int a, int b)
{
    if (a == 0 and b == 0)
    {
        throw domain_error("gcd(0, 0) is not defined");
    }
    
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

int main()
{
    int a;
    int b;
    
    while (cin >> a >> b)
    {
        try
        {
            clock_t beg = clock();
            int r = gcd(a, b);
            clock_t end = clock();
            cout << "time: " << double(end - beg) / CLOCKS_PER_SEC << endl;
            cout << "result: " << r << endl;
        }
        catch (domain_error& e)
        {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}