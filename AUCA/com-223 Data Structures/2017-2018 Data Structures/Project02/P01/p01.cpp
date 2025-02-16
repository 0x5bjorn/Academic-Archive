#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pixel
{
    int r;
    int c;
    int nb;
    
    Pixel(int aR, int aC, int aNB)
    : r(aR), c(aC), nb(aNB)
    {
    }
};


int main()
{
    int r; cin >> r;
    int c; cin >> c;
    
    vector<vector<char>> screen(r + 2, vector<char>(c + 2, '+'));
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> screen[i][j];
        }
    }
    
    
    int sr; cin >> sr;
    int sc; cin >> sc;
    
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    
    stack<Pixel> stack;
    
    screen[sr][sc] = '*';
    stack.push(Pixel(sr, sc, 0));
    while (not stack.empty())
    {
        bool found = false;
        
        for (int i = stack.top().nb; i < 4 and not found; ++i)
        {
            int cr = stack.top().r + dr[i];
            int cc = stack.top().c + dc[i];
            if (screen[cr][cc] == '.')
            {
                found = true;
                screen[cr][cc] = '*';
                stack.top().nb = i;
                stack.push(Pixel(cr, cc, 0));
            }
        }
        if (not found)
        {
            stack.pop();
        }
    }
    
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cout << screen[i][j];
        }
        cout << endl;
    }
    
    return 0;
}