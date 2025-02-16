#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	string set1;
	string set2;
	while (getline(cin, set1) and getline(cin, set2)) {
		vector<int> v1;
		vector<int> v2;
		int counter = 0;
		
		istringstream sinp1(set1);
		int n1;
		while (sinp1 >> n1) {
			if (not binary_search(v1.begin(), v1.end(), n1)) v1.push_back(n1);
		}
		
		sort(v1.begin(), v1.end());
		
		istringstream sinp2(set2);
		int n2;
		while (sinp2 >> n2) {
			if (not binary_search(v2.begin(), v2.end(), n2)) {
				v2.push_back(n2);
				if (binary_search(v1.begin(), v1.end(), n2)) ++counter;
			}
		}
		
		if 		(counter == v1.size() and v2.size() == v1.size()) cout << "A equals B" << endl;
		else if (counter < v1.size() and counter == v2.size())    cout << "B is a proper subset of A" << endl;
		else if (counter < v2.size() and counter == v1.size())    cout << "A is a proper subset of B" << endl;
		else if (counter == 0)		   							  cout << "A and B are disjoint" << endl;
		else if (counter < v1.size() and counter < v2.size())     cout << "I'm confused!" << endl;
	}
		
	return 0;
}