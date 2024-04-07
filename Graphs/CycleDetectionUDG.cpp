#include <bits/stdc++.h>
using namespace std;

bool _BFS(vector<int> graph[], vector<bool> &vis, int vertex)
{
    queue<pair<int, int>> q;
    q.push({vertex, -1});
    vis[vertex] = true;
    while (!q.empty())
    { 
        /*queue me current vertex and uska parent dono push karenge to check ke agar next bfs loop ke time hum same parent pe h to usko ignore karo but agar nhi h to iska matlab waha cycle form hori h  */
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto &i : graph[curr])
        {
            if (!vis[i])
            {
                q.push({i, curr});
                vis[i] = true;
            }
            else if (par != i)
            {
                return true;
            }
        }
    }
    return false;
}

bool _DFS(vector<int> graph[], vector<bool> &vis, int vertex, int parent)
{
    /* dfs(vertex)-> har vertex pe dfs kro and ek parent[] maintian karo
    agar to parent != current vertex ke to cycle exist
    agar nhi h to parent h usko ignore karo */
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
        {
            if (_DFS(graph, vis, i, vertex))
                return true;
        }
        else if (parent != i)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> graph[], int n)
{
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if (_DFS(graph, vis, i, -1))
                return true;
    }
    return false;
}
/* humko ye save karna hoga ki har vertex ka parent kya h agar next wali nodes jo visited h and parent nhi h to wo check karo agr aesa h to loop h*/
signed main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v + 1];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1);
    }
    cout << isCyclic(graph, v);
    return 0;
}