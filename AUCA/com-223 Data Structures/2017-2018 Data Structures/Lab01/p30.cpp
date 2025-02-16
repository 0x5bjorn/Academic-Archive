#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        int x;
        if (sinp >> x >> ws and sinp.eof())
        {
            cout << x << " + 1 = " << x + 1 << endl;
        }
        else
        {
            cout << line << ": incorrect int" << endl;
        }
    }
    return 0;
}