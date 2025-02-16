#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string name; sinp >> name;
        int sum = 0;
        int g;
        while (sinp >> g)
        {
            sum += g;
        }
        cout << name << ": " << sum << endl;
    }
    
    return 0;
}