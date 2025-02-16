#include <iostream>

using namespace std; 

int main() {
	
	int t; cin >> t;
	while (t--) {

		int sum = 0;
		int f; cin >> f;
		while (f--) {
			
			int a, b, c; cin >> a >> b >> c;
			double s = (double)a/b;
			double r = s*c*b;
			if (r+0.5>=(int)r+1) ++r;
			sum+=(int)r;
		}
		
		cout << sum << endl;
	}
	
	return 0;
}