#include <bits/stdc++.h>
using namespace std;

vector<int> TopologicalSort(vector<int> graph[], int n)
{
    vector<int> indegree(n); // store indegrees
    vector<int> ans;
    for (int i = 0; i < n; i++)
        for (auto &it : graph[i])
            indegree[it]++;

    queue<int> q; // push 0 indegree wale nodes in queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.emplace_back(curr); // push every node to get topo sort
        for (auto &i : graph[curr])
        {
            if (--indegree[i] == 0) // condition
                q.push(i);
        }
    }
    return ans;
}

void _DFS(vector<int> graph[], vector<bool> &vis, int vertex, stack<int> &stk)
{
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            _DFS(graph, vis, i, stk);
    }
    stk.push(vertex); // while returning from DFS push vertex to stack
}

vector<int> DFS(vector<int> graph[], int n)
{
    vector<bool> vis(n);
    vector<int> ans;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            _DFS(graph, vis, i, stk);
    }
    while (!stk.empty())
    {
        ans.emplace_back(stk.top());
        stk.pop();
    }
    cout << endl;
}

signed main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].emplace_back(v2);
        // graph[v2].emplace_back(v1);
    }
    vector<int> ans = TopologicalSort(graph, v);
    return 0;
}