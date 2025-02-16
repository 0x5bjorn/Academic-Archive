#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main() {
	
	string line;
	set<string> alph;
	while (cin >> line) {
		string s = "";
		for (int i = 0; i < line.length(); ++i) {
			if (isalpha(line[i])) {
				s += tolower(line[i]);
			} else if (s != "") {
				alph.insert(s);
				s = "";
			}
		}
		if (s != "") {
			alph.insert(s);
		}
	}
	
	for (string e: alph) {
		cout << e << endl;
	}
	
	return 0;
}