#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <iomanip>

using namespace std;

// size_t badHF(const string& s)
// {
    // return 42;
// }

int main()
{
    //typedef size_t (*HF)(const string&);
    //unordered_set<string, HF> names(2, badHF);
    
    unordered_set<string> names;
    
    auto hf = names.hash_function();
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        
        string cmd; sinp >> cmd;
        if (cmd == "#")
        {
            cout << "number of buckets: " << names.bucket_count() << endl;
            for (size_t i = 0; i < names.bucket_count(); ++i)
            {
                cout << setw(4) << i << ": ";
                for (auto it = names.begin(i); it != names.end(i); ++it)
                {
                    cout << *it << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else if (cmd == "+")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucket_count() << endl;
            cout << (names.insert(name).second ? "OK": "already exist") << endl;
        }
        else if (cmd == "-")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucket_count() << endl;
            cout << (names.erase(name) != 0 ? "OK": "does not exist") << endl;
        }
        else if (cmd == "?")
        {
            string name; sinp >> name;
            cout << "hash: " << hf(name) << endl;
            cout << "hash % size: " << hf(name) % names.bucket_count() << endl;
            auto it = names.find(name);
            cout << (it != names.end() ? "Found": "Not found") << endl;
        }
    }
    
    return 0;
}