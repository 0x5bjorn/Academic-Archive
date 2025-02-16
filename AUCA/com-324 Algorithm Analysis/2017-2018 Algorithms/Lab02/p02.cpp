#include <iostream>
#include <algorithm>

using namespace std;

class VecInt
{
    private:
    int* a;
    int sz;
    int cp;
    
    public:
    
    VecInt()
    : a(nullptr), sz(0), cp(0)
    {
    }
    
    void pushBack(int x);

    int* begin()
    {
        return a;
    }
    
    int* end()
    {
        return a + sz;
    }
    
    ~VecInt()
    {
        delete[] a;
    }
};

void VecInt::pushBack(int x)
{
    if (sz == cp)
    {
        cp = cp == 0 ? 1: 2 * cp;
        int* p = new int[cp];
        
        for (int i = 0; i < sz; ++i)
        {
            p[i] = a[i];
        }
        
        delete[] a;
        a = p;
    }
    a[sz] = x;
    ++sz;
}

int main()
{
    VecInt v;
    
    int x;
    while (cin >> x)
    {
        v.pushBack(x);
    }
    
    reverse(v.begin(), v.end());
    
    for (auto e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}