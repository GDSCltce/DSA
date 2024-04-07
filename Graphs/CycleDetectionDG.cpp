#include <bits/stdc++.h>
using namespace std;

bool _DFS(vector<int> graph[], vector<bool> &vis, vector<bool> &dfsvis, int vertex)
{
/* DFS call karnege 2 array maintain karenge visited and dfsVisted 
har next wali node me jake usko visitec and dfsVisited mark karenge 
while returning from dfs dfsVisited ko unmark karnege
agar while dfs humko koi node mil jaye jo dfsvisited h to matlab cycle h */
    vis[vertex] = true;
    dfsvis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
        {
            if (_DFS(graph, vis, dfsvis, i))
                return true;
        }
        else if (dfsvis[i])
            return true;
    }
    dfsvis[vertex] = false;
    return false;
}

bool _BFS(vector<int> graph[], int n)
{
    //kahns Algorithm
    /* sare indegrees nikalo ek array me */
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
        for (auto &it : graph[i])
            ++indegree[it];

    /* jo bhi 0 indegree wala node h wo push kardo queue me */
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto &i : graph[curr])
        {
            if (indegree[i])
            {
                if (--indegree[i] == 0)
                    q.push(i);
            }
        }
        count++;
    }
    return count != n;
}
bool isCyclic(vector<int> graph[], int n)
{
    vector<bool> vis(n, false);
    vector<bool> dfsvis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (_DFS(graph, vis, dfsvis, i))
                return true;
        }
    }
    return _BFS(graph, n);
    return false;
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
    cout << isCyclic(graph, v);
    return 0;
}