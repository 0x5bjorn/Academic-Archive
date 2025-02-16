#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(lst) {
	
	// for (list<int>::iterator it = v.begin(); it != v.end(); ++it) {
		// cout << *it << " ";
	// }
	// cout << endl:
	
	for (int e: lst) {
		cout << e << " ";
	}
	cout << endl;
}

void printInReverseOrder(lst) {
	
	// for (list<int>::const_reverse_ it = v.begin(); it != v.end(); ++it) {
		// cout << *it << " ";
	// }
	// cout << endl:
	
	
	for (auto it2 = lst.rbegin(); it2 != lst.rend(); ++it2) {
		cout << *it2 << " ";
	}
	cout << endl;
}

int main() {
	
	list<int> lst;
	int x;
	while (cin >> x) {
		lst.push_back(x);
	}
	
	printInDirectOrder(lst);
	printInReverseOrder(lst);

	auto it = lst.begin();
	while (it != lst.end()) {
		if (*it % 2 == 0) {
			it = lst.insert(it, 0);
			++it;
		}
		++it;
	}	
	
	printInDirectOrder(lst);
	printInReverseOrder(lst);
	
	it = lst.begin();
	while (it != lst.end()) {
		if (*it % 2 == 0) {
			it = lst.erase(it);
		} else {
			++it;
		}
	}	
	
	printInDirectOrder(lst);
	printInReverseOrder(lst);
	
	return 0;
}