#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 1; i<=t; ++i) {
		unordered_map<string, int> m;
		int n; cin >> n;
		while (n--) {
			string subj; int nD; cin >> subj >> nD;
			m[subj] = nD;
		}
		int d; cin >> d;
		string dueSubj; cin >> dueSubj;
	
		if 		(m[dueSubj] == 0 or m[dueSubj] > d+5)	cout << "Case " << i << ": Do your own homework!" << endl;
		else if (m[dueSubj] <= d) 						cout << "Case " << i << ": Yesss" << endl;
		else if (m[dueSubj] > d and m[dueSubj] <= d+5)  cout << "Case " << i << ": Late" << endl;
	
	}
	
	return 0;
}