#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <stdexcept>

class QueueException: public std::runtime_error
{
    public:
    QueueException(const std::string& msg)
    : runtime_error(msg)
    {
    }
};

template<typename T>
class Queue
{
    public:
    
    std::size_t size() const
    {
        return data.size();
    }
    
    bool empty() const
    {
        return data.empty();
    }
    
    const T& top() const
    {
        checkEmpty();
        return data.front(); 
    }
    
    T& top()
    {
        checkEmpty();
        return data.front(); 
    }
    
    void pop()
    {
        checkEmpty();
        data.pop_front();
    }

    void push(const T& e)
    {
        data.push_back(e);
    }
    
    private:
    
    void checkEmpty()
    {
        if (empty())
        {
            throw QueueException("Queue is empty");
        }
    }
    
    std::deque<T> data;
};

#endif