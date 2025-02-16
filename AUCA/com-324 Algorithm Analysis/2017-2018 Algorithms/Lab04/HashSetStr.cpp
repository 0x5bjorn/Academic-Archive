#include <iostream>
#include <iomanip>

#include "HashSetStr.h"

using namespace std;

void HashSetStr::print() const
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        cout << setw(8) << i << ": ";
        for (Node* p = buckets[i]; p != nullptr; p = p->next)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
}

bool HashSetStr::find(const string& s) const
{
    size_t index = hashFunc(s) % buckets.size();
    
    for (Node* p = buckets[index]; p != nullptr; p = p->next)
    {
        if (p->data == s)
        {
            return true;
        }
    }
    
    return false;
}

bool HashSetStr::insert(const string& s)
{
    size_t index = hashFunc(s) % buckets.size();
    
    for (Node* p = buckets[index]; p != nullptr; p = p->next)
    {
        if (p->data == s)
        {
            return false;
        }
    }
    
    if (length + 1 >= buckets.size())
    {
        rehash(2 * buckets.size() + 1);
    }
    
    buckets[index] = new Node(s, buckets[index]);
    ++length;
    
    return true;
}

bool HashSetStr::erase(const string& s)
{
    size_t index = hashFunc(s) % buckets.size();
    
    Node* q = nullptr;
    for (Node* p = buckets[index]; p != nullptr; p = p->next)
    {
        if (p->data == s)
        {
            if (q == nullptr)
            {
                buckets[index] = p->next;
                delete p;
            }
            else
            {
                q->next = p->next;
                delete p;
            }
            --length;
            return true;
        }
        q = p;
    }
    
    return false;
}

void HashSetStr::rehash(size_t newSize)
{
    vector<Node*> newBuckets(newSize, nullptr);
    
    
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        for (Node* p = buckets[i]; p != nullptr; p = p->next)
        {
            size_t index = hashFunc(p->data) % newSize;
            newBuckets[index] = new Node(p->data, newBuckets[index]);
        }
        
    }
    
    size_t temp = length;
    clear();
    length = temp;
    
    buckets.swap(newBuckets);
}

void HashSetStr::clear()
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        for (Node* p = buckets[i]; p != nullptr;)
        {
            Node* t = p->next;
            delete p;
            p = t;
        }
        
        buckets[i] = nullptr;
    }
    
    length = 0;
}

