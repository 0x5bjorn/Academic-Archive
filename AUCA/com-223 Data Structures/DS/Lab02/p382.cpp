#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	int a;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> a and a != 0) {
		
		int c = 0;
		for (int i = 1; i < a; ++i) {
			if (a%i==0) {
				c+=i;
			}
		}
		
		
		cout << setfill(' ');
		cout << right << setw(5) << a << "  ";
		if (c==a) {
			cout << "PERFECT" << endl;
		} else if (c<a) {
			cout << "DEFICIENT" << endl;
		} else if (c>a) {
			cout << "ABUNDANT" << endl;
		}
		
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
	
}