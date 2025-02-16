#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
	unordered_map<string, string> m;
	string line;
	while (getline(cin, line) and !line.empty()) {
		istringstream sinp(line);
		string eng, foreign; sinp >> eng >> foreign;
		m.insert({foreign, eng});
	}

	string in;
	while (cin >> in) {
		// auto it = m.find(in);
		// if (it->second == in) cout << it->first << endl;
		// else 				  cout << "eh" << endl;
		
		string res = m[in];
		if (res != "") cout << res << endl;
		else 			 cout << "eh" << endl;
	}
	
	return 0;
}