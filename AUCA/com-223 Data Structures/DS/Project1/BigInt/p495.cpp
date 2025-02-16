#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

class BigInt {
	
	friend std::ostream& operator<<(ostream& out, const BigInt& a);
	friend std::istream& operator>>(istream& inp, BigInt& a);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
	
	private:
	
	public:
	deque<int> digits;
	
	BigInt(const string& n = "0");	
};

BigInt::BigInt(const string& n) {
	
	for (int i = 0; i<n.size(); ++i) {
		char ch = n[i];
		digits.push_back(ch - '0');
	}
}

ostream& operator<<(ostream& out, const BigInt& a) {
	
	for (int i = 0; i < a.digits.size(); ++i) {
		out << a.digits[i];
	}
		
    return out;
}

istream& operator>>(istream& inp, BigInt& a) {
	
    string n;
    
    if (inp >> n) {
		
        BigInt t(n);
		a = t;
		
    } else {
        inp.setstate(ios::failbit);
    }
    
    return inp;
}

BigInt operator+(const BigInt& a, const BigInt& b) {
	
	BigInt r;
	r.digits.erase(r.digits.begin());

		int i = a.digits.size() - 1;
		int j = b.digits.size() - 1;

		int carry = 0;
		while (i > -1 or j > -1 or carry != 0) {
			
			int s = carry;
			if (i > -1) {
				s += a.digits[i];
				--i;
			}
			if (j > -1) {
				s += b.digits[j];
				--j;
			}
			carry = s / 10;
			int d = s % 10;
			r.digits.push_front(d);
		}
	
	return r;
}

int main() {
	
	deque<BigInt> d(5001);
	d[0] = to_string(0);
	d[1] = to_string(1);
	for (int i = 2; i<d.size(); ++i) {
		d[i] = d[i-1] + d[i-2];
	}
	
	int a;
	while (cin >> a) {
		cout << "The Fibonacci number for " << a << " is " << d[a] << endl;
	}
	
	return 0;
}
