#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	unordered_map<int, int> m;
	vector<int> v;
	int n;
	while (cin >> n) {
		if (m[n] == 0) {
			++m[n]; 
			v.push_back(n);
		} else {
			++m[n];
		}
	}

	for (int i = 0; i<v.size(); ++i) {
		cout << v[i] << " " << m[v[i]] << endl;
	}

	return 0;
}