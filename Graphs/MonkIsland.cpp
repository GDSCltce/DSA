#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int inf = 1e9;

void printpath(vector<int> &parent, int vertex)
{

    if (parent[vertex] == -1)
    {
        cout << vertex + 1 << " ";
        return;
    }
    printpath(parent, parent[vertex]);
    cout << vertex + 1 << " ";
    return;
}

int dijkstra(vector<pii> graph[], int n, int src = 0)
{
    bool vis[n] = {0};
    vector<int> dist(n, inf);
    vector<int> parent(n, -1);
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
        vis[curr] = true;
        for (auto &i : graph[curr])
        {
            int child = i.first;
            int childwt = i.second;
            if (dist[curr] + childwt < dist[child])
            {
                dist[child] = dist[curr] + childwt;
                pq.push({dist[child], child});
                parent[child] = curr;
            }
        }
    }
    printpath(parent, n - 1);
    return dist[n - 1];
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pii> graph[n];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1].push_back({y - 1, 1});
            graph[y - 1].push_back({x - 1, 1});
        }
        cout << dijkstra(graph, n) << endl;
    }
    return 0;
}