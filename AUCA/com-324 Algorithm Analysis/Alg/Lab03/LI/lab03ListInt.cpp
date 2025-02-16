#include <iostream>

using namespace std;

class ListInt {
	
	private:
	struct Node {
		int data;
		Node* prev;
		Node* next;
		
		Node(int aData, Node* aPrev, Node* aNext) 
		: data(aData), prev(aPrev), next(aNext)
		{	
		}
	};
	
	Node* head;
	Node* tail;
	int length;
	
	public:
	
	class Iter {
		friend class ListInt;
		
		private:
		Node* p;
		
		public:
		
		Iter()
		: p(nullptr) {
			
		}
		
		Iter& operator++() {
			p = p->next;
			return *this;
		}
		
		Iter& operator--() {
			p = p->prev;
			return *this;
		}
		
		int* operator*() {
			return p->data;
		}
		
		bool operator==(Iter other) {
			return p == other.p;
		}
		
		bool operator!=(Iter other) {
			return !(*this == other);
		}
	};
	
	class RIter {
		friend class ListInt;
		
		private:
		Node* p;
		
		public:
		
		RIter()
		: p(nullptr) {
			
		}
		
		RIter& operator--() {
			p = p->next;
			return *this;
		}
		
		RIter& operator++() {
			p = p->prev;
			return *this;
		}
		
		int* operator*() {
			return p->data;
		}
		
		bool operator==(RIter other) {
			return p == other.p;
		}
		
		bool operator!=(RIter other) {
			return !(*this == other);
		}
	};
	
	ListInt()
	: length(0) 
	{
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, head, nullptr);
		head->next=tail;
	}
	
	ListInt(const ListInt& other)
	: length(other.length) 
	{
		head = other.head;
		tail = other.tail;
		for (Node* p = other.head->next; p != nullptr; p=p->next) {
			
		}
	}
	
	~ListInt() {
		delete head;
		delete tail;
	}
	
	Iter begin() {
		Iter it;
		it.p = head->next;
		
		return it;
	}
	
	Iter end() {
		Iter it;
		it.p = tail;
		
		return it;
	}
	
	RIter rbegin() {
		RIter it;
		it.p = tail->prev;
		
		return it;
	}
	
	RIter rend() {
		RIter it;
		it.p = head;
		
		return it;
	}
	
	int size() {
		return length;
	}
	
	void pushBack(int elem) {
		insert(tail, elem);
	}
	
	void popBack() {
		erase(tail->prev);
	}
	
	void pushFront(int elem) {
		insert(head, elem);
	}
	
	void popFront() {
		erase(head->next);
	}
	
	Iter insert(Iter pos, int elem) {
		Iter res;
		res.p = insert(pos.p, elem);
		
		return res;
	}
	
	Iter erase(Iter pos) {
		Iter res;
		res.p = erase(pos.p);
		
		return res;
	}
	
	private:
	
	Node* insert(Node* p, int elem) {
		Node* t = new Node(elem, p->prev, p);
		p->prev->next = t;
		p->prev = t;
		++length;
		
		return p;
	}
	
	Node* erase(Node* p) {
		Node* t = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		--length;
		
		return t;
	}
};

int main() {
	
}