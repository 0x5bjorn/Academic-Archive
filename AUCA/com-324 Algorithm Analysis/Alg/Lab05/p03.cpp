#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct Point {
	int x, y;
	
	Point(int aX, int aY) 
	: x(aX), y(aY)
	{
	}
};

struct CmpPoints {
	bool operator()(const Point& a, const Point& b) const {
		if (a.x < b.x) return true;
		if (a.x > b.x) return false;
		if (a.y < b.y) return true;
		if (a.y > b.y) return false;
		return false;
	}
};

typedef map<Point, vector<string>, CmpPoints> CachesMap;

void insertCache(CachesMap& caches, istringstream& sinp) {
	int x; sinp >> x;
	int y; sinp >> y;
	string item;
	while (sinp >> item) {
		caches[{x, y}].push_back(item);
	}
}

void eraseCache(CachesMap& caches, istringstream& sinp) {
	int x; sinp >> x;
	int y; sinp >> y;
	cout << (caches.erase({x, y}) == 1 ? "removed", "does not exist") << endl;
}

void checkCache(const CachesMap& caches, istringstream& sinp) {
	int x; sinp >> x;
	int y; sinp >> y;
	
	auto it = caches.find({x, y});
	if (it != caches.end()) {
		cout << "[ " 
		for (const auto& i: it->second) {
			cout << i << " ";
		}
		cout << "]";
	}
}

int main() {
	CachesMap caches;
	caches[{1, 2}].push_back("weapon1");
	
	string line;
	while (getLine(cin, line)) {
		istringstream sinp(line);
		
		string cmd; sinp >> cmd;
		if (cmd == "insert") {
			insertCache(caches, sinp);
		} else if (cmd == "erase") {
			eraseCache(caches, sinp);
		} else if (cmd == "check") {
			checkCache(caches, sinp);
		} else {
			cout << "Unknown command" << endl;
		}
	}
	
	return 0;
}