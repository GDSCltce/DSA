#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], vector<bool> &vis, int vertex)
{
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            DFS(graph, vis, i);
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;
        vector<int> graph[n];
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        vector<bool> vis(n);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                DFS(graph, vis, i);
            }
        }
        cout << count << endl;
    }
    return 0;
}
