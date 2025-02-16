#include <iostream>
#include <vector>

#include "algol.h"

using namespace std;
bool isEven(int n)
{
	return n % 2 == 0;
}

struct IsEven
{
	bool operator()(int n)
	{
		return n % 2 == 0;
	}
};

int main()
{
	vector<int> v = {3, 1, 2, 5, 4};

	auto it1 = auFindIf(v.begin(), v.end(), isEven);
	if (it1 != v.end())
	{
		cout << "found: " << *it1 << endl;
	}
	else
	{
		cout << "even number not found" << endl;
	}
	
	auto it2 = auFindIf(v.begin(), v.end(), IsEven());
	if (it2 != v.end())
	{
		cout << "found: " << *it2 << endl;
	}
	else
	{
		cout << "even number not found" << endl;
	}
	
	auto it3 = auFindIf(v.begin(), v.end(), 
				       [](int n) {return n % 2 == 0;});
				
	if (it3 != v.end())
	{
		cout << "found: " << *it3 << endl;
	}
	else
	{
		cout << "even number not found" << endl;
	}
	
	return 0;
}