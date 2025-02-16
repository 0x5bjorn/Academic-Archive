#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	
	int r = 0;
	int t; cin >> t;
	while (t--) {
		string operation; cin >> operation;
		if (operation == "donate") {
			int donate; cin >> donate;
			r += donate;
		} else {
			cout << r << endl;
		}
	}
	
	return 0;
}