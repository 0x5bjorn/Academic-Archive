#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    vector<int> v;
    
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    
    vector<int> w = v;
    
    reverse(w.begin(), w.end());
    
    cout << (v == w ? "palindrome": "not a palindrome");
    
    return 0;
}