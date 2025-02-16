#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

bool isPalindrome(string s);
bool isMirrored(string s);

int main() {
	
	string s;
	while (getline(cin, s)) {
		
		if (isPalindrome(s)) {
			if (isMirrored(s)) {
				cout << s << " -- is a mirrored palindrome." << endl;
				cout << endl;
			} else {
				cout << s << " -- is a regular palindrome." << endl;
				cout << endl;
			}
		} else if (isMirrored(s)) {
			cout << s << " -- is a mirrored string." << endl;
			cout << endl;
		} else {
			cout << s << " -- is not a palindrome." << endl;
			cout << endl;
		}
	}
	return 0;
}

bool isPalindrome(string s) {
	
	bool palindrome = false;
	
	string temp;
	for (char c: s) {
		temp += c;
	}
	
	string check = temp;
	reverse(check.begin(), check.end());
	
	if (check == temp) palindrome = true;
	else 			   palindrome = false;
	
	return palindrome;
}

bool isMirrored(string s) {
	
	bool mirrored = false;
	string asd = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	string dsa = "A   3  HIL JM O   2TUVWXY51SE Z  8 0";
	
	string temp = "";
	
	for (unsigned i = 0; i<s.size(); ++i) {
		for (unsigned j = 0; j<asd.size(); ++j) {
			if (s[i] == asd[j]) {
				temp += dsa[j];
			}
		}
	}
	reverse(temp.begin(), temp.end());

	if (temp == s) mirrored = true;
	else 		   mirrored = false;
	
	return mirrored;
}










