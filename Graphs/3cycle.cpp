#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &graph, int n)
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (graph[i][j])
            {
                for (int k = 0; k <= n; k++)
                {
                    if (graph[j][k] && graph[k][i])
                        cnt++;
                }
            }
        }
    }
    return cnt/6;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    for (int i = 0; i < m; i++)
        cin >> u[i];
    for (int i = 0; i < m; i++)
        cin >> v[i];
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        graph[u[i]][v[i]] = 1;
        graph[v[i]][u[i]] = 1;
    }

    cout << solve(graph, n) << endl;

    return 0;
}
