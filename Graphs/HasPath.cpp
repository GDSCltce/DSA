#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<int> graph[], int vertex, int topath, vector<bool> &vis)
{
    vis[vertex] = true;
    if (vertex == topath)
        return true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i] && DFS(graph, i, topath, vis))
            return true;
    }
    return false;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> graph[n];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int v1, v2;
        cin >> v1 >> v2;
        vector<bool> vis(n, 0);
        bool ans = DFS(graph, v1, v2, vis);
        cout << ans << endl;
    }
    return 0;
}
