#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct Job {
	string jb;
	long long sal;	
	
	Job(string aJ, long long aSal)
	: jb(aJ), sal(aSal)
	{
	}
};

bool cmp(const Job& a, const Job& b) {
	return a.jb < b.jb;
}

int main() {
	int m, n; cin >> m >> n;
	vector<Job> v;
	while (m--) {
		string j; cin >> j;
		long long sal; cin >> sal;
		v.push_back(Job(j, sal));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	while (n--) {
		string text;
		long long sum = 0;
		while (cin >> text) {
			if (text == ".") break;
			Job b{text, 0};
			if (binary_search(v.begin(), v.end(), b, cmp)) {
				for (int i = 0; i<v.size(); ++i) {
					if (text == v[i].jb) sum += v[i].sal;					
				}
			}
		}		
		
		cout << sum << endl;
	}
	
	return 0;
}