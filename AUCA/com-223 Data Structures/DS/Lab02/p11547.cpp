#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int tc; cin >> tc;
	
	while (tc--) {
		
		int n; cin >> n;
		int r = (n*567/9+7492)*235/47-498;
		r/=10;
		r%=10;
		
		cout << abs(r) << endl;
	}
	
	return 0;
}