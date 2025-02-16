#include <iostream>
#include <vector>

class VecInt
{
    private:
    int* a;
    int sz;
    int cp;
    
    void ensureCapacity();
    
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
    
    ~VecInt()
    {
        delete[] a;
    }
    
    int* insert(int* it, int e);
    int* erase(int* it);
    
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
    
    
};

void  VecInt::ensureCapacity()
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
}

int* VecInt::insert(int* it, int e)
{
    int index = it - begin();
    
    ensureCapacity();
    
    for (int i = sz - 1; i >= index; --i)
    {
        a[i + 1] = a[i];
    }
    
    a[index] = e;
    
    ++sz;
    
    return a + index;
}

int* VecInt::erase(int* it)
{
    int index = it - begin();
    for (int i = index; i + 1 < sz; ++i)
    {
        a[i] = a[i + 1];
    }
    --sz;
    
    return a + index;
}

void VecInt::pushBack(int x)
{
    ensureCapacity();
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
    
    auto it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            it = v.insert(it, 0);
            ++it;
        }
        ++it;
    }
    
    for (int e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    
    it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    for (int e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}