#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string kb = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
	string line;
	getline(cin, line);
	
	string r = "";
	for (unsigned i = 0; i<line.length(); ++i) {
		if (line[i] != '`' and line[i] != '1' and line[i] != 'q' and line[i] != 'w' and
			line[i] != 'a' and line[i] != 's' and line[i] != 'z' and line[i] != 'x' and 
			line[i] != 'Q' and line[i] != 'W' and line[i] != 'A' and line[i] != 'S' and 
			line[i] != 'Z' and line[i] != 'X') {
				
			if (line[i] == ' ') r += line[i];
			else {
				for (unsigned j = 0; j<kb.length(); ++j) {
					line[i] = tolower(line[i]);
					if (line[i]==kb[j]) {
						r += kb[j-2];
					}
				}
			}
		}
	}
	
	cout << r << endl;
	
	return 0;
}