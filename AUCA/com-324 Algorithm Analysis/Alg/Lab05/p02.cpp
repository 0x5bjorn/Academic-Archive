#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main() {
	
	map<string, set<int>> m;
	
	int counter = 0;
	string line;
	while(getline(cin, line)) {
		++counter;
		istringstream sinp(line);
		string w;
		while (sinp >> w) {
			m[w].insert(counter);
		}
	}
	
	for (const auto& p: m) {
		cout << p.first << ":";
		for (const auto& n: p.second) {
			cout << " " << n;
		}
		cout << endl;
	}
	
	return 0;
}