#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
	
	cout << "number of points: ";
	int p; cin >> p;
	
	char g;
	if (100 < p) {
		g = 0;
	}
	else if (80 <= p) {
		g = 'A';
	}
	else if (60 <= p) {
		g = 'B';
	}
	else if (40 <= p){
		g = 'C';
	}
	else if (20 <= p){
		g = 'D';
	}
	else if (0 <= p){
		g = 'F';
	}
	else {
		g = 0;
	}
	
	if (g != 0) {
		cout << "Your grade: " << g << endl;
	}
	else {
		cout << "Incorrect data" << endl;
	}
	
	return 0;
}






