#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Region {
	char letter;
	int amount;
	
	Region(char aLetter, int aAmount)
	: letter(aLetter), amount(aAmount)
	{
	}
	
	bool operator<(const Region other) {
		return amount<other.amount;
	}
};

int main() {
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		int res = 0;
		int r, c, m, n; cin >> r >> c >> m >> n;
		vector<int> counter(26, 0);
		vector<Region> v;
		while (r--) {
			string s; cin >> s;
			for (int i = 0; i < s.length(); ++i) {
				++counter[s[i] - 'A'];
			}
		}
		
		for (int i = 0; i < counter.size(); ++i) {
			v.push_back(Region((char)(i+'A'), counter[i]));
		}
		
		sort(v.begin(), v.end());
		auto iter = --v.end();
		int max = iter->amount;
		
		for (auto it = v.rbegin(); it != v.rend(); ++it) {
			if (it->amount == max) res += it->amount*m;
			else 				   res += it->amount*n;
		}
		
		cout << "Case " << k << ": " << res << endl; 
	}
	
	return 0;
}