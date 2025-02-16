#include <iostream>
#include <algorithm>

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
	
	VecInt(const VecInt& other)
	: sz(other.sz), cp(other.sz)
	{
		a = new int[sz];
		for (int i = 0; i < sz; ++i)
		{
			a[i] = other[i];
		}
	}
    
    VecInt& operator=(const VecInt& other)
    {
        if (this != &other)
        {
            delete[] a;
            sz = other.sz;
            cp = other.sz;
            a = new int[sz];
            for (int i = 0; i < other.size(); ++i)
            {
                a[i] = other[i];
            }
        }
        
        return *this;
    }
    
    void pushBack(int x);
    
	int size() const
	{
		return sz;
	}
	
	const int& operator[](int index) const
	{
		return a[index];
	}
	
	int& operator[](int index) 
	{
		return a[index];
	}
	
    int* begin() const
    {
        return a;
    }
    
    int* end() const
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

bool operator==(const VecInt& a, const VecInt& b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	
	return true;
}

bool operator!=(const VecInt& a, const VecInt& b)
{
	return !(a == b);
}

using namespace std;

int main()
{
    VecInt v;
    
    int x;
    while (cin >> x)
    {
        v.pushBack(x);
    }
    
    VecInt w = v;
    // w = v
    
    reverse(w.begin(), w.end());
    
    cout << (v == w ? "palindrome": "not a palindrome");
	
    return 0;
}