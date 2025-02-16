#include <iostream>

using namespace std;

int main() {
	
	int a; int b;
	
	while (cin >> a >> b) {
		if (b == 0) {
			cout << "divisor can not be 0" << endl;
			continue;
		}
		
		cout << a << " / " << b << " = " << a/b << endl;
		cout << a << " % " << b << " = " << a%b << endl;
	}
	
	return 0;
}
