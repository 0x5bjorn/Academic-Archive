#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int aX = 0, int aY = 0)
    : x(aX), y(aY)
    {
    }
};

struct CmpPoints
{
    bool operator()(const Point& a, const Point& b) const
    {
        if (a.x < b.x)
            return true;
        if (a.x > b.x)
            return false;
        if (a.y < b.y)
            return true;
        if (a.y > b.y)
            return false;
        return false;
    }
};

typedef map<Point, vector<string>, CmpPoints> CacheMap;

void addCache(CacheMap& m)
{
    string line;
    getline(cin, line);
    
    istringstream sinp(line);
    int x; sinp >> x;
    int y; sinp >> y;
    string item;
    while (sinp >> item)
    {
        m[{x, y}].push_back(item);
    }
}

void removeCache(CacheMap& m)
{
    string line;
    getline(cin, line);
    
    istringstream sinp(line);
    int x; sinp >> x;
    int y; sinp >> y;
    cout << (m.erase({x, y}) ? "removed": "doesn't exist")
         << endl;
}

void checkCache(const CacheMap& m)
{
    string line;
    getline(cin, line);
    
    istringstream sinp(line);
    int x; sinp >> x;
    int y; sinp >> y;
    auto it = m.find({x, y});
    if (it != m.end())
    {
        cout << "Found: ";
        for (const auto& item: it->second)
        {
            cout << " " << item;
        }
        cout << endl;
    }
}

void printCaches(const CacheMap& m)
{
    for (const auto& p: m)
    {
        cout << "(" << p.first.x << ", " << p.first.y << ")";
        cout << "{";
        for (const auto& s: p.second)
        {
            cout << " " << s;
        }
        cout << "}" << endl;
    }
}

int main()
{
    CacheMap caches;
    
    string cmd;
    while (getline(cin, cmd))
    {
        if (cmd == "insert")
        {
            addCache(caches);
        }
        else if (cmd == "erase")
        {
            removeCache(caches);
        }
        else if (cmd == "check")
        {
            checkCache(caches);
        }
        else if (cmd == "print")
        {
            printCaches(caches);
        }
    }
    
    return 0;
}