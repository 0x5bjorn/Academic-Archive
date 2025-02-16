#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int n; cin >> n;
	
	for (int i = 0; i<n; ++i) {
		string a; cin >> a;
		if (a == "1" or a == "4" or a == "78") {
			cout << "+" << endl;
		} else if (a[a.size()-1] == '5' and a[a.size()-2] == '3') {
			cout << "-" << endl;
		} else if (a[0] == '9' and a[a.size()-1] == '4') {
			cout << "*" << endl;
		} else {
			cout << "?" << endl;
		}
	}	
	
	return 0;
}
