#include <stdexcept>
#include <sstream>

#include "BigInt.h"

using namespace std;

BigInt::BigInt(const string& n) {
    
	for (int i = 0; i<n.size(); ++i) {
		
		if (isalpha(n.at(i))) {
			throw std::runtime_error("incorrect BigInt: " + n);
		}
		
		digits.push(n.at(i) - '0');
	}	
}

ostream& operator<<(ostream& out, const BigInt& a) {
	
	string r;
	for (int i = 0; i < a.digits.size(); ++i) {
		r+=a.digits[i];
	}
		
    return out << r;
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
	r.digits.pop_back();

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
			r.digits.push(d);
		}
	
	return BigInt r;
}

BigInt operator-(const BigInt& a, const BigInt& b) {
	
	BigInt r;
	r.digits.pop_back();
	
	int i = a.digits.size() - 1;
	int j = b.digits.size() - 1;
	
	int carry = 0;
		while (i > -1 or j > -1 or carry != 0) {
			
			int s = 0;
			if (i > -1) {
				s -= a.digits[i] - carry;
				--i;
			}
			if (j > -1) {
				s += b.digits[j];
				--j;
			}
			
			if (s < 0) {
				s += 10;
				carry = 1;
			} else
				carry = 0;

			int d = s % 10;
			r.digits.push(d);
		}
	
	return BigInt r;
}

BigInt operator*(const BigInt& a, const BigInt& b) {
	BigInt r;
	r.digits.pop_back();
	
	int i = a.digits.size() - 1;
	int j = b.digits.size() - 1;
	int c = 0;

	while (j > -1) {
		BigInt t;
		t.digits.pop_back();
		int carry = 0;

		for (int k = 0; k < c; ++k) {
			t.digits.push(0);
		}

		while (i > -1) {
			int s = 1;

			s = a.digits[i] * b.digits[j] + carry;
			--i;
			
			carry = s / 10;
			int d = s % 10;
			t.digits.push(d);
			if (i < 0) t.digits.push(carry);
		}
		
		r = r + t;
		--j;
		i = a.digits.size() - 1;
		++c;
	} 
		
	while (r.digits.front == 0 && r.digits.size() > 1) {
		r.digits.pop_front();
	}
	
	return r;
}

BigInt operator/(const BigInt& a, const BigInt& b) {
}

BigInt operator%(const BigInt& a, const BigInt& b) {
}
