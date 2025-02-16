#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>	
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
		
	string line;
	int n; cin >> n;
	getline(cin, line);
	while (n--) {
		int c = 0;
		int p1 = 0; int p2 = 0; int p3 = 0; int p4 = 0;
		string s1, s2, s3, s4, s5;
		
		string line1;
		getline(cin, line1);
		for (unsigned i = 0; i<line1.size(); ++i) {
			if (c==0) {
				if (line1[i] == '<') p1 = i;
				if (line1[i] == '>') {
					p2 = i;
					c=1;
				}
			} else if (c==1) {
				if (line1[i] == '<') p3 = i;
				if (line1[i] == '>') {
					p4 = i;
					c=2;
				}
			}
		}
		
		s1 = line1.substr(0, p1);
		s2 = line1.substr(p1+1, (p2-p1-1));
		s3 = line1.substr(p2+1, (p3-p2-1));
		s4 = line1.substr(p3+1, (p4-p3-1));
		s5 = line1.substr(p4+1, (line1.size() - p4));

		line1.erase(p1, 1);
		line1.erase(p2-1, 1);
		line1.erase(p3-2, 1);
		line1.erase(p4-3, 1);
		
		string line2;
		getline(cin, line2);
		for (unsigned i = 0; i<line2.size(); ++i) {
			if (line2[i] == '.') {
				line2.erase(i);
			}
		}
		line2+=s4+s3+s2+s5;
		
		cout << line1 << endl;
		cout << line2 << endl;
	}
		
	return 0;
}