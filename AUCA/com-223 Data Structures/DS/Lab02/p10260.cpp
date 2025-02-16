#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	string s; 
	while (cin >> s) {
		vector<int> v;
		for (unsigned i = 0; i<s.size(); ++i) {
			int d = 0;
			switch (s[i]) {
				case 'B': case 'F': case 'P': case 'V':
					d = 1;
					break;
				case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
					d = 2;
					break;
				case 'D': case 'T':
					d = 3;
					break;
				case 'L':
					d = 4;
					break;
				case 'M': case 'N':
					d = 5;
					break;
				case 'R':
					d = 6;
					break;
				default:
					break;
			}
			if (v.size()>0) {
				if (d != v[v.size()-1]) {
					v.push_back(d);
				}
			} else {
				v.push_back(d);
			}
		}
		
		for (int n: v) {
			if (n!=0) cout << n;
		}
		cout << endl;
	}
	
	
	return 0;
}