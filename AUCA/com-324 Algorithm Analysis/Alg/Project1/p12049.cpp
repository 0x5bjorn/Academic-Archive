#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int l1, l2;
		while (cin >> l1 >> l2) {
			int res = 0;
			unordered_map<int, int> m;
			while(l1--) {
				int n; cin >> n;
				++m[n];
			}
			while(l2--) {
				int n; cin >> n;
				--m[n];
			}
			for (auto it = m.begin(); it != m.end(); ++it) {
				if (it->second >= 0) res += it->second;
				else 				 res += -(it->second);
			}
			cout << res << endl;
		}
	}
					
	return 0;
}