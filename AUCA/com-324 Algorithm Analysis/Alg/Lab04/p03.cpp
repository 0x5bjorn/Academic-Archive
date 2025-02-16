#include <iostream>

using namespace std;

void printTable( , const string& s, double a, double b, double step) {
	
}

double sqrt(double x) {
	return x * x;
}

int main() {
	
	double (*fp)(double);
	cout << sizeof(fp) << endl;
	
	fp = sqrt;
	cout << "sqrt(4.0) = " << fp(4.0) << endl;
	
	fp = abs;
	cout << "sqrt(-3.5) = " << abs(-3.5) << endl;
	
	printTable();
	printTable
	printTable
	
	return 0;
}