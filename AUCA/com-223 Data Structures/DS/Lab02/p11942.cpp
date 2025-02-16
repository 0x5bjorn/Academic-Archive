#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	cout << "Lumberjacks:" << endl;
	
	int t; cin >> t;
	while (t--) {
		
		vector<int> v;
		int a = 10;
		while (a--) {
			int l; cin >> l;
			v.push_back(l);
		}
		
		int check1 = 0;
		int check2 = 0;
		int temp = 0;
		
		for (int n: v) {
			if (temp!=0) {
				if (temp > n) check1=1;
				else 		  check2=1;
			}
			temp = n;			
		}
		
		if (check1 == check2) {
			cout << "Unordered" << endl;
		} else {
			cout << "Ordered" << endl;
		}
	}
	
	return 0;
}