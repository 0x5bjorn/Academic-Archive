#include <iostream>

using namespace std;


class ListInt
{
    private:

    struct Node
    {
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
    
    class Iter
    {
        friend class ListInt;
        
        private:
        Node* p;
        
        public:
        
        Iter()
        : p(nullptr)
        {
        }
        
        Iter& operator++()
        {
            p = p->next;
            return *this;
        }
        
        Iter& operator--()
        {
            p = p->prev;
            return *this;
        }
        
        int& operator*()
        {
            return p->data;
        }
        
        bool operator==(Iter other)
        {
            return p == other.p;
        }
        
        bool operator!=(Iter other)
        {
            return not(*this == other);
        }
    };
    
    class RIter
    {
        friend class ListInt;
        
        private:
        Node* p;
        
        public:
        
        RIter()
        : p(nullptr)
        {
        }
        
        RIter& operator++()
        {
            p = p->prev;
            return *this;
        }
        
        RIter& operator--()
        {
            p = p->next;
            return *this;
        }
        
        int& operator*()
        {
            return p->data;
        }
        
        bool operator==(RIter other)
        {
            return p == other.p;
        }
        
        bool operator!=(RIter other)
        {
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
    
    Iter begin()
    {
        Iter it;
        it.p = head->next;
        
        return it;
    }
    
    Iter end()
    {
        Iter it;
        it.p = tail;
        
        return it;
    }
    
    RIter rbegin()
    {
        RIter it;
        it.p = tail->prev;
        
        return it;
    }
    
    RIter rend()
    {
        RIter it;
        it.p = head;
        
        return it;
    }
    
    void pushBack(int elem)
    {
        Node* t = new Node(elem, tail->prev, tail);
        tail->prev->next = t;
        tail->prev = t;
        
        ++length;
    }
    
    void debugPrint()
    {
        cout << "Size: " << length << "\n";
        for (Node* p = head->next; p != tail; p = p->next)
        {
            cout << p->data << " ";
        }
        cout << "\n";
    }
    
    void debugReversePrint()
    {
        cout << "Size: " << length << "\n";
        for (Node* p = tail->prev; p != head; p = p->prev)
        {
            cout << p->data << " ";
        }
        cout << "\n";
    }
        
};

int main()
{
    ListInt v;
    
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    
    for (int e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    
    for (ListInt::RIter it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}