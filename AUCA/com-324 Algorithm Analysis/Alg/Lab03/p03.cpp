#include <iostream>
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
	
	// void insert(Node* p, int elem) {
		
	// }
	
	public:
	
	class Iter {
		friend class ListInt;
		
		private:
		Node* p;
		
		public:
		
		Iter()
		: p(nullptr)
		{
		}
		
		Iter& operator++() {
			#ifdef AUCA_DEBUG
			if (p == nullptr or p->next == nullptr) {
				throw out_of_range("ListInt::Iter: incorrect ++");
			}	
			#endif
			
			p = p->next;
			return *this;
		}
		
		Iter& operator--() {
			#ifdef AUCA_DEBUG
			if (p == nullptr or p->prev->prev == nullptr) {
				throw out_of_range("ListInt::Iter: incorrect --");
			}	
			#endif
			
			p = p->prev;
			return *this;
		}
		
		int& operator*() {
			#ifdef AUCA_DEBUG
			if (p == nullptr or p->next == nullptr or p->prev == nullptr) {
				throw out_of_range("ListInt::Iter: incorrect *");
			}
			#endif
			
			return p->data;
		}
		
		bool operator==(Iter other) {
			return p == other.p;
		}
		
		bool operator!=(Iter other) {
			return not(*this == other);
		}
	};
	
	class RIter {
		friend class ListInt;
		
		private:
		Node* p;
		
		public:
		
		RIter()
		:p(nullptr)
		{
		}
		
		RIter& operator++() {
			p = p->next;
			return *this;
		}
		
		RIter& operator--() {
			p = p->prev;
			return *this;
		}
		
		int& operator*() {
			return p->data;
		}
		
		bool operator==(RIter other) {
			return p == other.p;
		}
		
		bool operator!=(RIter other) {
			return not(*this == other);
		}
	};
	
	ListInt() 
	: length(0)
	{
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, head, nullptr);
		head->next = tail;
	}
	
	~ListInt() {
		Node* p = head->next;
		while (p != tail) {
			erase(p);
		}
		
		head = tail = nullptr;
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
	
	void pushBack(int elem) {
		insert(tail, elem);
	}
	
	void popBack() {
		erase(tail->prev);
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
	
	void debugPrint() {
		cout << "Size: " << length << endl;
		for (Node* p = head->next; p != tail; p = p->next) {
			cout << p->data << " ";
		}
		cout << endl;
	}
	
	void debugReversePrint() {
		cout << "Size: " << length << endl;
		for (Node* p = tail->prev; p != head; p = p->prev) {
			cout << p->data << " ";
		}
		cout << endl;
	}
	
	private:
	//service function
	Node* insert(Node* p, int elem) {
		Node* t = new Node(elem, p->prev, p);
		p->prev->next = t;
		p->prev = t;
		++length;
		
		return t;
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
	ListInt v;
	int x;
	while (cin >> x) {
		v.pushBack(x);
	}
	
	for (int e: v) {
		cout << e << " ";
	}
	cout << endl;
	
	for (ListInt::Iter it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	for (ListInt::RIter it = v.rbegin(); it != v.rend(); --it) {
		cout << *it << " ";
	}
	cout << endl;
	
	//Case 0:
	// ListInt::Iter it1 = v.begin();
	// ++it1;
	// ++it1;
	// ++it1;
	
	//Case 1:
	//cout << *it1 << endl;
	
	//Case 2:
	//++it1;
	
	// ListInt::Iter it2;
	
	//Case 3:
	//cout << *it2 << endl;
	
	//Case 4:
	//++it2;
	
	//Case 5:
	//--it2;
	
	ListInt::Iter it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.insert(it, 0);
			++it;
		}
		++it;
	}
	
	v.debugPrint();
	v.debugReversePrint();
	
	it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.erase(it);
		} else {
			++it;
		}
	}	
	
	v.debugPrint();
	v.debugReversePrint();
	
	return 0;
}