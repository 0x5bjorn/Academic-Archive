#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
	
	string asd;
	int n; cin >> n;	
	getline(cin, asd);
	while (n--) {
		getline(cin, asd);	
		
		string line;
		getline(cin, line);
		istringstream sinp1(line);
		vector<int> pos;
		int p; 
		while (sinp1 >> p) {
			pos.push_back(p);
		}
			
		getline(cin, line);
		istringstream sinp2(line);
		vector<string> num(pos.size());
		int a = pos.size();
		int i = 0;
		while (a--) {
			sinp2 >> num[pos[i]-1];
			++i;
		}
		
		for (string r: num) {
			cout << r << endl;
		}
		if (n != 0) cout << endl;
	}
	
	return 0;
}