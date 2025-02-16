#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    
    cout << "size of vector: " << sizeof(v) << endl;

    //v.reserve(2048);
    
    const int n = 1000;
    
    for (int i = 0; i < n; ++i)
    {
        cout << "size: " << v.size() << endl;
        cout << "capacity: " << v.capacity() << endl;
        v.push_back(i);
    }
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
        
    return 0;
}