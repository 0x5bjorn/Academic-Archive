#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int r;
	int p, b, h, w; cin >> p >> b >> h >> w;
	
	while (h--) {
		
		vector<int> beds;
		int price; cin >> price;
		while (w--) {
			int bed; cin >> bed;
			beds.push_back(bed);
		}
		
		for (int n: beds) {
			if (p>=n) {
				r = price*=p;
				if (r>=b) {
					cout << r << endl;
				} else {
					cout << "stay home" << endl;
				}
			}
		}
	}

	return 0;
}