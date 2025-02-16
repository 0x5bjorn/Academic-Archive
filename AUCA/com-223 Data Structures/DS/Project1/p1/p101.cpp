#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class RobotWorld {
	
	friend std::ostream& operator<<(ostream& out, const RobotWorld& a);
	friend std::istream& operator>>(istream& inp, const RobotWorld& a);
	void moveOnto(const int& a, const int& b);
	void moveOver(const int& a, const int& b);
	void pileOnto(const int& a, const int& b);
	void pileOver(const int& a, const int& b);
	
	private:
	
	public:

	vector<vector<int>> v;

	RobotWorld()
	: n(1)
	{
		
	}
	
	RobotWorld (const int& n);
};

RobotWorld::RobotWorld(const int& n) {
    
	vector<int> a(n);
	
	for (int i = 0; i<10; ++i) {
		a[0] = i;
		v.push_back(a);
	}
}

int main() {
	
	RobotWorld n; cin >> n;

	while (n--) {
		
		string line;
		while (getline(cin, line))
		{
			istringstream sinp(line);
			string ac1; sinp >> ac1;
			int a; sinp >> a;
			string ac2; sinp >> ac2;
			int b; sinp >> b;
				
			 if (ac1 == "quit") {
				break;
			} else if (ac1 == "move") {
				if (ac2 == "onto") {
					n.moveOnto(a, b);
				} else if (ac2 == "over") {
					n.moveOver(a, b);
				}
			} else if (ac1 == "pile") {
				if (ac2 == "onto") {
					n.pileOnto(a, b);
				} else if (ac2 == "over") {
					n.pileOver(a, b);
				} 
			}

		return 0;
	}
}

ostream& operator<<(ostream& out, const RobotWorld& a) {
	
    return out << a.r;
}

istream& operator>>(istream& inp, RobotWorld& a) {
	
    int n;
    
    if (inp >> n) {
		
        BigInt t(n);
		a = t;
		
    } else {
        inp.setstate(ios::failbit);
    }
    
    return inp;
}

void moveOnto(a, b) {
	
	RobotWorld *p = &;
	
}

void moveOver(a, b) {
	
}

void pileOnto(a, b) {
	
}

void pileOver(a, b) {
	
}
