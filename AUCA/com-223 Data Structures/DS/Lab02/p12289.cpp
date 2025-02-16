#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (s.length() == 3) {
			if 			((s.at(0)=='o' and s.at(1)=='n') or 
						(s.at(1)=='n' and s.at(2)=='e') or
						(s.at(0)=='o' and s.at(2)=='e')) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			} 
		} else {
				cout << 3 << endl;
			}
	}
	
	return 0;
}