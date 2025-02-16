#include <iostream>
#include <ctime>

using namespace std;

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	
	if (n == 2) {
		return true;
	}
	
	if (n % 2 == 0) {
		return false;
	}
	
	for (int i = 3; i*i<=n; i+=2) {
		if (n%i==0) {
			return false;
		}
	}
	return true;
}

int main() { 
	
	int a; cin >> a;
	int b; cin >> b;
	
	clock_t beg = clock();
	
	int r = 0;	
	for (int i = a; i<=b; ++i) {
		r += isPrime(i);
	}
	
	clock_t end = clock();
	cout << "result: "<< r << endl;
	cout << "time: "<< (double)(end - beg)/CLOCKS_PER_SEC << endl;
	
	return 0;
}