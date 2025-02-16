#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	string text = "";
	bool isDash = false;
	set<string> alph;
	string line;
	while (getline(cin, line)) {
	    istringstream sinp(line);
		string cmd;
		while (sinp >> cmd) {
			for (int i = 0; i < cmd.length(); ++i) {
				if (i == cmd.length()-1 and cmd[i]=='-') {
					isDash = true;
				} else if (isalpha(cmd[i]) or cmd[i]=='-') {
					isDash = false;
					text += tolower(cmd[i]);
				} else if (text != "" and cmd[i]!='-') {
					text += ' ';
				}
			}
			if (!isDash) {
				text += ' ';
			}
		}		
	}
	
	istringstream sinp1(text);
	string cmd;
	while (sinp1 >> cmd) {
		alph.insert(cmd);
	}
	
	for (string e: alph) {
		cout << e << endl;
	}
	
	
	return 0;
}