#include <iostream>

using namespace std;

int main() {
	int64_t a, b;
	
	while(cin >> a >> b) {
		if (a==0 and b==0) {
			break;
		}
		
		int64_t x = a; 
		int64_t y = b;
		if (x<y) {
			swap(x, y);
		}
		
		int64_t c = 0;
		int64_t carry = 0;
		while (x!=0 or y!=0) {
			int64_t s = 0;
			s = (x%10 + y%10 + carry)/10;
			carry = 0;
			x/=10;
			y/=10;			
			if (s > 0) {
				++c;
				carry = 1;
			}
		}
		
		if (c==0) {
			cout << "No carry operation." << endl;
		} else if (c==1) {
			cout << c << " carry operation." << endl;
		} else {
			cout << c << " carry operations." << endl;
		}
	}
	
	return 0;
}

