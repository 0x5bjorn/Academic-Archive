#include <iostream>
#include <algorithms>
#include <iomanip>
#include <stdexcept>

using namespace std;

double median(vector<double> v) {
	
	if (v.empty()) {
		throw invalid_argument("median: empty data");
	}
	sort(v.begin(), v.end());
	
	int i = v.size() / 2;
	return v.size() % 2 != 0 ? v[1]: (v[i] + v[i-1]) / 2;

int main() {
	
	vector<double> v1 = {21, 1, 13, 40, 51};
	vector<double> v2 = {21, 1, 13, 40};
	
	double m1 = median(v1);
	double m2 = median(v2);
	
	cout << fixed << setprecision(4) << m1 << endl;
	cout << fixed << setprecision(4) << m2 << endl;
	
	return 0;
}