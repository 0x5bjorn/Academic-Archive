#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int a, b;
	while (cin >> a >> b) {
		if (a==-1 and b==-1) break;
		
		int r = abs(a-b);
		if (r>50) r = 100-r;
		
		cout << r << endl;
	}
	
	return 0;
}