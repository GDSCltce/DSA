#include <bits/stdc++.h>
using namespace std;

void addedge(vector<int> graph[], int v1, int v2)
{
    graph[v1].emplace_back(v2);
    graph[v2].emplace_back(v1);
}

bool BFS(vector<int> graph[], int vertex, vector<int> &color)
{
    queue<int> q;
    q.push(vertex);
    color[vertex] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto &i : graph[curr])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[curr];
                q.push(i);
            }
            else if (color[i] == color[curr])
            {
                return false;
            }
        }
    }
    return true;
}

bool DFS(vector<int> graph[], int vertex, vector<int> &color)
{
    if (color[vertex] == -1)
        color[vertex] = 1;
    for (auto &i : graph[vertex])
    {
        if (color[i] == -1)
        {
            color[i] = 1 - color[vertex];
            if (!DFS(graph, i, color))
                return false;
        }
        else if (color[i] == color[vertex])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> graph[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1 && !DFS(graph, i, color))
            return false;
    }
    return true;
}

int main()
{
    int n = 3;
    // cin >> n;
    vector<int> graph[n];
    addedge(graph, 0, 1);
    addedge(graph, 2, 1);
    cout << isBipartite(n, graph);
    return 0;
}
