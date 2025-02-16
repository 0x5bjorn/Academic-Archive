#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	
	cout << "size of table: ";
	int n; cin >> n;
	
	//int w = to_string(n*n).size() + 1;
	
	ostringstream sout;
	cout << n * n;
	int w = sout.str().size();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << setw(w) << (i*j);
		}				
		cout << endl;
	}
	
	return 0;
}