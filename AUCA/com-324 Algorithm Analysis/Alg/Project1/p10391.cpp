#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> s;
	string word;
	while (cin >> word) {
		s.insert(word);
	}
	
	for (auto it = s.begin(); it != s.end(); ++it) {	
		for (int j = 0; j < (*it).size(); ++j) {
			string a = (*it).substr(0, j);
			string b = (*it).substr(j, (*it).size()-1);
			
			if (s.find(a) != s.end() && s.find(b) != s.end()) {
				cout << (*it) << endl;
				break;
			}
		}
	}
	
	return 0;
}