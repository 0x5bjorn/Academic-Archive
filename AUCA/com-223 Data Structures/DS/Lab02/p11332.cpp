#include <iostream>

using namespace std;

int main() {
	
	int n; 
	while (cin >> n) {
		if (n==0) break;
		
		int sum = 0;
		int temp = n;
		
		while (n/10!=0) {
			sum += temp%10;
			temp/=10;
			
			if (temp == 0) {
				n = sum;
				temp = sum;
				sum = 0;
			}
		}
		cout << n << endl;
	}
	
	return 0;
}