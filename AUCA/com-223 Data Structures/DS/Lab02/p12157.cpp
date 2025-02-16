#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	int m = 30;
	int j = 60;
	int c = 0;
	int t; cin >> t;
	while (t--) {
		
		int mC = 0;
		int jC = 0;
		int n; cin >> n;
		while (n--) {
			int d; cin >> d;
			
			for (int i = 1; i<m*m; ++i) {
				if (d<i*m) {
					mC+=10*i;
					break;
				}
			}
			
			for (int i = 1; i<j*j; ++i) {
				if (d<i*j) {
					jC+=15*i;
					break;
				}
			}
		}
		
		++c;
		if 		(mC<jC) cout << "Case " << c << ": " << "Mile " << mC << endl;
		else if (mC>jC) cout << "Case " << c << ": " << "Juice " << jC << endl;
		else 			cout << "Case " << c << ": " << "Mile Juice " << mC << endl;
		}
	}
	
	return 0;
}