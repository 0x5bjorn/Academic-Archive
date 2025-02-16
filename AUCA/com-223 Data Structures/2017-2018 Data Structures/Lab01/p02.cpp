#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setfill('.');
    cout << left << setw(20) << "Fortran" << right << setw(40) << 1957 << endl;
    cout << left << setw(20) << "C" << right << setw(40) << 1972 << endl;
    cout << left << setw(20) << "C++" << right << setw(40) << 1980 << endl;
    cout << left << setw(20) << "Java" << right << setw(40) << 1995 << endl;
    cout << left << setw(20) << "C#" << right << setw(40) << 2000 << endl;
    
    return 0;
}