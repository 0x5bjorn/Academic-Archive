#include <iostream>

using namespace std;

int main() { 
	
	int t; cin >> t;
	while (t--) {
		
		int a, b; cin >> a >> b;
		
		int r = (a/3) * (b/3);
		
		cout << r << endl;
	}
	
	return 0;
}