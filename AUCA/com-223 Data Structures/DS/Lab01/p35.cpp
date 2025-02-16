#include <iostream>

using namespace std;

void myBadSwap(int a, int b) {
	int t = a;
	a = b; 
	b = a;
}

void myGoodSwap(int& a, int& b) {
	int t = a;
	a = b; 
	b = a;
}

int main() {
	
	cout << "a: ";
	int a; cin >> a;
	
	cout << "b: ";
	int b; cin >> b;
	
	cout << "before swap a = " << a << ", b = " << b << endl;
	
	myBadSwap(a, b);
	
	cout << "after swap a = " << a << ", b = " << b << endl;
	
	cout << "before swap a = " << a << ", b = " << b << endl;
	
	myGoodSwap(a, b);
	
	cout << "after swap a = " << a << ", b = " << b << endl;
}