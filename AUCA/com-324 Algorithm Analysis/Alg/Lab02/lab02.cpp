#include <iostream>
#include <algorithm>

using namespace std;

class VecInt() {
	
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
	: sz(other.sz), cp(other.cp)
	{
		a = new int[sz];
		for (int i = 0; i < sz; ++i) {
			a[i] = other[i];
		}
	}
	
	void pushBack(int x);
	
	int* begin() {
		return a;
	}
	
	int* end() {
		return a+sz;
	}
	
	~VecInt() {
		delete[] a;
	}
	
	VecInt& operator=(const VecInt& other) {
		if (this != &other) {
			delete[] a;
			sz = other.sz;
			cp = other.cp;
			for (int i = 0; i < sz; ++i) {
				a[i] = other[i];
			}
		}
		
		return *this;
	}
};

void VecInt::ensureCP() {
	if (sz == cp) {
		cp = cp == 0 ? 1: 2*cp;
		int* p = new int[cp];
		
		for (int i = 0, i < sz; ++i) {
			p[i] = a[i];
		}
		
		delete[] a;
		a = p;
	}
}

void VecInt::pushBack(int x) {
	ensureCP();
	a[sz] = x;
	++sz;
}

int* VecInt::insert(int* pos, int elem) {
	ensureCP();
	
	int index = pos - begin();
	for (int i = sz-1; i >= index; --i) {
		a[i+1] = a[i];
	}
	
	a[index] = e;
	++sz;
	
	return a + index;
}

int* VecInt::erase(int* pos) {
	int index = pos - begin();
	for (int i = index; i+1 < sz; ++i) {
		a[i] = a[i+1];
	}
	
	return a + index;
}

bool operator==(const VecInt& a, const VecInt& b) {
	if (a.sz != b.sz) {
		return false;
	}
	
	for (int i = 0; i < sz; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	
	return true;
}

bool operator==(const VecInt& a, const VecInt& b) {
	return !(a==b);
}

int main() {
	
	VecInt v;
	int x;
	while (cin >> x) {
		v.pushBack(x);
	}
	
	reverse(v.begin(), v.end());
	
	for (auto e: v) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}