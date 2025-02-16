#include <iostream>
#include <vector>

using namespace std;

int counter = 0;
int n;
vector<int> sol;
vector<int> rows;
vector<int> diag1;
vector<int> diag2;



bool check(int r, int c)
{
    return rows[r] == 0 and diag1[c - r + n - 1] == 0 and diag2[r + c] == 0;
}

void printSol()
{
    for (int e: sol)
    {
        cout << " " << e;
    }
    cout << endl;
}

void putQueen(int r, int c)
{
    rows[r] = diag1[c - r + n - 1] = diag2[r + c] = 1;
    sol.push_back(r);
}

void takeQueen(int r, int c)
{
    rows[r] = diag1[c - r + n - 1] = diag2[r + c] = 0;
    sol.pop_back();
}


void solve(int col)
{
    if (col == n)
    {
        ++counter;
        printSol();
    }
    else
    {
        for (int row = 0; row < n; ++row)
        {
            if (check(row, col))
            {
                putQueen(row, col);
                solve(col + 1);
                takeQueen(row, col);
            }
        }
    }
}

int main()
{
    cin >> n;
    
    rows.resize(n);
    diag1.resize(2 * n - 1);
    diag2.resize(2 * n - 1);
    solve(0);
    cout << "Total: " << counter << endl;
    
    return 0;
}