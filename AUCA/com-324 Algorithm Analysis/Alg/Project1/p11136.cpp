#include <iostream>
#include <set>

using namespace std;

int main() {
	size_t t;
	while (cin >> t) {
		if (t == 0) break;
		
	    size_t res = 0;
	    multiset<size_t> ms;
    	while (t--) {
    		size_t n; cin >> n;
    		while (n--) {
    			size_t b; cin >> b;
    			ms.insert(b);
    		}
			auto beg = ms.begin();
			auto end = --ms.end();
    		res += *end - *beg;
			ms.erase(beg);
			ms.erase(end);
    	}
    	cout << res << endl;
	}
	
	return 0;
}