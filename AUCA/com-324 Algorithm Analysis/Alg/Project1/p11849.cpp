#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int j1, j2;
	while (cin >> j1 >> j2) {
		if (j1 == 0 and j2 == 0) break;
		
		int res = 0;
		unordered_set<int> s;
		while(j1--) {
			int cd; cin >> cd;
			s.insert(cd);
		}
		while(j2--) {
			int cd; cin >> cd;
			auto it = s.find(cd);
			if (it != s.end()) ++res;
		}
		cout << res << endl;
	}
					
	return 0;
}