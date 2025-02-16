#include <iostream>
#include <stdexcept>

#include "BigInt.h"

using namespace std;

int main()
{
    BigInt a;
    BigInt b;
	char op;
    
    while (cin >> a >> op >> b) {
        
		try {
            Rational c;
            switch (op) {
                case '+':
                    c = a + b;
                    cout << c << endl;
                    break;
                case '-':
                    c = a - b;
                    cout << c << endl;
                    break;
                case '*':
                    c = a * b;
                    cout << c << endl;
                    break;
                case '/':
                    c = a / b;
                    cout << c << endl;
                    break;
				case '%':
                    c = a / b;
                    cout << c << endl;
                    break;	
                default:
                    cout << "Unknown operation: " << op << endl;
                    break;
            }
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}