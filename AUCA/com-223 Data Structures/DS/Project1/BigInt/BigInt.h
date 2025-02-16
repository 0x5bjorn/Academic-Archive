#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>

class BigInt {
	
	friend std::ostream& operator<<(ostream& out, const BigInt& a);
	friend std::istream& operator>>(istream& inp, BigInt& a);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
	friend BigInt operator-(const BigInt& a, const BigInt& b);
	friend BigInt operator*(const BigInt& a, const BigInt& b);
	friend BigInt operator/(const BigInt& a, const BigInt& b);
	friend BigInt operator%(const BigInt& a, const BigInt& b);
	
	private:

	public:
	
	deque<int> digits;	
	BigInt(const string& n);	
};

#endif