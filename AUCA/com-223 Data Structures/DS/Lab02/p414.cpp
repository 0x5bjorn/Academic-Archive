#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
	
	string asd;
	int n;		
	while (cin >> n) {
		getline(cin, asd);
		if (n==0) break;
		
		int r = 0;
		vector<string> v;
		
		while (n--) {
			string a = "";
			string line;
			getline(cin, line);
			istringstream sinp(line);
			string s;
			while (sinp >> s) {
				a += s;
			}
			v.push_back(a);
		}
		
		sort(v.begin(), v.end());
		
		for (unsigned i = 0; i<v.size()-1; ++i) {
			r += v[v.size()-1].size() - v[i].size();
		}
		
		cout << r << endl;
	}
	
	return 0;
}