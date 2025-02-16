#include <iostream>
#include "MapStrInt.h"

using namespace std;

void MapStrInt::print() const {
	
	
	cout << "size: " << length << endl;
}

int& MapStrInt::operator[](const string& k) {
	++length;
	
	bool isLeft = false;
	
	Node* p = root;
	Node* q = nullptr;
	while (p) {
		q = p;
		if (k < p->data.first) {
			isLeft = true;
			p=p->lft;
		} else if (k > p->data.first) {
			isLeft = true;
			p=p->rgt;
		} else {
			return p->data.second;
		}
	}
	
	Node* t = new Node(k, 0, nullptr, nullptr);
	
	if (q == nullptr) {
		root = t;
		return root->data.second;
	}
	
	if (isLeft) {
		q->lft = t;
	} else {
		q->rgt = t;
	}
	
	return t->data.second;
}