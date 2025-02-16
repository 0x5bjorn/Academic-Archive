#include <iostream>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		set<int> s;
		int number; cin >> number;
		int t = number;
		int res = 0;
		while (s.insert(number).second) {
			string numb = to_string(number);
			for (int k = 0; k < numb.length(); ++k) {
				res += (numb[k] - '0') * (numb[k] - '0');	
			}
			
			number = res;
			res = 0;
		}

		if (number == 1) cout << "Case #" << i << ": " << t << " is a Happy number." << endl;
		else 			 cout << "Case #" << i << ": " << t << " is an Unhappy number." << endl;
	}
	
	return 0;
}