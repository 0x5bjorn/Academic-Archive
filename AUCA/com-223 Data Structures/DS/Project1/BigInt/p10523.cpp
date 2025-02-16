#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

class BigInt {
	
	friend std::ostream& operator<<(ostream& out, const BigInt& a);
	friend std::istream& operator>>(istream& inp, BigInt& a);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
	friend BigInt operator*(const BigInt& a, const BigInt& b);
	
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

BigInt operator*(const BigInt& a, const BigInt& b) {
	BigInt r;
	r.digits.erase(r.digits.begin());
	
	int i = a.digits.size() - 1;
	int j = b.digits.size() - 1;
	int counter = 0;

	while (j > -1) {
		BigInt t;
		t.digits.erase(t.digits.begin());
		int carry = 0;

		for (int k = 0; k < counter; ++k) {
			t.digits.push_back(0);
		}

		while (i > -1) {
			int s = 1;

			s = a.digits[i] * b.digits[j] + carry;
			--i;
			
			carry = s / 10;
			int d = s % 10;
			t.digits.push_front(d);
			if (i < 0) t.digits.push_front(carry);
		}
		
		r = r + t;
		--j;
		i = a.digits.size() - 1;
		++counter;
	} 
		
	while (r.digits.front() == 0 and r.digits.size() > 1) {
		r.digits.pop_front();
	}
	
	return r;
}

int main() {
	
	BigInt r;
	int n;
	BigInt a;
	while (cin >> n >> a) {
		
		BigInt s;
		for (int i = 1; i<=n; ++i) {
			s = to_string(i);
			for (int j = 0; j<i; ++j) {
				s = s*a;
			}
			r = r + s;
		}
		
		cout << r << endl;
		r = to_string(0);
	}
	
	return 0;
}

