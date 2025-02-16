#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double cmPerInch = 2.54;
    
    cout << "length in inches: ";
    double length;
    cin >> length;
    
    cout << "this length in cm: "
         << fixed << setprecision(2) << cmPerInch * length << endl;
    
    return 0;
}