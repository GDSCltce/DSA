#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int> graph[], vector<bool> &vis, int vertex)
{
    queue<int> q;
    vector<int> ans;
    ans.emplace_back(vertex);
    vis[vertex] = true;
    q.push(vertex);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto &i : graph[curr])
        {
            if (!vis[i])
            {
                ans.emplace_back(i);
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return ans;
}

void DFS(vector<int> graph[], vector<bool> &vis, int vertex, vector<int> &ans)
{
    ans.emplace_back(vertex);
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
        {
            DFS(graph, vis, i, ans);
        }
    }
}

vector<vector<int>> allConnected(vector<int> graph[], int n)
{
    vector<bool> vis(n + 1, 0);
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            DFS(graph, vis, i, temp);
            ans.emplace_back(temp);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<int> graph[v + 1];
        int v1, v2;
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2;
            graph[v1].emplace_back(v2);
            graph[v2].emplace_back(v1);
        }
        vector<vector<int>> ans = allConnected(graph, v);
        for (auto &&i : ans)
        {
            sort(i.begin(), i.end());
            for (auto &&it : i)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}