#include <iostream>

using namespace std;

int main()
{
    cout << "some integer: ";
    int n; cin >> n;
    int counter =0;
    do
    {
        cout << n % 10 << endl;
        n /= 10;
        ++counter;
    } while (n != 0);
    
    cout << "this number has " << counter
         << " digit" << (counter == 1 ? "": "s") << endl;
    
    return 0;
}