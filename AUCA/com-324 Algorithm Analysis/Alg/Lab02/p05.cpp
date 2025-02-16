#include <iostream>
#include <vector>

using namespace std;

class VecInt {		
	private:
	int* data;
	int sz;
	int cp;
	
	void ensureCapacity(); 
	
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
	
	~VecInt() {
		delete[] data;
	}
	
	int* insert(int* it, int e);
	int* erase(int* it);
	
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

void VecInt::ensureCapacity() {
	if (sz == cp) {
		cp = (cp  == 0) ? 1: 2 * cp;
		int* p = new int[cp];
		for (int i = 0; i < sz; ++i) {
			p[i] = data[i];
		}
		
		delete[] data;
		data = p;
	}
}

int* VecInt::insert(int* it, int e) {
	int index = it - begin();
	
	ensureCapacity();
	
	for (int i = sz - 1; i >= index; --i) {
		data[i + 1] = data[i];
	}
	data[index] = e;
	++sz;
	
	return data + index;
}

int* VecInt::erase(int* it) {
	int index = it - begin();
	for (int i = index; i + 1 < sz; ++i) {
		data[i] = data[i + 1];
	}
	--sz;
	
	return data + index;
}

void VecInt::pushBack(int x) {
	
	ensureCapacity();
	
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
	
	auto it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.insert(it, 0);
			++it;
		}
		++it;
	}
	
	for (auto e: v) {
		cout << e << " ";
	}
	cout << endl;
	
	it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.erase(it);
		} else {
			++it;
		}
	}
	
	for (auto e: v) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}