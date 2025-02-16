#ifndef HASHSETSTR_H
#define HASHSETSTR_H

#include <iostream>
#include <vector>

class HashSetStr {
	
	public:
	
	typedef std::size_t (*HashFunction) (const string& s);
	
	HashSetStr(HashFunction hf) 
	: buckets(2, nullptr), length(0), hashFunc(hf);
	{
	}
	
	HashSetStr(const HashSetStr& other) = delete;
	HashSetStr operator=(const HashSetStr& other) = delete;
		
	~HashSetStr() {
		clear();
	}
	
	void clear();
	void print() const;
	
	bool insert(const string& s);
	bool erase(const string& s);
	bool find(const string& s) const;
	
	size_t bucketCount() const {
		return buckets.size();
	}
	
	size_t size() const {
		return length;
	}
	
	HashFunction getHashFunc() {
		return hashFunc;
	}
	
	private:
	
	struct Node {
		std::string data;
		Node* next;
		
		Node(const std::string& data d, Node* n) 
		: data(d), next(n)
		{	
		}
	};
	
	std::vector<Node*> buckets;
	std::size_t length;
	HashFunction hashFunc;
};