#include <bits/stdc++.h>
using namespace std;
bool BFS(vector<vector<int>> &graph, int n, int vertex,
         int topath, vector<bool> &vis, vector<int> &ans)
{
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(vertex);
    vis[vertex] = true;
    bool done = false;
    while (!q.empty() && !done)
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (graph[curr][i] == 1 && !vis[i])
            {
                vis[i] = true;
                q.push(i);
                parent[i] = curr;
                if (i == topath)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    if (!done)
        return false;
    else
    {
        int curr = topath;
        ans.emplace_back(topath);
        while (curr != vertex)
        {
            curr = parent[curr];
            ans.emplace_back(curr);
        }
        return true;
    }
}

bool DFS(vector<vector<int>> &graph, int n, int vertex,
         int topath, vector<bool> &vis, vector<int> &ans)
{
    int res;
    vis[vertex] = true;
    if (vertex == topath)
    {
        ans.push_back(topath);
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !vis[i] &&
            DFS(graph, n, i, topath, vis, ans))
        {
            ans.push_back(vertex);
            return true;
        }
    }
    return false;
}

int main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        int v1, v2;
        cin >> v1 >> v2;
        vector<bool> vis(n, false);
        vector<int> ans;

        if (DFS(graph, n, v1, v2, vis, ans))
        {
            for (auto &i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        vis.assign(n, false);
        ans.clear();
        if (BFS(graph, n, v1, v2, vis, ans))
        {
            for (auto &i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
