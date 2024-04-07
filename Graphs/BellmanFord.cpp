#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define inf 1e9

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;  
        vector<vector<int>> graph;
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < e; i++)
        {
            int src, dest, wt;
            cin >> src >> dest >> wt;
            graph.push_back({src, dest, wt});
        }
        vector<int> dist(n + 1, inf);
        vector<int> parent(n + 1, -1);
        dist[a] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < e; j++)
            {
                int src = graph[j][0];
                int dest = graph[j][1];
                int wt = graph[j][2];
                if (dist[dest] > dist[src] + wt)
                {
                    dist[dest] = dist[src] + wt;
                    parent[dest] = src;
                }
            }
        }
        cout << dist[b] << endl;
    }
    return 0;
}