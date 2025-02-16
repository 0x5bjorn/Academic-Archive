#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setfill('.');
	cout << left << setw(20) << "Fortran" << right << setw(20) << 1957 << endl;
	cout << left << setw(20) << "C" << right << setw(20) << 1972 << endl;
	cout << left << setw(20) << "C++" << right << setw(20) << 1980 << endl;
	cout << left << setw(20) << "Java" << right << setw(20) << 1995 << endl;
	cout << left << setw(20) << "C#" << right << setw(20) << 2000 << endl;
	
	return 0;
}