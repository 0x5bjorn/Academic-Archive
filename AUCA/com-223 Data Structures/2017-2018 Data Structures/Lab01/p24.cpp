#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v;
    
    string name;
    while (cin >> name)
    {
        v.push_back(name);
    }
    
    sort(v.begin(), v.end());
    
    for (string n: v)
    {
        cout << n << endl;
    }
    
    return 0;
}