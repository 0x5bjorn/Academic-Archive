#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

const int defSize = 4;
const int minSize = 3;
const int maxSize = 6;

using namespace std;

int parseCmdLineArgs(int argc, char* argv[]);
vector<string> fillNumbers(int n);
void showHelp(int n);
string getUserNumber(const vector<string>& numbers);
void analyze(const string& compNumber, const string& userNumber, int& dig, int& pos);

int main(int argc, char* argv[])
{
    srand(time(0));
    
    int n = parseCmdLineArgs(argc, argv);

    vector<string> numbers = fillNumbers(n);
    
    random_shuffle(numbers.begin(), numbers.end());
    string compNumber = numbers.front();
    
    sort(numbers.begin(), numbers.end());
    
    showHelp(n);

    int moves = 0;
    int dig = 0;
    int pos = 0;
    while (dig != n or pos != n)
    {
        string userNumber = getUserNumber(numbers);
        analyze(compNumber, userNumber, dig, pos);
        cout << "digits   : " << dig << endl;
        cout << "positions: " << pos << endl;
        ++moves;
    }
    cout << "You are winner!!!" << endl;
    cout << "Your result is " << moves << (moves == 1? " move.": " moves.") << endl;
    
    cout << "\nPress any key..." << endl;
    string s;
    getline(cin, s);
    
    return 0;
}

int parseCmdLineArgs(int argc, char* argv[])
{
    int res = defSize;
    
    if (argc == 2)
    {
        int t; 
        istringstream sinp(argv[1]);
        if (sinp >> t >> ws and sinp.eof())
        {
            t = abs(t);
            res = minSize <= t and t <= maxSize ? t: defSize;
        }
    }
    
    return res;
}

vector<string> fillNumbers(int n)
{
    array<int, 4> lowBounds = {102, 1023, 10234, 102345};
    array<int, 4> uppBounds = {987, 9876, 98765, 987654};
        
    vector<string> res;
    
    for (int i = lowBounds.at(n - minSize); i <= uppBounds.at(n - minSize); ++i)
    {
        string t = to_string(i);
        set<char> s(t.begin(), t.end());
        if (s.size() == n)
        {
            res.push_back(t);
        }
    }
    
    return res;
}

void showHelp(int n)
{
    cout << "------------------------BULLS AND COWS-----------------------------------" << endl;
    cout << "Computer chose " << n << "-digit number without repeating digits." << endl;
    cout << "Your goal is to guess it. After each try computer shows 2 numbers: " << endl;
    cout << "Digits   : <how many digits you guessed>" << endl;
    cout << "Positions: <how many of them are in correct place>" << endl;
    cout << "Good luck!" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

string getUserNumber(const vector<string>& numbers)
{
    for (;;)
    {
        cout << "your guess: ";
        string line;
        getline(cin, line);
        istringstream sinp(line);
        int t;
        if (sinp >> t >> ws and sinp.eof())
        {
            string res = to_string(t);
            if (binary_search(numbers.begin(), numbers.end(), res))
            {
                return res;
            }
        }
        cout << "Incorrect number. Try again..." << endl;
    }
}

void analyze(const string& compNumber, const string& userNumber, int& dig, int& pos)
{
    dig = 0;
    pos = 0;
    for (int i = 0; i < int(userNumber.size()); ++i)
    {
        for (int j = 0; j < int(compNumber.size()); ++j)
        {
            if (userNumber[i] == compNumber[j])
            {
                ++dig;
                pos += i == j;
            }
        }
    }
}