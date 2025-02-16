#include <iostream>
#include <vector>
#include <list>

#include "algol.h"

using namespace std;

int main()
{
	int a[] = {1, 0, 2, 3, 4};
	vector<int> v = {1, 2, 3, 4, 5};
	list<int> w = {2, 0, -3, 4, 10};
	
	auto it1 = auFind(a, a + 5, 3);
	if (it1 != a + 5)
	{
		cout << 3 << " found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	
	auto it2 = auFind(v.begin(), v.end(), 3);
	if (it2 != v.end())
	{
		cout << 3 << " found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	
	auto it3 = auFind(w.begin(), w.end(), 3);
	if (it3 != w.end())
	{
		cout << 3 << " found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	
}