#include <iostream>
#include <vector>
#include <stack>

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

void solve()
{
	stack<int> stk;
	
	stk.push(-1);
	
	while (not stk.empty())
	{
		if (stk.size() == n + 1)
		{
			++counter;
			printSol();
			stk.pop();
            takeQueen(stk.top(), stk.size() - 1);
		}
		else if (stk.top() == n)
		{
			stk.pop();
            if (stk.size() != 0)
            {
                takeQueen(stk.top(), stk.size() - 1);
            }
		}
		else
		{
            ++stk.top();
			if (stk.top() < n and check(stk.top(), stk.size() - 1))
			{
				putQueen(stk.top(), stk.size() - 1);
				stk.push(-1);
			}
		}
	}
}

int main()
{
    cin >> n;
    
    rows.resize(n, 0);
    diag1.resize(2 * n - 1, 0);
    diag2.resize(2 * n - 1, 0);

    solve();

    cout << counter << endl;

	return 0;
}