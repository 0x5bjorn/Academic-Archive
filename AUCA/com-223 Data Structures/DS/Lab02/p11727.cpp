#include <iostream>

using namespace std;

int main() {
	
	int t; cin >> t;
	int counter = 0;
	while(t--) {
		int a, b, c; cin >> a >> b >> c;

		int r1 = min(min(a, b), min(b, c));
		int r2 = max(max(a, b), max(b, c));
		int r;
		
		if 		((a==r1 and b==r2) or (a==r2 and b==r1)) r = c;
		else if ((a==r1 and c==r2) or (a==r2 and c==r1)) r = b;
		else if ((c==r1 and b==r2) or (c==r2 and b==r1)) r = a;

		++counter;
		
		cout << "Case " << counter << ": " << r << endl;
	}
	
	return 0;
}