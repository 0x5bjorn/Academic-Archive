#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << "1 cathetus: ";
    double a;
    cin >> a;
    
    cout << "2 cathetus: ";
    double b;
    cin >> b;
    
    double c = sqrt(a * a + b * b);
    
    
    cout << "hypotenuse: " << fixed << setprecision(4) << c << endl;
    
    return 0;
}