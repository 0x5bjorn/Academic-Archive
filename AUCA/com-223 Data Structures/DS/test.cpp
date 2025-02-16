#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>	
#include <vector>
#include <string>
#include <cctype>
#include <sstream>


using namespace std;

int main() {
	
	vector< vector<int> > v;
	vector<int> a(10);
	
	for (int i = 0; i<10; ++i) {
		a[0] = i;
		v.push_back(a);
	}
	
	for (int i = 0; i<10; ++i) {
		for (int j = 0; j<10; ++j) {
			cout << v[i][j];
		}
		cout << endl;
	}
}
