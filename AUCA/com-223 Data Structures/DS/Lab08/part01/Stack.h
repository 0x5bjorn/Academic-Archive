#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

class StackException: public std::runtime_error
{
    public:
    StackException(const std::string& msg)
    : runtime_error(msg)
    {
    }
};

template<typename T>
class Stack
{    
    private:
    
    std::vector<T> data;
	
    public:
    
    void push(const T& e)
    {
        data.push_back(e);
    }
    
    void pop()
    {
        if (data.empty())
        {
            throw StackException("Stack: Stack is empty");
        }
        data.pop_back();
    }
    
    T& top()
    {
        if (data.empty())
        {
            throw StackException("Stack: Stack is empty");
        }
        return data.back();
    }
    
    const T& top() const
    {
        if (data.empty())
        {
            throw StackException("Stack: Stack is empty");
        }
        return data.back();
    }
    
    bool empty() const
    {
        return data.empty();
    }
    
    std::size_t size() const
    {
        return data.size();
    }
};

#endif