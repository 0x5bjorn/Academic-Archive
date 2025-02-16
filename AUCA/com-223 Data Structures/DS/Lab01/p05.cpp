#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	cout << "1st cthetus: ";
	double a;
	cin >> a;
	
	cout << "2nd cthetus: ";
	double b;
	cin >> b;
	
	double c = sqrt(a*a + b*b);
	
	cout << "hypotenuse: " << fixed << setprecision(4) << c << endl;
	
	return 0;
}