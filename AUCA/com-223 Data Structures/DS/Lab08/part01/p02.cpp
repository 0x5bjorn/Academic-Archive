#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"

using namespace std;

double eval(const string& line);

int main()
{
    string line;
    while (getline(cin, line))
    {
        try
        {
            double res = eval(line);
            cout << "= " << res << endl;
        }
        catch (StackException& e)
        {
            cerr << "incorrect expression: '" << line << "'\n";
            cerr << "error: too many operators" << endl;
        }
        catch (runtime_error& e)
        {
            cerr << "incorrect expression: '" << line << "'\n";
            cerr << "error: " << e.what() << endl;
        }
    }
    
    return 0;
}

double eval(const string& line)
{
    Stack<double> stk;
    
    istringstream sinp(line);
    string token;
    while (sinp >> token)
    {
        if (token == "+")
        {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            stk.push(a + b);
        }
        else if (token == "-")
        {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            stk.push(b - a);
        }
        else if (token == "*")
        {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            stk.push(a * b);
        }
        else if (token == "/")
        {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            if (a == 0.0)
            {
                throw runtime_error("division by zero");
            }
            stk.push(b / a);
        }
        else
        {
            istringstream sinp2(token);
            double x;
            if (sinp2 >> x and sinp2.eof())
            {
                stk.push(x);
            }
            else
            {
                throw runtime_error("incorrect double: '" + token + "'");
            }
        }
    }
    
    if (stk.size() != 1)
    {
        throw runtime_error("not enough operators");
    }
    
    return stk.top();
}