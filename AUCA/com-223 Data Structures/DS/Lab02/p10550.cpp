#include <iostream>

using namespace std;

int main() {
	
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (a==0 and b==0 and c==0 and d==0) {
			break;
		}
				
		int an = 360/40;
		int first = ((a - b + 40) % 40) * an;
		int second = ((c - b + 40) % 40) * an;
		int third = ((c - d + 40) % 40) * an;
		int r = 360*3 + first + second + third;
		
		cout << r << endl;
	}
	
	return 0;
}