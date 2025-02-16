#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string s);
bool isMagicSquarePalindrome(string s, int square);
bool isSquare(string s);
int squareOf(string s);
string onlyAlpha(string s);

int main() {
	
	string asd;
	int c = 0;
	int t; cin >> t;
	getline(cin, asd);
	while (t--) {
		string s;
		getline(cin, s);
		
		++c;
		string temp = onlyAlpha(s);
		int square = squareOf(temp);
		
		cout << "Case #" << c << ":" << endl;
		if 		(temp.size() == 1) cout << 1 << endl;
		else if (temp.size() == 0) cout << 0 << endl;
		else {
			if (isPalindrome(temp)) {
				if (isMagicSquarePalindrome(temp, square)) cout << square << endl;
				else 									   cout << "No magic :(" << endl;
			} else {
				cout << "No magic :(" << endl;
			}
		} 
	}
	
	return 0;
}

bool isPalindrome(string s) {
	bool palindrome = false;
	
	string check = s;
	reverse(check.begin(), check.end());
	
	if (check == s) palindrome = true;
	else 			palindrome = false;
	
	return palindrome;
}

bool isMagicSquarePalindrome(string s, int square) {
	
	bool magicSquarePalindrome = false;
	vector<string> v;
	
	if (isSquare(s)) {
		for (unsigned i = 0; i<s.size(); i+=square) {
			v.push_back(s.substr(i, square));
		}
		
		for (unsigned i = 0; i<v.size()/2; ++i) {
			string check = v[v.size()-1-i];
			reverse(check.begin(), check.end());
			
			if (v[i] == check) magicSquarePalindrome = true;
			else {
				magicSquarePalindrome = false;
				break;
			}
		}
	}

	return magicSquarePalindrome;
}

bool isSquare(string s) {
	
	bool square = false;
	
	for (unsigned i = 1; i<s.size(); ++i) {
		if (s.size()/i == i) {
			square = true;
			break;
		}
		else square = false;
	}
	
	return square;
}

int squareOf(string s) {
	
	int r = 0;
	
	for (unsigned i = 1; i<s.size(); ++i) {
		if (s.size()/i == i) {
			r = i;
			break;
		}
	}
	
	return r;
}

string onlyAlpha(string s) {
	
	string temp;
	for (char c: s) {
		if (isalpha(c)) {
			temp += c;
		}
	}
	
	return temp;
}

