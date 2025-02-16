#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	
	int c = 0;
	int t; cin >> t;
	while (t--) {
		
		int n = 10;
		vector<string> web;
		vector<int> rel;
		
		while (n--) {
			string w; cin >> w;
			int r; cin >> r;
			web.push_back(w);
			rel.push_back(r);
		}
		
		++c;
		cout << "Case #" << c << ":" << endl;
		
		int i = 0;
		auto rR = max_element(rel.begin(), rel.end());
		for (int a: rel) {
			if (a==(int)*rR) {
				cout << web[i] << endl;
			}
			++i;
		}	
	}
	
	return 0;
}