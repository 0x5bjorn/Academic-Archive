#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "HashSetStr.h"

using namespace std;

size_t goodHF(const string& s)
{
    size_t r = 97;
    
    for (char c: s)
    {
        r = r * 257 + c * 31;
    }
    
    return r;
}

int main()
{   
    HashSetStr names(goodHF);
    
    auto hf = names.getHashFunc();
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        
        string cmd; sinp >> cmd;
        if (cmd == "#")
        {
            cout << "number of buckets: " << names.bucketCount() << endl;
            names.print();
        }
        else if (cmd == "+")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
            cout << (names.insert(name) ? "OK": "already exist") << endl;
        }
        else if (cmd == "-")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
            cout << (names.erase(name) ? "OK": "does not exist") << endl;
        }
        else if (cmd == "?")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
            cout << (names.find(name) ? "Found": "Not found") << endl;
        }
    }
    
    return 0;
}