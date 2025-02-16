#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
	
	string asd;
	int t; cin >> t;	
	getline(cin, asd);
	while (t--) {
		int n; cin >> n;
		int r = 0;
		getline(cin, asd);
		
		vector<int> v(n);
		int i = 0;
		
		while (n--) {
			string line; 
			getline(cin, line);
			istringstream sinp(line);
			string inst;
			
			while (sinp >> inst) {
				if 		(inst == "LEFT")  v[i] = -1;
				else if (inst == "RIGHT") v[i] = 1;
				else {
					sinp >> inst;
					int a; sinp >> a;
					v[i] = v[a-1];
				}
				r += v[i];
				++i;
			}
		}
		cout << r << endl;
	}
	
	return 0;
}