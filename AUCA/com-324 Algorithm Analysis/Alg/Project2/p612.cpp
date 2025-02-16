#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DNA {
	string sdna;
	int sortedness;
	
	DNA(string aSdna, int aSortedness)
	: sdna(aSdna), sortedness(aSortedness)
	{
	}
};

bool cmp(const DNA& a, const DNA& b) {
	return a.sortedness<b.sortedness;
}

int main() {
	int t; cin >> t;
	while (t--) {
		vector<DNA> v;
		int n, m; cin >> n >> m;
		while (m--) {
			int i = 0;
			int sortedness = 0;
			string s; cin >> s;
			for (int i = 0; i<s.length(); ++i) {
				for (int j = i+1; j<s.length(); ++j) {
					if (s[i] > s[j]) ++sortedness;
				}
			}
			v.push_back(DNA(s, sortedness));
		}
		
		stable_sort(v.begin(), v.end(), cmp);
		
		for (int i = 0; i<v.size(); ++i) {
			cout << v[i].sdna << endl;
		}
		
		if (t!=0) cout << endl;
	}
		
	return 0;
}