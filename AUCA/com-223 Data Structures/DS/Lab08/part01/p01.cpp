#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        Stack<char> stk;
        
        bool isCorrect = true;
        istringstream sinp(line);
        char ch;
        while (sinp >> ch and isCorrect)
        {
            if (ch == '(' or ch == '{' or ch == '[')
            {
                stk.push(ch);
            }
            else if (stk.empty())
            {
                isCorrect = false;
            }
            else if (stk.top() == '(' and ch != ')')
            {
                isCorrect = false;
            }
            else if (stk.top() == '{' and ch != '}')
            {
                isCorrect = false;
            }
            else if (stk.top() == '[' and ch != ']')
            {
                isCorrect = false;
            }
            else
            {
                stk.pop();
            }
        }
        if (not stk.empty())
        {
            isCorrect = false;
        }
        
        cout << (isCorrect ? "correct": "incorrect") << endl;
    }
    
    return 0;
}