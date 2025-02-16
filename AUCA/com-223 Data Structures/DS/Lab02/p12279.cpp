#include <iostream> 

using namespace std;

int main() {
	
	int c = 0;
	int n;
	while (cin >> n) {
		if (n==0) break;
		
		int r = 0;
		while (n--) {
			int a; cin >> a;
			if (a==0) {
				r--;
			} else {
				r++;
			}
		}

		c++;
		cout << "Case " << c << ": " << r << endl;
	}
	
	return 0;
}