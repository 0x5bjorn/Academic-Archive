#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	
	int t;
	while (cin >> t) {
		if (t == 0) break;
		
		vector<size_t> v;
		size_t e;
		while (t--) {
			size_t e; cin >> e;
			v.push_back(e);
		}
		
		sort(v.begin(), v.end());
		auto low = lower_bound(v.begin(), v.end(), v[v.size()-1]);
		bool check = false;
		
		size_t sum = 0;
		for (auto it1 = v.begin(); it1 != v.end(); ++it1) {
			sum += *it1;
			for (auto it2 = v.begin(); it2 != v.end(); ++it2) {
				sum += *it2;
				if (sum > *low) {
					check = false;
					break;
				} else if (sum == *low) {
					check = true;
					break;
				}
			}
			if (check) break;
			else sum = 0;
		}
		
		if (check) cout << sum << endl;
		else 	   cout << "no solution" << endl;
	}
	
	return 0;
}