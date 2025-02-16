#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
	
	Node(int aData, Node* aPrev, Node* aNext)
	: data(aData), prev(aPrev), next(aNext)
	{
	}
	
	// ~Node() {
		// delete[] data;
		// prev = nullptr;
		// next = nullptr;
	// }
};

void pushBack(Node*& head, Node*& tail, int elem) {
	if (head == nullptr) {
		head = tail = new Node(elem, nullptr, nullptr);
	} else {
		tail = tail->next = new Node(elem, tail, nullptr);
	}
}

void printInDirectOrder(Node* head, Node* tail) {
	for (Node* p = head; p != nullptr; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}

void printInReverseOrder(Node* head, Node* tail) {
	for (Node* p = tail; p != nullptr; p = p->prev) {
		cout << p->data << " ";
	}
	cout << endl;
}

void insertBefore(Node*& head, Node* curr, int elem) {
	if (curr = head) {
		Node* t = new Node(elem, nullptr, head);
		head->prev = t;
		head = t;
		
	//	head = new Node(elem, nullptr, head);
	//	head->next->prev = head;
	} else {
		Node* t = new Node(elem, curr->prev, curr);
		curr->prev->next = t;
		curr->prev = t;
		
	// curr->prev->next = new Node(elem, curr->prev, curr);
	// curr-> = ;
	}
}

Node* erase(Node*& head, Node*& tail, Node* curr) {
	if (head == curr && head == tail) {
		delete curr;
		head = tail = nullptr;
		return nullptr;
	}
	if (head == curr) {
		Node* t = head->next;
		delete head;
		head = t;
		head->prev = nullptr;
		return head;
		
		//head->next->prev = nullptr;
	}
	if (tail == curr) {
		Node* t = tail->prev;
		delete tail;
		tail = t;
		tail->next = nullptr;
		return nullptr;
	}
	
	Node* t = curr->next;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
	return t;
}

void destroy(Node*& head, Node*& tail) {
	Node* p = head;
	while(p) {
		Node* t = p;
		p = p->next;
		delete t;
	}
	
	head = nullptr;
	tail = nullptr;
}

// void destroy(Node*& head, Node*& tail) {
	// Node* p = head;
	// while(p != nullptr) {
		// p = erase(head, tail, p);
	// }
	// head = tail = nullptr;
// }

int main() {
	
	Node* head = nullptr;
	Node* tail = nullptr;
	
	int x;
	while (cin >> x) {
		pushBack(head, tail, x);
	}
	
	printInDirectOrder(head, tail);
	printInReverseOrder(head, tail);
	
	for (Node* p = head; p != nullptr; p = p->next) {
		if (p->data % 2 == 0) {
			insertBefore(head, p, 0);
		}
	}
	
	printInDirectOrder(head, tail);
	printInReverseOrder(head, tail);
	
	Node* p = head;
	while(p != nullptr) {
		if (p->data % 2 == 0) {
			p = erase(head, tail, p);
		} else {
			p = p->next;
		}
	}
	
	printInDirectOrder(head, tail);
	printInReverseOrder(head, tail);
	
	destroy(head, tail);
	printInDirectOrder(head, tail);
	printInReverseOrder(head, tail);
	
	return 0;
}