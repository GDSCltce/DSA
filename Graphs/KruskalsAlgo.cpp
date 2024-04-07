#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int v1, v2, wt;
    bool operator<(edge const &a)
    {
        return wt < a.wt;
    }
};

int getParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = getParent(parent[v], parent);
}

void kruskalsAlgo(vector<edge> &Edges, int n, vector<edge> &ans)
{
    sort(Edges.begin(), Edges.end());
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0, cnt = 0; cnt < (n - 1); i++)
    {
        edge curr = Edges[i];
        int src = getParent(curr.v1, parent);
        int dest = getParent(curr.v2, parent);
        if (src != dest)
        {
            ans[cnt++] = curr;
            parent[src] = dest;
        }
    }
    return;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<edge> Edges(e);
        for (int i = 0; i < e; i++)
        {
            cin >> Edges[i].v1 >> Edges[i].v2 >> Edges[i].wt;
        }
        vector<edge> ans(n - 1);
        kruskalsAlgo(Edges, n, ans);
        int answt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cout << answt << " ";
            answt += ans[i].wt;
        }
        cout << answt << endl;
    }
    return 0;
}