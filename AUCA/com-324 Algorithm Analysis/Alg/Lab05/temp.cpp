#include <iosteram>
#include <functional>

using namespace std;

struct LessInt {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	
	LessInt cmp1;
	
	cout << boolalpha << cmp1(2, 3) << endl;
	
	return 0;
}