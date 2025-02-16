#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class VecInt {		
	private:
	int* data;
	int sz;
	int cp;
	
	public:
	VecInt() 
	: data(nullptr), sz(0), cp(0)
	{
	}
	
	VecInt(const VecInt& other) 
	: sz(other.sz), cp(other.sz)
	{
		data = new int[sz];
		for (int i = 0; i < sz; ++i) {
			data[i] = other[i];
		}
	}
	
	~VecInt(){
		delete[] data;
	}
	
	VecInt& operator=(const VecInt& other) {
		if (this != &other) {
			delete[] data;
			sz = other.sz;
			cp = other.sz;
			data = new int[sz];
			for (int i = 0; i < sz; ++i) {
				data[i] = other[i];
			}
		}
		
		return *this;
	}
	
	void pushBack(int x);
	void reverse(int* beg, int* end);
	
	int size() const {
		return sz;
	}
	
	const int& operator[](int index) const {
		return data[index];
	}
	
	int& operator[](int index) {
		return data[index];
	}
	
	int* begin() {
		return data;
	}
	
	int* end() {
		return data + sz;
	}
};

void VecInt::pushBack(int x) {
	
	if (sz == cp) {
		cp = (cp  == 0) ? 1: 2 * cp;
		int* p = new int[cp];
		for (int i = 0; i < sz; ++i) {
			p[i] = data[i];
		}
		
		delete[] data;
		data = p;
	}
	
	data[sz] = x;
	++sz;
}

void VecInt::reverse(int* beg, int* end) {
	if (beg == end) return;
	
	for (;;) {
		if (--end == beg) break;
		
		int t = *beg;
		*beg = *end;
		*end = t;
		
		if (++beg == end) break;
	}
}

bool operator==(const VecInt& a, const VecInt& b) {
	if (a.size() != b.size()) {
		return false;
	}
	
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	
	return true;
}

bool operator!=(const VecInt& a, const VecInt& b) {
	return not (a == b);
}

int main() {
	
	VecInt v;
	
	int x;
	while (cin >> x) {
		v.pushBack(x);
	}
	
	VecInt z;
	VecInt w;
	w.pushBack(12);
	
	w = v;
	
	v = v;
	
	z = w = v;
	
	reverse(w.begin(), w.end());
	
	cout << (v == w ? "palindrome": "not a palindrome");
	
	return 0;
}