#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int a, b;
	while (cin >> a >> b) {
		
		int x = a;
		int y = b;
		if (x > y) {
			swap(x, y);
		}
		
		int res = 0;
		
		for (int i = x; i<=y; ++i) {
			int c = 1;
			int t = i;
			
			while (t!=1) {
				++c;
				
				if (t%2 == 0) {
					t/=2;
				}
				else {
					t = 3*t + 1;
				}
			}
			res = max(res, c);
		}
		
		cout << a << ' ' << b << ' ' << res << "\n";
	}

	return 0;
}