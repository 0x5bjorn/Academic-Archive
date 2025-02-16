#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main() {
	int t;
	string empty;
	while (cin >> t) {
		if (t == 0) break;
		
		getline(cin, empty);
		int res = 0;
		int max = 0;
		map<set<int>, int> m;
		int c;
		while (t--) {
			string line;
			getline(cin, line);
			set<int> s;
			istringstream sinp(line);
			while (sinp >> c) {
				s.insert(c);
			}
			++m[s];
		}
		
		for (auto it = m.begin(); it != m.end(); ++it) {
			if (it->second > max) max = it->second, res = 0;
			if (it->second == max) res += max;
		}
		
		cout << res << endl;
	}		
	return 0;
}