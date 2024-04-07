#include <bits/stdc++.h>
using namespace std;
int N = 10001;
void dfs(vector<vector<bool>> &graph, int n, int vertex, vector<bool> &vis)
{
    cout << vertex << endl;
    vis[vertex] = 1;
    for (int child = 1; child < graph.size(); child++)
    {
        if (child != vertex && graph[vertex][child] && !vis[child])
        {
            dfs(graph, n, child, vis);
        }
    }
}

void bfs(vector<vector<bool>> &graph, int vertex, vector<bool> &vis)
{
    // vector<bool> vis(N);
    vector<int> level(N);
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;
    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int child = 1; child < graph.size(); child++)
        {
            if (child != curr && !vis[child] && graph[curr][child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[curr] + 1;
            }
        }
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     if (vis[i])
    //         cout << i << ": " << level[i] << endl;
    // }
}

int main()
{
    freopen("in.in", "r", stdin);

    int n, e;
    cin >> n >> e;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1));

    for (int i = 0; i < e; i++)
    {
        int f, s, wt = 1;
        cin >> f >> s;
        graph[f][s] = wt;
        graph[s][f] = wt;
    }
    vector<bool> vis(n);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(graph, n, i, vis);
    vis.assign(n, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            bfs(graph, i, vis);

    return 0;
}
