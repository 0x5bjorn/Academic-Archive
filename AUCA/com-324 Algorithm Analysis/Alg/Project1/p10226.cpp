#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
	int t; cin >> t;
	string empty;
	getline(cin, empty);
	getline(cin, empty);
	while (t--) {
		map<string, int> m;
		int total = 0;
		string s;
		while (getline(cin, s) and !s.empty()) {
			++total;
			++m[s];
		}

		for (auto it = m.begin(); it != m.end(); ++it) {
			cout << it->first << " " << fixed << setprecision(4) << it->second*100.0/total << endl;
		}
		if (t != 0) cout << endl;
	}

	return 0;
}