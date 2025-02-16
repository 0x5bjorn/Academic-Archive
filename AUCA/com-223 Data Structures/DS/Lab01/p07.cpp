#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
	
	char minChar = numeric_limits<char>::min();
	char maxChar = numeric_limits<char>::max();
	
	cout << "size of char: " << sizeof(char) << endl;
	
	cout << "min value of char: " << int(minChar) << endl;
	cout << "max value of char: " << int(maxChar) << endl;
	
	cout << endl;
	
	cout << "digits (ASCII): " << endl;
	cout << '0' << ": " << int('0') << endl;
	cout << '1' << ": " << int('1') << endl;
	cout << '2' << ": " << int('2') << endl;
	cout << "..." << endl;
	cout << '9' << ": " << int('9') << endl;
	
	cout << endl;
	
	cout << "1st digit: ";
	char d1;
	cin >> d1;
	
	cout << "2nd digit: ";
	char d2;
	cin >> d2;
	
	cout << d1 << " * " << d2 << " = " << (d1 - '0') * (d2 - '0') << endl;
	
	cout << endl;
	
	cout << "Upper-case letter: " << endl;
	cout << 'A' << ": " << int('A') << endl;
	cout << 'B' << ": " << int('B') << endl;
	cout << 'C' << ": " << int('C') << endl;
	cout << "..." << endl;
	cout << 'Z' << ": " << int('Z') << endl;
	
	cout << endl;
	
	cout << "Lower-case letter: " << endl;
	cout << 'a' << ": " << int('a') << endl;
	cout << 'b' << ": " << int('b') << endl;
	cout << 'c' << ": " << int('c') << endl;
	cout << "..." << endl;
	cout << 'z' << ": " << int('z') << endl;
	
	cout << endl;
	
	cout << "Upper-case letter: ";
	char uc;
	cin >> uc;
	cout << "Lower-case letter: " << char(uc + 'a' - 'A') << endl;	
	
	cout << endl;
	
	cout << "Lower-case letter: ";
	char lc;
	cin >> lc;
	cout << "Upper-case letter: " << char(lc - ('a' - 'A')) << endl;
	
	return 0;
}