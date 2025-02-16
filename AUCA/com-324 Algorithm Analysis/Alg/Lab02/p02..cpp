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
	
	~VecInt(){
		delete[] data;
	}
	
	void pushBack(int x);
	void reverse(int* beg, int* end);
	
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