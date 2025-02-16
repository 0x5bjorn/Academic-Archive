#include <iostream>

using namespace std;

int main() {
	
	bool inQuote = false;
	
	char ch;
	while(cin.get(ch)) {
		
		if (ch == '\"' and not inQuote) {
			cout.put('`');
			cout.put('`');
			inQuote = true;
		} else if (ch == '\"') {
			cout.put('\'');
			cout.put('\'');
			inQuote = false;
		} else {
			cout.put(ch);
		}
	}

	return 0;
}