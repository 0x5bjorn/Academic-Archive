#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<int> counters('Z' - 'A' + 1, 0);
	
	char ch;
	while (cin.get(ch)) {
		if (isalpha(ch)) {
			ch = toupper(ch);
			++counters[ch - 'A'];
		}
	}
	
	char letter = 'A';
	for (int c: counters) {
		cout << letter << ": " << c << endl;
		++letter;
	}
	// C++ 98
	//vector<int>::max_element(counters.begin(), counters.end());
		
	// C++ 11
	auto p = max_element(counters.begin(), counters.end());
	
	cout << char('A' + p - counters.begin()) << endl;
	cout << *p << endl;
		
	return 0;
}