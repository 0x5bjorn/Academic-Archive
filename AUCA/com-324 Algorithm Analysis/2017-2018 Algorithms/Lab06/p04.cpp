#include <iostream>

using namespace std;

void solve(int n, char s, char d, char t)
{
    if (n > 0)
    {
        solve(n - 1, s, t, d);
        cout << s << "->" << d << endl;
        solve(n - 1, t, d, s);
    }
}

int main()
{
    int n; cin >> n;
    
    solve(n, 'a', 'c', 'b');
    
    return 0;
}