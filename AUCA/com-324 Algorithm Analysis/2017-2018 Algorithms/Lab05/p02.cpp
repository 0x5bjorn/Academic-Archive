#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    map<string, set<int>> m;
    
    int numOfLine = 0;
    string line;
    while (getline(cin, line))
    {
        ++numOfLine;
        istringstream sinp(line);
        string word;
        while (sinp >> word)
        {
            m[word].insert(numOfLine);
        }
    }
    
    for (const auto& p: m)
    {
        cout << p.first << ":";
        for (auto v: p.second)
        {
            cout << " " << v;
        }
        cout << endl;
    }
    
    return 0;
}