#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	
	vector<string> txt;
	
	string line;
	while (getline(cin, line)) {
		txt.push_back(line);
	}
	
	// opposite stoi, stod
	int w = to_string(txt.size()).size();
	
	for (int i = 0; i < int(txt.size()); ++i) {
		cout << setw(w) << i + 1 << ": " << txt[i] << endl;
	}
	
	return 0;
}