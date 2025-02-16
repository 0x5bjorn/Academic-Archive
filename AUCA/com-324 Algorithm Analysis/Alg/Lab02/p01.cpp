#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<int> v;
	int x;
	while (cin >> x) {
		v.push_back(x);
	}
	
	reverse(v.begin(), v.end());
	
	for (auto e: v) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}
