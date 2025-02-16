#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
	
	vector<string> v = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", 
						"Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	vector<string> names;
	int t; cin >> t;
	string name;
	while (t--) {
		cin >> name;
		names.push_back(name);
	}	
	
	unsigned c = 0;
	
	for (unsigned i = 0; i<names.size(); ++i) {	
		cout << names[i] << ": " << v[c] << endl;
		++c;
		if (c==v.size()) c = 0;
	}
	
	if (c!=v.size()) {
		for (unsigned i = 0; c<v.size(); ++i) {	
			cout << names[i] << ": " << v[c] << endl;
			++c;	
		}
	}
	
	return 0;
}