#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int PrimsAlgo(vector<pii> graph[], int n)
{
    int src = 0;
    vector<int> weight(n, 1e9);
    weight[src] = 0;
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        for (auto &i : graph[u])
        {
            int wt = i.first;
            int v = i.second;
            if (!inMST[v] && weight[v] > wt)
            {
                weight[v] = wt;
                pq.push({wt, v});
            }
        }
    }
    int sum = 0;
    for (auto &i : weight)
    {
        sum += i;
    }
    return sum;
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
            Graph[src].push_back({wt, dest});
            Graph[dest].push_back({wt, src});
        }
        cout << PrimsAlgo(Graph, n) << endl;
    }
    return 0;
}