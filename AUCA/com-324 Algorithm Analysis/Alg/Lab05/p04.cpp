#include <iostream>
#include <string>
#include "MapStrInt.h"

using namespace std;

int main() {
	
	MapStrInt m;
	
	string w;
	while(cin >> w) {
		++m[w];
	}
	
	m.print();
	
	return 0;
}