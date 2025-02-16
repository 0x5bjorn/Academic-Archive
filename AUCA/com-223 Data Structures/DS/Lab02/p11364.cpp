#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--) {
		
		int sum = 0;
		int temp = 0;
		int dif;
		vector<int> v;
		int s; cin >> s;
		
		while (s--) {
			int p; cin >> p;
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		
		for (int n: v) {
			dif = abs(n - temp);
			temp = n;
			sum += dif;
		}
		sum += abs(v[0] - temp);
		sum -= v[0];
		
		cout << sum << endl;
	}
	
	return 0;
}