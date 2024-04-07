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
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && !vis[newx][newy] && graph[newx][newy])
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
                int count = 0;
                DFS(graph, vis, i, j, n, count);
                ans = max(ans, count);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
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

        cout << solve(graph, n) << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// void dfs(int **cake, int n, int i, int j, bool **visited, int &count)
// {
//     visited[i][j] = true;
//     if (i < 0 || j >= n || cake[i][j] == 0 || j < 0 || i >= n)
//     {
//         return 0;
//     }
//     count++;
//     dfs(cake, n, i, j + 1, visited);
//     dfs(cake, n, i + 1, j, visited);
//     dfs(cake, n, i + 1, j + 1, visited);
//     dfs(cake, n, i - 1, j - 1, visited);
//     return;
// }
// int piece(int **cake, int n)
// {
//     int ans = 0;
//     bool **visited = new bool *[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = new bool[n];
//         for (int j = 0; j < n; j++)
//         {
//             visited[i][j] = false;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             int count = 0;
//             dfs(cake, n, i, j, vis, count);
//             ans = max(ans, count);
//         }
//     }
//     return ans;
// }
// int main()
// {

//     // write your code here
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         int **cake = new int *[n];
//         for (int i = 0; i < n; i++)
//         {
//             cake[i] = new int[n];
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> cake[i][j];
//             }
//         }
//         cout << piece(cake, n) << endl;
//     }
//     return 0;
// }