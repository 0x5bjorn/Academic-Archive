#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int findColumn(int n);
int findRow(int n);
bool isStop(int cK, int rK, int cPQ, int rPQ);
bool isIllegalMove(int cK, int rK, int cQ, int rQ, int cPQ, int rPQ);
bool isNotAllowed(int cK, int rK, int cPQ, int rPQ);

int main() {
	
	int k, q, pq;
	while (cin >> k >> q >> pq) {
		int cK = findColumn(k);
		int rK = findRow(k);
		
		int cQ = findColumn(q);
		int rQ = findRow(q);
		
		int cPQ = findColumn(pq);
		int rPQ = findRow(pq);
		
		if (k==q) {
			cout << "Illegal state" << endl;
		} else {
			if (isStop(cK, rK, cPQ, rPQ)) {
				cout << "Stop" << endl;
			} else if (isIllegalMove(cK, rK, cQ, rQ, cPQ, rPQ)) {
				cout << "Illegal move" << endl;
			} else if (isNotAllowed(cK, rK, cPQ, rPQ)) {
				cout << "Move not allowed" << endl;
			} else {
				cout << "Continue" << endl;
			}
		}
	}
	
	return 0;
}

bool isStop(int cK, int rK, int cPQ, int rPQ) {
	
	bool r = false;
	if (((cK==0 and rK==0) and (cPQ==1 and rPQ==1)) or 
		((cK==0 and rK==7) and (cPQ==1 and rPQ==6)) or 
		((cK==7 and rK==0) and (cPQ==6 and rPQ==1)) or
		((cK==7 and rK==7) and (cPQ==6 and rPQ==6))) {
		r = true;
	} else r = false;
	
	return r;
}

bool isIllegalMove(int cK, int rK, int cQ, int rQ, int cPQ, int rPQ) {
	
	bool r = false;
	if ((cPQ>cQ and rPQ>rQ) or (cPQ>cQ and rPQ<rQ) or 
		(cPQ<cQ and rPQ>rQ) or (cPQ<cQ and rPQ<rQ)) {
		r = true;
	} else if ((cPQ==cQ and rPQ==rQ) or (cPQ==cK and rPQ==rK)) {
		r = true;
	} else if ((cPQ==cK and rQ>rK and rK>rPQ) or 
			   (cPQ==cK and rQ<rK and rK<rPQ) or 
			   (rPQ==rK and cQ>cK and cK>cPQ) or 
			   (rPQ==rK and cQ<cK and cK<cPQ)) {
			r = true;
	} else r = false;
	
	return r;
}

bool isNotAllowed(int cK, int rK, int cPQ, int rPQ) {
	
	bool r = false;
	if ((cPQ==cK+1 and rPQ==rK) or 
		(cPQ==cK and rPQ==rK+1) or 
		(cPQ==cK-1 and rPQ==rK) or
		(cPQ==cK and rPQ==rK-1)) {
		r = true;
	} else r = false;
	
	return r;
}


int findColumn(int n) {
	int r = 0;
	r = n%8;
	return r;
}

int findRow(int n) {
	int r = 0;
	r = n/8;
	return r;
}