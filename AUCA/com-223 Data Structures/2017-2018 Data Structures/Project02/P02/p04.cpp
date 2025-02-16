#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Cell
{
    int row;
    int col;
    Cell(int aRow = 0, int aCol = 0)
    : row(aRow), col(aCol)
    {
    }
};

int main()
{
    vector<vector<int>> maze;
    string line;
    
    Cell start(-1, -1);
    Cell finish(-1, -1);
    
    int row = 0;
    
    while (getline(cin, line))
    {
        maze.push_back(vector<int>());
        int col = 0;
        for (char ch: line)
        {
            if (ch == '.')
            {
                maze.back().push_back(0);
            }
            else if (ch == 'X')
            {
                maze.back().push_back(-1);
            }
            else if (ch == 'S')
            {
                start = Cell(row, col);
                maze.back().push_back(0);
            }
            else if (ch == 'F')
            {
                finish = Cell(row, col);
                maze.back().push_back(0);
            }
            ++col;
        }
        ++row;
    }
    
    int mazeWidth = maze.front().size();
    int mazeHeight = maze.size();
    
    queue<Cell> q;
    
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    
    q.push(Cell(start.row, start.col));
    maze[start.row][start.col] = 1;
    
    bool found = false;
    while (not q.empty() and not found)
    {
        Cell u = q.front(); q.pop();
        for (int i = 0; i < dr.size(); ++i)
        {
            int tr = u.row + dr[i];
            int tc = u.col + dc[i];
            
            if (tr < 0 or mazeHeight <= tr)
            {
                continue;
            }
            if (tc < 0 or mazeWidth <= tc)
            {
                continue;
            }
            
            if (maze[tr][tc] == 0)
            {
                maze[tr][tc] = maze[u.row][u.col] + 1;
                q.push(Cell(tr, tc));
                if (tr == finish.row and tc == finish.col)
                {
                    found = true;
                }
            }
        }
    }
    
    if (found)
    {
        cout << "distance: " 
             << maze[finish.row][finish.col] << endl;
        int cr = finish.row;
        int cc = finish.col;
        int ds = maze[cr][cc];
        maze[cr][cc] = -3;
        while (cr != start.row or cc != start.col)
        {
            for (int i = 0; i < dr.size(); ++i)
            {
                int tr = cr + dr[i];
                int tc = cc + dc[i];
                if (tr < 0 or mazeHeight <= tr)
                {
                    continue;
                }
                if (tc < 0 or mazeWidth <= tc)
                {
                    continue;
                }
                if (maze[tr][tc] + 1 == ds)
                {
                    --ds;
                    cr = tr;
                    cc = tc;
                    maze[cr][cc] = -3;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "shortest path not found" << endl;
    }
    
    for (auto r: maze)
    {
        for (auto c: r)
        {
            if (c >= 0)
            {
                cout << '.';
            }
            else if (c == -1)
            {
                cout << 'X';
            }
            else if (c == -3)
            {
                cout << '+';
            }
        }
        cout << endl;
            
    }
    return 0;
}