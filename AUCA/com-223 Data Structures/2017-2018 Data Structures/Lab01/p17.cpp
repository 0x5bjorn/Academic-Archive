#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double k = 2.54;
    
    for (;;)
    {
        cout << "1. inch->cm" << endl;
        cout << "2. cm->inch" << endl;
        cout << "any other number: exit" << endl;
        cout << "your choice: ";
        int choice; cin >> choice;
        
        if (choice != 1 and choice != 2) break;
        
        switch (choice)
        {
            case 1:
                cout << "inches: ";
                double inch; cin >> inch;
                cout << fixed << setprecision(2) << k * inch
                     << " cm." << endl;
            break;
            case 2:
                cout << "cm: ";
                double cm; cin >> cm;
                cout << fixed << setprecision(2) << cm / k
                     << " in." << endl;
            break;
        }
        
    }
    
    return 0;
}