#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

void printTable (
        double (*f)(double),
        const string& s, double a, double b, double step)
{
    cout << s << endl;
    cout << string(50, '-') << endl;
    cout << setw(10) << "x" << setw(40) << "f(x)" << endl;
    
    double x = a;
    cout << fixed;
    while (x <= b)
    {
        cout << setw(10) << setprecision(4) << x
             << setw(40) << setprecision(6) << f(x) << endl;
        x += step;
    }
    cout << string(50, '-') << endl;
}

double sqr(double x)
{
    return x * x;
}

int main()
{
    double (*fp)(double);
    
    cout << sizeof(fp) << endl;
    
    fp = sqrt;
    
    cout << "sqrt(4.0) = " << fp(4.0) << endl;

    fp = abs;
    
    cout << "abs(-5.0) = " << fp(-5.0) << endl;
    
    printTable(sqrt, "Table of sqrt(x)", 0, 100, 10);
    printTable(abs, "Table of abs(x)", -10, 10, 2);
    printTable(sqr, "Table of sqr(x)", 1, 10, 1);
    
    return 0;
}
