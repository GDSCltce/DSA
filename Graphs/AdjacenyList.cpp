#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printGraph(vector<int> graph[], int v)
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << " ";
        for (auto &i : graph[i])
            cout << i << " ";
        cout << endl;
    }
}

void _dfs(vector<int> graph[], int vertex, vector<bool> &vis)
{
    cout << vertex << endl;
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        if (!vis[child])
            _dfs(graph, child, vis);
    }
}

void dfs(vector<int> graph[], int vertex)
{
    vector<bool> vis(N);
    _dfs(graph, vertex, vis);
}

void bfs(vector<int> graph[], int vertex)
{
    vector<bool> vis(N);
    vector<int> level(N);
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;
    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int &child : graph[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[curr] + 1;
            }
        }
    }
}

signed main()
{
    freopen("in.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> graph[N];
    int v1, v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        addEdge(graph, v1, v2);
    }
    dfs(graph, 1);
    bfs(graph, 1);

    return 0;
}
