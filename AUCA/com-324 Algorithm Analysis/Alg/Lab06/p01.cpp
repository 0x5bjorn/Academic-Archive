#include <iostream>

using namespace std;

void printInReversedOrder()
{
    int x;
    if (cin >> x)
    {
        printInReversedOrder();
        cout << " " << x;
    }
}

int main()
{
    printInReversedOrder();
    cout << endl;
    
    return 0;
}