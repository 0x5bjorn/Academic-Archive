#ifndef HASHSETSTR_H
#define HASHSETSTR_H

#include <string>
#include <vector>

class HashSetStr {
	
	public:
	typedef std::size_t (*HashFunc) (const std::string& s);
	
	HashSetStr(HashFunc aHash)
	: buckets(2, nullptr), length(0), hash(aHash) 
	{
		
	}
	
	private:
	struct Node {
		std::string data;
		Node* next;
		
		Node(const std::string& aData, Node* aNext)
		: data(aData), next(aNext)
		{
		}
	}
	
	std::vector<Node*> buckets;
	std::size_t length;
	HashFunc hash;
};

#endif