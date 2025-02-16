#include <iostream>
#include <cstdint>

using namespace std;

int64_t fib(int n)
{
    return n == 0 or n == 1 ? 1: fib(n - 2) + fib(n - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << fib(n) << endl;
    }
}