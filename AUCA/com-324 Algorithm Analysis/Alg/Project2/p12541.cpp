#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct BirthDate {
	string name;
	int day;
	
	BirthDate(string aName, int aDay)
	: name(aName), day(aDay)
	{
	}
	
	bool operator<(const BirthDate other) {
		return day<other.day;
	}
};

int main() {
	vector<BirthDate> v;
	int t; cin >> t;
	while (t--) {
		string name; cin >> name;
		int d, m, y; cin >> d >> m >> y;	
		v.push_back(BirthDate(name, d+m*31+y*365));
	}
	
	auto young = max_element(v.begin(), v.end());
	auto old = min_element(v.begin(), v.end());
	
	cout << young->name << endl;
	cout << old->name << endl;
	
	return 0;
}