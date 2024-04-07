#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], vector<bool> &vis, int vertex)
{
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
        {
            vis[i] = true;
            DFS(graph, vis, i);
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<int> graph[v];
        for (int i = 0; i < e; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].emplace_back(v2);
            graph[v2].emplace_back(v1);
        }
        vector<bool> vis(v, 0);
        DFS(graph, vis, 0);
        bool flag = true;
        for (auto &&i : vis)
        {
            if (!i)
            {
                flag = false;
                cout << "false\n";
                break;
            }
        }
        if (flag)
        {
            cout << "true\n";
        }
    }
    return 0;
}

bool isconnected(int **edge, int n, int start_vertex, bool *visited)
{
    queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = true;
    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == current_vertex)
                continue;
            if (edge[current_vertex][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}