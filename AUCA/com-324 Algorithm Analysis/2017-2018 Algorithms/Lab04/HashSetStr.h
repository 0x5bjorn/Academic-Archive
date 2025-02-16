#ifndef HASHSETSTR_H
#define HASHSETSTR_H

#include <vector>
#include <string>

class HashSetStr
{
    public:
    
    typedef std::size_t (*HashFunction)(const std::string& s);
    
    HashSetStr(HashFunction hf)
    :buckets(2, nullptr), length(0), hashFunc(hf)
    {
    }
    
    HashSetStr(const HashSetStr& other) = delete;
    HashSetStr& operator=(const HashSetStr& other) = delete;
    
    
    ~HashSetStr()
    {
        clear();
    }
    
    bool find(const std::string& s) const;
    bool insert(const std::string& s);
    bool erase(const std::string& s);
    void rehash(size_t newSize);
    
    void clear();
    void print() const;
    
    size_t bucketCount() const
    {
        return buckets.size();
    }
    
    size_t size() const
    {
        return length;
    }
    
    HashFunction getHashFunc() const
    {
        return hashFunc;
    }
    
    
    private:
    
    struct Node
    {
        std::string data;
        Node* next;
        
        Node(const std::string& d, Node* n)
        : data(d), next(n)
        {
        }
    };
  
  
    std::vector<Node*> buckets;
    std::size_t length;
    HashFunction hashFunc;
};

#endif