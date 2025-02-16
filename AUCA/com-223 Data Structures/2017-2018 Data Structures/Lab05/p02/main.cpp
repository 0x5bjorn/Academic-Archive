#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Rational.h"

using namespace std;

int main()
{
    char op;
 
    string s1;
    string s2;
    while (cin >> s1 >> op >> s2)
    {
        try
        {
            istringstream sinp1(s1); 
            Rational a; sinp1 >> a;
            
            istringstream sinp2(s2);
            Rational b; sinp2 >> b;

            Rational c;
            switch (op)
            {
                case '+':
                    c = a + b;
                    cout << c << endl;
                    cout << c.toDouble() << endl;
                    cout << c.toSchoolForm() << endl;
                    break;
                case '-':
                    c = a - b;
                    cout << c << endl;
                    cout << c.toDouble() << endl;
                    cout << c.toSchoolForm() << endl;
                    break;
                case '*':
                    c = a * b;
                    cout << c << endl;
                    cout << c.toDouble() << endl;
                    cout << c.toSchoolForm() << endl;
                    break;
                case '/':
                    c = a / b;
                    cout << c << endl;
                    cout << c.toDouble() << endl;
                    cout << c.toSchoolForm() << endl;
                    break;
                default:
                    cout << "Unknown operation: " << op << endl;
                    break;
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}
