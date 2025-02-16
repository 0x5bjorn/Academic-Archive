#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
	
	string line;
	while (getline(cin, line)) {
		vector<string> v;
		istringstream sinp(line);
		string s; 
		while (sinp >> s) {
			
			string temp;
			for (char c: s) {
				temp += c;
			}
			
			reverse(temp.begin(), temp.end());
			
			v.push_back(temp);
		}
		
		for (unsigned i = 0; i<v.size(); ++i) {
			cout << v[i];
			if (i==(v.size()-1)) cout << endl;
			else 				 cout << " ";
		}
	}
	
	return 0;
}