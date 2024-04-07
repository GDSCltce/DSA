#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}

void mazeHelp(vector<vector<int>> &maze, int n, vector<vector<int>> &solution, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        printSolution(solution, n);
        return;
    }
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }
    solution[x][y] = 1;
    mazeHelp(maze, n, solution, x - 1, y);
    mazeHelp(maze, n, solution, x + 1, y);
    mazeHelp(maze, n, solution, x, y - 1);
    mazeHelp(maze, n, solution, x, y + 1);
    solution[x][y] = 0;
}

void ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> solution(n, vector<int>(n));
    mazeHelp(maze, n, solution, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInAMaze(maze, n);
    return 0;
}