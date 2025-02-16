#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Word {
	string s;
	string an;	
	
	Word(string aS, string aAn)
	: s(aS), an(aAn)
	{
	}
};

bool cmp(const Word& a, const Word& b) {
	return a.an < b.an;
}

int main() {	
	string s;
	vector<Word> v;
	while(cin >> s) {
		if(s == "#") break;
		
		string an;
		for(int i = 0; i < s.size(); ++i) {
			an += tolower(s[i]);
		}
		sort(an.begin(), an.end());
		
		v.push_back(Word(s, an));
	}

	sort(v.begin(), v.end(), cmp);
	vector<string> str;
	for(int i = 0; i < v.size(); ++i) {
		auto it = equal_range(v.begin(), v.end(), v[i], cmp);
		int up = it.first - v.begin();
		int down = it.second - v.begin();
		if(down - up == 1) str.push_back(v[i].s);
	}
	
	sort(str.begin(), str.end());
	for(auto e : str)
	{
		cout << e << endl;
	}
	
	return 0;
}