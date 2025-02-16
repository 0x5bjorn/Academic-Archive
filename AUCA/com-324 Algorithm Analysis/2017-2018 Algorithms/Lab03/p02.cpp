#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int>& v)
{
    // for (list<int>::const_iterator it = v.begin();
         // it != v.end(); ++it)
    // {
        // cout << *it << " ";
    // }
    // cout << endl;
    
    for (auto e: v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void printInReversedOrder(const list<int>& v)
{
    // for (list<int>::const_reverse_iterator it = v.rbegin();
         // it != v.rend(); ++it)
    // {
        // cout << *it << " ";
    // }
    // cout << endl;
    
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    printInDirectOrder(v);
    printInReversedOrder(v);
    
    auto p = v.begin();
    while (p != v.end())
    {
        if (*p % 2 == 0)
        {
            p = v.insert(p, 0);
            ++p;
        }
        ++p;
    }
    
    printInDirectOrder(v);
    printInReversedOrder(v);
    
    p = v.begin();
    while (p != v.end())
    {
        if (*p % 2 == 0)
        {
           p = v.erase(p);
        }
        else
        {
            ++p;
        }
    }
    
    printInDirectOrder(v);
    printInReversedOrder(v);
    
    return 0;
}