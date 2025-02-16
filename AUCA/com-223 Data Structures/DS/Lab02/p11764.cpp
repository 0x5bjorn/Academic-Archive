#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int c = 0;
	int t; cin >> t;
	while (t--) {
		
		int w; cin >> w;
		vector<int> v;
		int hj = 0;
		int lj = 0;
		int temp = 0;
		
		while (w--) {
			int n; cin >> n;
			v.push_back(n);
		}
		
		for (int n: v) {
			if (temp!=0) {
				if 		(temp < n) ++hj;
				else if (temp > n) ++lj;
			}
			temp = n;
		}
		
		++c;
		cout << "Case " << c << ": " << hj << " " << lj << endl;
	}
	
	return 0;
}