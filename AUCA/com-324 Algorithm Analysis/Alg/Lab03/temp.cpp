#include <iostream>

using namespace std;

int main() {
	
	int n; cin >> n;
	
	int s;
	for (int i = 1; i < n; ++i) {
		#ifdef AUCA_DEBUG
		cout << "s = " << s << " i = " << i << endl;
		#endif
		s += i;
	}
	
	cout << s << endl;
	
	return 0;
}