#include <iostream>

using namespace std;

int main()
{
    int a; cin >> a;
    int b; cin >> b;
    
    if (a <= b)
        goto L1;
    
    swap(a, b);
    
L1: 
    int64_t s = 0;
    
    int i = a;
L3: if (i > b)
        goto L2;
    s += i;
    ++i;
    goto L3;
    
L2:
    cout << s << endl;
    
    return 0;
}