#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	string line;
	int t; cin >> t;
	unordered_map<string, string> m;
	getline(cin, line);
	while (t--) {
		string slogan1, slogan2;
		getline(cin, slogan1);
		getline(cin, slogan2);
		m[slogan1] = slogan2;
	}
	
	int q; cin >> q;
	getline(cin, line);
	while (q--) {
		string s;
		getline(cin, s);
		if (!m.insert({s, "asd"}).second) cout << m[s] << endl;
	}
	
	return 0;
}