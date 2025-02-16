#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Queue.h"

using namespace std;

const int minValue = -20;
const int maxValue = 20;

struct Task
{
    int num1;
    int num2;
    char op;
    int res;
    Task(int aNum1, int aNum2, char anOp, int aRes)
    : num1(aNum1), num2(aNum2), op(anOp), res(aRes)
    {
    }
};

Queue<Task> generateTasks(int n);
bool checkCurrentTask(const Task& t);
bool getInt(const string& msg, const string& err, int& res);

int main()
{
    srand(time(0));

    const string msg = "number of tasks (<= 0: exit): ";
    const string err = "incorrect integer";
    int n;
    
    while (getInt(msg, err, n) and n > 0)
    {
        Queue<Task> tasks = generateTasks(n);
        while (not tasks.empty())
        {
            cout << "number of tasks remained: " << tasks.size() << endl;
            
            Task t = tasks.top(); tasks.pop();
            if (not checkCurrentTask(t))
            {
                tasks.push(t);
            }
        }
    }
    
    return 0;
}

bool getInt(const string& msg, const string& err, int& res)
{
    for (;;)
    {
        cout << msg;
        string line;
        if (not getline(cin, line))
        {
            cin.clear();
            continue;
        }
        istringstream sinp(line);
        int x;
        if (sinp >> x >> ws and sinp.eof())
        {
            res = x;
            return true;
        }
        cout << err << endl;
    }        
}

Queue<Task> generateTasks(int n)
{
    const string operations = "+-*/";
    
    Queue<Task> res;
    for (int i = 0; i < n; ++i)
    {
        char op = operations[rand() % operations.size()];
        int a = minValue + rand() % (maxValue - minValue + 1);
        int b = minValue + rand() % (maxValue - minValue + 1);
        while (op == '/' and b == 0)
        {
            b = minValue + rand() % (maxValue - minValue + 1);
        }
        switch (op)
        {
            case '+':
                res.push(Task(a, b, op, a + b));
                break;
            case '-':
                res.push(Task(a, b, op, a - b));
                break;
            case '*':
                res.push(Task(a, b, op, a * b));
                break;
            case '/':
                res.push(Task(a * b, b, op, a));
                break;
        }
    }
    
    return res;
}

bool checkCurrentTask(const Task& t)
{
    ostringstream sout;
    sout << t.num1 << " " << t.op << " " << t.num2 << " = ";
    
    for (;;)
    {
        int x;
        if (getInt(sout.str(), "incorrect int", x))
        {
            if (x != t.res)
            {
                cout << "incorrect answer; try again later" << endl;
                return false;
            }
            return true;
        }
    }
}