#include <bits/stdc++.h>
using namespace std;    
#define pii pair<int, int>
#define inf 1e9

int Dijkstra(vector<pii> graph[], int n, int src = 0)
{
    /* prims algo ki tara h
    phele ek priority_queue banao fir source ko usme push karo
    fir BFS ki tara loop karo */
    vector<bool> vis(n + 1, 0);
    vector<int> dist(n + 1, inf);
    vector<int> parent(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int currwt = pq.top().first;
        pq.pop();
        if (vis[curr])
            continue;
        vis[curr] = 1;
        for (auto &i : graph[curr])
        {
            int childv = i.first;
            int childwt = i.second;
            /* agar to child node ka dist + dist[curr] < dist[child] se  */
            if (dist[curr] + childwt < dist[childv])
            {
                dist[childv] = dist[curr] + childwt;
                pq.push({dist[childv], childv});
                parent[childv] = curr;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == inf)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pii> Graph[n + 1];
    for (auto &v : times)
    {
        Graph[v[0]].push_back({v[1], v[2]});
    }
    return Dijkstra(Graph, n, k);
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<pii> Graph[n];
        for (int i = 0; i < e; i++)
        {
            int src, dest, wt;
            cin >> src >> dest >> wt;
            Graph[src].push_back({dest, wt});
            // Graph[dest].push_back({src, wt});
        }
        Dijkstra(Graph, n);
    }
    return 0;
}