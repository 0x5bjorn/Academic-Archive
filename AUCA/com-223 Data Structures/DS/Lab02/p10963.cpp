#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int tc; cin >> tc;
	
	while (tc--) {
		
		int n; cin >> n;
		bool correct = true;
		
		int a, b; cin >> a >> b;
		int	d = a-b;	
		for (int i = 0; i < n-1; ++i) {
			int a, b; cin >> a >> b;
			if (a-b!=d) {
				correct = false; 
			}
		}
		
		if (correct) cout << "yes" << endl;
		else 		 cout << "no" << endl;
		
		if (tc) cout << endl;
	}
	
	return 0;
}