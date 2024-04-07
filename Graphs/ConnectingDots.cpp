#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void DFS(vector<vector<int>> &graph, vector<vector<bool>> &vis,
         int x, int y, int n, int &count)
{
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && !vis[x][y] && graph[x][y])
        {
            vis[newx][newy] = 1;
            count++;
            DFS(graph, vis, newx, newy, n, count);
        }
    }
}

int solve(vector<vector<int>> &graph, int n)
{
    vector<vector<bool>> vis(n, vector<bool>(n));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && graph[i][j])
            {
                int count = 1;
                DFS(graph, vis, i, j, n, count);
                ans = max(ans, count);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string temp;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < n; j++)
            graph[i][j] = temp[j] - '0';
    }

    cout << solve(graph, n);
    return 0;
}
