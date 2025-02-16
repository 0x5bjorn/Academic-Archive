#include <iostream>
#include <ctime>

using namespace std;

int gcd(int a, int b) {
	if (a==0 and b==0) {
		throw domain_error("gcd(0, 0) is not defined");
	}
	if (a==0) {
		return b;
	}
	if (b==0) {
		return a;
	}
	
//	int d = min(a, b);
//	cout << "do: " << d << endl;
//	cout << "asd: " << a%d << endl;
//	while (a%d!=0 or b%d!=0) {
//		--d;
//		cout << "posle: " << d << endl;
//	}
	
	
	
	return d;
}

int main() {
	
	int a, b;
	while (cin >> a >> b) {
		try {
			clock_t beg = clock();
			int r = gcd(a, b);
			clock_t end = clock();
			cout << "result: " << r << endl;
			cout << "time: " << (double)(end - beg)/CLOCKS_PER_SEC << endl;
		} catch {
			
		}
	}
	
	
	return 0;
}