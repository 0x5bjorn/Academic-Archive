#include <iostream>

#include "MapStrInt.h"

using namespace std;

int main()
{
    MapStrInt m;
    
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "print")
        {
            m.printInOrder();
        }
        else if (cmd == "find")
        {
            string key;
            cin >> key;
            auto p = m.find(key);
            if (p.first)
            {
                cout << key << " found. Value " << p.second << endl;
            }
            else
            {
                cout << key << " not found" << endl;
            }
        }
        else if (cmd == "update")
        {
            string key;
            cin >> key;
            int val;
            cin >> val;
            m[key] = val;
        }
        else if (cmd == "insert")
        {
            string key;
            cin >> key;
            int val;
            cin >> val;
            cout << (m.insert(key, val) ? "inserted" : " not inserted")
                 << endl;
        }
        else if (cmd == "erase")
        {
            string key;
            cin >> key;
            cout << (m.erase(key) ? "erased" : "not erased") << endl;
        }
    }
    
    return 0;
}