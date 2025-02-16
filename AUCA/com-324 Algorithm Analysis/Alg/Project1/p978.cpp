#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main () {
	
	int t; cin >> t;
	while (t--) {
		multiset<int> ga;
		multiset<int> ba;
		int b, sg, sb; cin >> b >> sg >> sb;
		while (sg--) {
			int p; cin >> p;
			ga.insert(p);
		}
		
		while (sb--) {
			int p; cin >> p;
			ba.insert(p);
		}
		
		int c;
		while ((!ga.empty() and !ba.empty()) and (!ga.empty() or !ba.empty())) {
			vector<int> v;
			if (b <= ga.size() and b <= ba.size()) c = b;
			else c = min(ga.size(), ba.size());
			
			while (c--) {			
				auto it1 = ga.end();
				auto it2 = ba.end();
				int res = *(--it1) - *(--it2);
				v.push_back(res);
				ga.erase(it1);
				ba.erase(it2);
			}	
			
			for (int i = 0; i < v.size(); ++i) {
				if 		(v[i] < 0)  ba.insert(v[i]*(-1));
				else if (v[i] != 0) ga.insert(v[i]);
			}
		}
		
		if (ga.empty() and ba.empty()) {
			cout << "green and blue died" << endl;
		} else if (ba.empty()) {
			cout << "green wins" << endl;
			for (auto it = ga.rbegin(); it != ga.rend(); ++it) {
				cout << *it << endl;
			}
		} else if (ga.empty()) {
			cout << "blue wins" << endl;	
			for (auto it = ba.rbegin(); it != ba.rend(); ++it) {
				cout << *it << endl;
			}
		}
		
		if (t!=0) cout << endl;
	}
	
	return 0;
}