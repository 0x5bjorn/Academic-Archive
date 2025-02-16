#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

vector<string> fillGuesses();
int getAnswer(const string& msg, int a, int b);
vector<string> filter(const vector<string>& g, int n, int m);
void countBullsCows(const string& g, const string& e, int& n, int& m);
bool parseInt(const string& s, int& r);

int main()
{
    srand(time(0));
    
    vector<string> guesses = fillGuesses();
    random_shuffle(guesses.begin(), guesses.end());
    
    for (;;)
    {
        cout << "My guess: " << guesses.front() << endl;
        
        int n = getAnswer("number of digits: ", 0, 4);
        int m = getAnswer("correct positions: ", 0, 4);
        
        if (n == 4 and m == 4)
        {
            cout << "AI won." << endl;
            break;
        }
        
        guesses = filter(guesses, n, m);
        
        if (guesses.empty())
        {
            cout << "Cheating!!!" << endl;
            break;
        }
        
        random_shuffle(guesses.begin(), guesses.end());
    }
    
    return 0;
}

vector<string> fillGuesses()
{
    vector<string> res;
    
    for (int i = 1023; i <= 9876; ++i)
    {
        string t = to_string(i);
        set<char> s(t.begin(), t.end());
        if (s.size() == 4)
        {
            res.push_back(t);
        }
    }
    
    return res;
}


int getAnswer(const string& msg, int a, int b)
{
    for (;;)
    {
        cout << msg;
        string line;
        getline(cin, line);
        
        int r; 
        if (parseInt(line, r) and a <= r and r <= b)
        {
            return r;
        }
        cout << "Incorrect input. Try again." << endl;
    }
}


vector<string> filter(const vector<string>& guesses, int n, int m)
{
    vector<string> res;
    
    string g = guesses.front();
    
    for (const auto& e: guesses)
    {
        int tn;
        int tm;
        countBullsCows(g, e, tn, tm);
        
        if (tn == n and tm == m)
        {
            res.push_back(e);
        }
    }
    
    return res;
}

void countBullsCows(const string& g, const string& e, int& n, int& m)
{
    n = 0;
    m = 0;
    for (int i = 0; i < int(g.size()); ++i)
    {
        for (int j = 0; j < int(e.size()); ++j)
        {
            if (g[i] == e[j])
            {
                ++n;
                m += i == j;
            }
            
        }
    }
}

bool parseInt(const string& s, int& r)
{
    istringstream sinp(s);
    return sinp >> r >> ws and sinp.eof();
}