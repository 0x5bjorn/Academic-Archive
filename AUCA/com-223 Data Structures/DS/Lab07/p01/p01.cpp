#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"
using namespace std; 

int main() {
	
	string line;
	while (getline(cin, line)) {
		
		//template class
		stack<char> stk;
		int isCorrect = true;
		istringstream sinp(line);
		char ch;
		while (sinp >> ch) {
			if (ch == '(' or ch == '{' or ch == '[') {
				stk.push(ch);
			} else if (stk.empty()) {
				isCorrect = false;
				break;
			} else if (stk.top() == '(' and ch != ')') {
				isCorrect = false;
				break;
			} else if (stk.top() == '{' and ch != '}') {
				isCorrect = false;
				break;
			} else if (stk.top() == '[' and ch != ']') {
				isCorrect = false;
				break;
			} else {
				stk.pop();
			}
		}
		
		if (not stk.empty()) {
			isCorrect = false;
		}
		
		cout << (isCorrect ? "correct" : "incorrect") << endl;
	}
	
	return 0;
}