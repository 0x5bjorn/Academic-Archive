#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct Letter {
	char let;
	int freq;
	
	Letter(char aLet, int aFreq) 
	: let(aLet), freq(aFreq)
	{
	}
};

bool cmp(const Letter& a, const Letter& b) {
	if (a.freq == b.freq) return a.let > b.let;
	return a.freq<b.freq;
}

int main() {
	int t = 0;
	string line;
	while (getline(cin, line)) {
		if (t != 0) cout << endl;
		++t;
		
		vector<Letter> v;
		vector<int> counter(96, 0);
		for (int i = 0; i < line.length(); ++i) {
			++counter[line[i] - ' '];
		}
		
		for (int i = 0; i < counter.size(); ++i) {
			if (counter[i] != 0) v.push_back(Letter((char)(i+' '), counter[i]));
		}
		
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); ++i) {
			cout << (int)v[i].let << " " << v[i].freq << endl;
		}
	}
	
	return 0;
}