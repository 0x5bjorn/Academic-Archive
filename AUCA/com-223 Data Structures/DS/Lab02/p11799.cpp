#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int counter = 0;
	int t; cin >> t;
	while (t--) {
		int r = 0;
		
		int x; cin >> x;
		while (x--) {
			int s; cin >> s;
			if (s>r) r = s;
		}
		
		++counter;
		cout << "Case " << counter << ": " << r << endl;
	}
	
	return 0;
}