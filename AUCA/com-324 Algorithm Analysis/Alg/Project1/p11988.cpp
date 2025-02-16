#include <iostream>
#include <list>

using namespace std;

int main() {
	
	string line;
	while (getline(cin, line)) {	
		list<char> lst;	
		auto it = lst.begin();
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] == '[') {
				it = lst.begin();
			} else if (line[i] == ']') {
				it = lst.end();
			} else {
			    lst.insert(it, line[i]);
			}
		}	
		
		for (char e: lst) {
			cout << e;
		}
		cout << endl;
	}
	
	return 0;
}