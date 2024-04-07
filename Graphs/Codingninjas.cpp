#include <bits/stdc++.h>
using namespace std;
// char pattern[11] = {'C', 'O', 'D', 'I', 'N', 'G', 'N', 'I', 'N', 'J', 'A'};
string pattern = "CODINGNINJA";
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool valid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool DFS(string graph[], vector<vector<bool>> &vis,
         int x, int y, int index, int n, int m)
{
    if (index == pattern.length())
        return 1;

    vis[x][y] = true;
    bool found = 0;
    for (int i = 0; i < 8; i++)
    {
        int newx, newy;
        newx = x + dir[i][0];
        newy = y + dir[i][1];
        if (valid(newx, newy, n, m) &&
            graph[newx][newy] == pattern[index] &&
            !vis[newx][newy])
        {
            found = found | DFS(graph, vis, newx, newy, index + 1, n, m);
        }
    }
    vis[x][y] = false;
    return found;
}

bool solve(string graph[], int n, int m)
{
    bool found = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'C')
            {
                found = DFS(graph, vis, i, j, 1, n, m);
                if (found)
                    break;
            }
        }
        if (found)
            break;
    }
    return found;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string graph[n];
        for (int i = 0; i < n; i++)
            cin >> graph[i];

        cout << solve(graph, n, m) << endl;
    }
    return 0;
}
