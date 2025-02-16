#include <iostream>

using namespace std;

int main() {
	
	int c = 0;
	int t; cin >> t;
	while (t--) {
		int l, w, h; cin >> l >> w >> h;
		c++;
		
		if (l>20 or w>20 or h>20) {
			cout << "Case " << c << ": " << "bad" << endl;
		} else {
			cout << "Case " << c << ": " << "good" << endl;
		}		
	}
	
	return 0;
}