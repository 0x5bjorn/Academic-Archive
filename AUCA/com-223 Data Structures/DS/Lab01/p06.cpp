#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {

	cout << "size of double: " << sizeof(double) << endl;
	
	cout << "min value of double: " << numeric_limits<double>::min() << endl;
	cout << "max value of double: " << numeric_limits<double>::max() << endl;
	
	double x = 0.0;
	
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	x+= 0.1;
	
	cout << "1.0 = " << fixed << setprecision(2) << x << endl;
	cout << "1.0 = " << fixed << setprecision(4) << x << endl;
	cout << "1.0 = " << fixed << setprecision(6) << x << endl;
	cout << "1.0 = " << fixed << setprecision(8) << x << endl;
	cout << "1.0 = " << fixed << setprecision(10) << x << endl;
	cout << "1.0 = " << fixed << setprecision(12) << x << endl;
	cout << "1.0 = " << fixed << setprecision(14) << x << endl;
	cout << "1.0 = " << fixed << setprecision(16) << x << endl;
	
	return 0;
}