#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	while (true) {
		int k, m; cin >> k >> m;
		if (k == 0) break;
		
		bool check = true;
		vector<int> v;
		while (k--) {
			int course; cin >> course;
			v.push_back(course);
		}
		
		sort(v.begin(), v.end());
		
		while (m--) {
			int c, r; cin >> c >> r;
			while (c--) {
				int catCourse; cin >> catCourse;
				if (binary_search(v.begin(), v.end(), catCourse)) --r;
			}
			
			if (r>0) check = false;
		}
		
		if (check) cout << "yes" << endl;
		else 	   cout << "no" << endl;
	}
	
	return 0;
}