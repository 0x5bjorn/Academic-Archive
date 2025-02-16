#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    
    int d = min(a, b);
    while (a % d != 0 or b % d != 0)
    {
        --d;
    }

    return d;
}

int main()
{
    int a;
    int b;
    
    while (cin >> a >> b)
    {
        clock_t beg = clock();
        int r = gcd(a, b);
        clock_t end = clock();
        cout << "time: " << double(end - beg) / CLOCKS_PER_SEC << endl;
        cout << "result: " << r << endl;
    }
    
    return 0;
}