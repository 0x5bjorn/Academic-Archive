#include <iostream>
#include <cstdint>

using namespace std;

int64_t fib(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    
    int64_t a = 1;
    int64_t b = 1;
    for (int i = 2; i <= n; ++i)
    {
        int64_t t = a + b;
        a = b;
        b = t;
    }
    
    return b;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << fib(n) << endl;
    }
}