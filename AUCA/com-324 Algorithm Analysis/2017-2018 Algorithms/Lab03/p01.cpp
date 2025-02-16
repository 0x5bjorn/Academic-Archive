#include <iostream>

using namespace std;

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

void pushBack(Node*& head, Node*& tail, int elem)
{
    if (head == nullptr)
    {
       head = tail = new Node(elem, nullptr, nullptr);
    }
    else
    {
       tail->next = new Node(elem, tail, nullptr);
       tail = tail->next;
    }
}

void printInDirectOrder(Node* head, Node* tail)
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void printInReversedOrder(Node* head, Node* tail)
{
    for (Node* p = tail; p != nullptr; p = p->prev)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void insertBefore(Node*& head, Node* curr, int elem)
{
    if (curr == head)
    {
       Node* t = new Node(elem, nullptr, head);
       head->prev = t;
       head = t;
    }
    else
    {
        Node* t = new Node(elem, curr->prev, curr);
        curr->prev->next = t;
        curr->prev = t;
    }
}

Node* erase(Node*& head, Node*& tail, Node* curr)
{
    if (head == curr && head == tail)
    {
        delete curr;
        return nullptr;
    }    
    if (head == curr)
    {
        Node* t = head->next;
        delete head;
        head = t;
        head->prev = nullptr;
        return head;
    }
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    
    int x;
    while (cin >> x)
    {
        pushBack(head, tail, x);
    }
    
    printInDirectOrder(head, tail);
    printInReversedOrder(head, tail);

    for (Node* p = head; p != nullptr; p = p->next)
    {
        if (p->data % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }
    
    printInDirectOrder(head, tail);
    printInReversedOrder(head, tail);

    Node* p = head;
    while (p != nullptr)
    {
        if (p->data % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->next;
        }
    }
    
    printInDirectOrder(head, tail);
    printInReversedOrder(head, tail);
    
    return 0;
}