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
};

void pushBack(Node*& head, Node*& tail, int elem) {
	if (head == nullptr) {
		head = tail = new Node(elem, nullptr, nullptr);
	} else {
		tail->next = new Node(elem, tail, nullptr);
		tail = tail->next;
	}
}

void printInDirOrder(Node* head, Node* tail) {
	for (Node* p = head; p!= nullptr; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}

void printInDirOrder(Node* head, Node* tail) {
	for (Node* p = tail; p!= nullptr; p = p->prev) {
		cout << p->data << " ";
	}
	cout << endl;
}

void insertBefore(Node*& head, Node* curr, int elem) {
	if (head == curr) {
		Node* t = new Node(elem, nullptr, head);
		head->prev = t;
		head = t;
	} else {
		Node* t = new Node(elem, curr->prev, curr);
		curr->prev->next = t;
		curr->prev = t;
	}
}

Node* erase(Node*& head, Node*& tail, Node* curr) {
	if (head == curr && curr == tail) {
		delete curr;
		return nullptr;
	} 
	if (curr == head) {
		Node* t = head->next;
		delete head;
		head = t;
		head->prev = nullptr;
		return head;
	}
	
	if (curr == tail) {
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
	while (p) {
		Node* t = p;
		p = p->next;
		delete t;
	}
	
	head = tail = nullptr;
}

int main() {
	
	
	
	return 0;
}