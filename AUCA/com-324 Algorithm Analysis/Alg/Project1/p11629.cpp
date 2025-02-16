#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
	int p, g; cin >> p >> g;
	unordered_map<string, int> m;
	while (p--) {			
		string name; cin >> name;
		double vote; cin >> vote;
		m[name] = (int)(vote*10);
	}
	
	string line;
	getline(cin, line);
	for (int i = 1; i <= g; ++i) {
		getline(cin, line);
		bool res;
		int t = 0;
		double sum = 0;
		istringstream sinp(line);
		string s;
		while (sinp >> s) {	
			if (s == ">") {
				sinp >> t;
				res = sum > t*10;
				break;
			}
			if (s == ">=") {
				sinp >> t;
				res = sum >= t*10;
				break;
			}
			if (s == "<") {
				sinp >> t;
				res = sum < t*10;
				break;
			}
			if (s == "<=") {
				sinp >> t;
				res = sum <= t*10;
				break;
			}
			if (s == "=") {
				sinp >> t;
				res = sum == t*10;
				break;
			}
			
			if (s!="+") sum += m[s];
		}
		
		if (res) cout << "Guess #" << i << " was correct." << endl;
		else 	 cout << "Guess #" << i << " was incorrect." << endl;
	}
	
	return 0;
}