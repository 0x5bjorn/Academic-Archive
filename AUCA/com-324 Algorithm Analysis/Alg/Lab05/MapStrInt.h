#ifndef MAPSTRINT_H
#define MAPSTRINT_H

#include <string>
#include <utility>

class MapStrInt {
	public:
	MapStrInt()
	: root(nullptr), length(0)
	{
	}
	
	void print() const;
	int& operator[](const std::string& k);
	
	private:
	struct Node {
		std::pair<string, int> data;
		Node* lft;
		Node* rgt;
		
		Node(const std::string& k, int v, Node* aLft, Node* aRgt) 
		: data(k, v), lft(aLft), rgt(aRgt)
		{	
		}
	};
	
	struct StackFrame {
		int counter;
		Node* n;
		
		StackFrame(int aCount; Node* aN) 
		: count(aCount), n(aN)
		{
		};
	};
	
	Node* root;
	size_t length; // int
};

#endif