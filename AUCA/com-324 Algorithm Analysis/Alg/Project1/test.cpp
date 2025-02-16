#include <iostream>
#include <list>

using namespace std;

int main() {
	
	list<char> lst;
	string line;
	while (getline(cin, line)) {
		auto it = line.begin();
		while (it != line.end()) {
			cout << *it << endl;
			++it;
		}
	}
	
	return 0;
}