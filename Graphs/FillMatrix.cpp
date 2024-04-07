#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    // size of DSU
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
            parent.emplace_back(i);
        size.assign(n + 1, 1);
    }
    void make(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    // returns the parent of the given set
    int findParent(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = findParent(parent[v]);
    }
    // Combines a, b set into a
    void Union(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
        return;
    }
};

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

bool isbipartite(vector<int> graph[], int V)
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1 && !DFS(graph, i, color))
            return false;
    }
    return true;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        DSU ds(n);
        vector<int> graph[n];
        bool flag = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y, val;
            cin >> x >> y >> val;
            x--, y--;
            if (x == y and val == 1)
                flag = 1;
            if (val == 0)
                ds.Union(x, y);
            else
            {
                graph[x].emplace_back(y);
                graph[y].emplace_back(x);
            }
        }
        if (flag)
        {
            cout << "no\n";
            continue;
        }
        vector<int> nGraph[n];
        for (int i = 0; i < n; i++)
        {
            for (auto &x : graph[i])
            {
                int p1 = ds.findParent(i);
                int p2 = ds.findParent(x);
                if (p1 == p2)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    nGraph[p1].emplace_back(p2);
                    nGraph[p2].emplace_back(p1);
                }
            }
            if (flag)
                break;
        }
        if (flag)
        {
            cout << "no\n";
            continue;
        }
        if (!isbipartite(nGraph, n))
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}