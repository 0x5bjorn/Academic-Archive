#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	
	map<string, int> m;
	
	string w;
	while(cin >> w) {
		++m[w];
	}
	
	for (const auto& p: m) {
		cout << p.first << ": " << p.second << endl;
	}
	
	return 0;
}