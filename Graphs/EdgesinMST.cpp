#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int src[N], dst[N], wt[N], index[N];
int ans[N], vis[N], depth[N];
int parent[N], sze[N];

vector<pair<int, int>> graph[N];

// sze of DSU
void DSUmake()
{
    for (int i = 0; i < N; i++)
        parent[i] = i;
    memset(sze, 1, sizeof sze);
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
    graph[a].clear();
    graph[b].clear();
    vis[a] = vis[b] = false;
    if (a != b)
    {
        if (sze[a] < sze[b])
            swap(a, b);
        parent[b] = a;
        sze[a] += sze[b];
    }
    return;
}

void kruskal(int vertex, int index, int h)
{
    vis[vertex] = true;
    depth[vertex] = h;
    for (auto &i : graph[vertex])
    {
        if (!vis[i.first])
        {
            kruskal(i.first, i.second, h + 1);
            depth[vertex] = min(depth[vertex], depth[i.first]);
        }
        else if (i.second != index)
            depth[vertex] = min(depth[vertex], depth[i.first]);
    }
    if (depth[vertex] == h)
        ans[index] = 2;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> src[i] >> dst[i] >> wt[i];
        index[i] = i;
    }
    sort(index + 1, index + m + 1, [&](int x, int y)
         { return wt[x] < wt[y]; });

    DSUmake();
    for (int i = 1; i <= m;)
    {
        int j = i;
        for (; wt[index[i] == wt[index[j]]]; j++)
        {
            int p1 = findParent(src[index[j]]);
            int p2 = findParent(dst[index[j]]);
            if (p1 != p2)
            {
                ans[index[j]] = 1;
                graph[p1].push_back({p2, index[j]});
                graph[p2].push_back({p1, index[j]});
            }
        }
        for (j = i; wt[index[i] == wt[index[j]]]; j++)
        {
            int v = findParent(src[index[j]]);
            if (!vis[v])
                kruskal(v, 0, 0);
        }
        for (j = i; wt[index[i] == wt[index[j]]]; j++)
        {
            Union(src[index[j]], dst[index[j]]);
        }
        i = j;
    }

    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
            cout << "none\n";
        if (ans[i] == 1)
            cout << "at least one\n";
        if (ans[i] == 2)
            cout << "any\n";
    }

    return 0;
}

/* #include <iostream>
#include <vector>
#include <algorithm>
#define N 100001
using namespace std;
int n, m, x[N], y[N], z[N], p[N];
int ans[N], f[N], h[N], pe[N], d[N];
vector<pair<int, int>> v[N];
bool cmp(const int &x, const int &y)
{
    return z[x] < z[y];
}
int par(int x)
{
    while (pe[x])
        x = pe[x];
    return x;
}
void uni(int x, int y)
{
    x = par(x);
    y = par(y);
    v[x].clear();
    v[y].clear();
    f[x] = 0;
    f[y] = 0;
    if (x == y)
        return;
    if (h[x] > h[y])
        pe[y] = x;
    else
    {
        pe[x] = y;
        if (h[x] == h[y])
            h[y]++;
    }
}
void add_edge(int x, int y, int i)
{
    if (x == y)
        return;
    ans[i] = 1;
    v[x].push_back({y, i});
    v[y].push_back({x, i});
}
void kruskal(int c, int g, int h)
{
    f[c] = true;
    d[c] = h;
    for (pair<int, int> i : v[c])
        if (!f[i.first])
        {
            kruskal(i.first, i.second, h + 1);
            d[c] = min(d[c], d[i.first]);
        }
        else if (i.second != g)
            d[c] = min(d[c], d[i.first]);
    if (d[c] == h)
        ans[g] = 2;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        p[i] = i;
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m;)
    {
        int j;
        for (j = i; z[p[j]] == z[p[i]]; j++)
            add_edge(par(x[p[j]]), par(y[p[j]]), p[j]);
        for (j = i; z[p[j]] == z[p[i]]; j++)
        {
            int k = par(x[p[j]]);
            if (!f[k])
                kruskal(k, 0, 0);
        }
        for (j = i; z[p[j]] == z[p[i]]; j++)
            uni(x[p[j]], y[p[j]]);
        i = j;
    }
    for (int i = 1; i <= m; i++)
        if (!ans[i])
            cout << "none" << endl;
        else if (ans[i] == 1)
            cout << "at least one" << endl;
        else
            cout << "any" << endl;
    return 0;
}


/*
You are given a connected weighted undirected graph without any loops and multiple edges.
Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.
Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.

Input Format:
The first line contains two space-separated integers n and m — the number of the graph's vertexes and edges, correspondingly.
 Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi", where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight.

Output Format:
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.

Constraints:
 1 <= N, M <= 10^5
 1 <= a, b <= N
 1 <= w[i] <= 10^6
 Graph is connected and does not contain self loops and multiple edges.

Sample Input:
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
Sample Output:
none
any
at least one
at least one
any
 /

#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5+5;

int src[N], dst[N], wt[N], idx[N];
int ans[N], visited[N], depth[N];
int parent[N], r[N];

vector<vector<pair<int, int>>> graph(N);


// initialize the rank of all elements 0 and make each node as it's parent
void make_set() {
    for(int i = 0 ; i < N ; ++i) {
        r[i] = 0;
        parent[i] = i;
    }
}

// This function is to get parent or set with path compression
int get_parent(int x) {
    while(x != parent[x]) {
        x = parent[x];
    }
    return x;
}

// This merging two sets.
// When we merge two sets we clear the previous graph as it's a new set now
void union_set(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    graph[x].clear();
    graph[y].clear();
    visited[x] = visited[y] = false;

    // marking parent using rank
    if(x != y) {
        if(r[x] == r[y]) ++r[x];
        if(r[x] < r[y]) swap(x, y);
        parent[y] = x;
    }
}

// To understand the forward and backward edge refer CodeNCode bridges video.
// We are using kruskal to find if the edges are bridge or not.
void kruskal(int v, int index, int h) {
    visited[v] = true;
    depth[v] = h;

    for(pair<int, int> p : graph[v]) {
        // forward edge
        if(!visited[p.first]) {
            kruskal(p.first, p.second, h+1);
            depth[v] = min(depth[v], depth[p.first]);
        }
        // backward edge
        else if(p.second != index) {
            depth[v] = min(depth[v], depth[p.first]);
        }
    }
    // if it's not a bridge, then this edge will come in all MST's.
    if(depth[v] == h) ans[index] = 2;
}

int main()
{
    //code
    int n, m;
    cin >> n >> m;

    // TAking input
    for(int i = 1 ; i <= m ; i++) {
        cin >> src[i] >> dst[i] >> wt[i];
        idx[i] = i;
    }

    // Sort edges on the basis of weight
    sort(idx+1, idx+m+1, [&](int x, int y) {
        return wt[x] < wt[y];
    });

    // calling to initialize
    make_set();

    for(int i = 1 ; i <= m ; ) {
        int j = i;
        // processing the edges collectively having same weight and forming a graph
        for(j = i ; wt[idx[i]] == wt[idx[j]] ; ++j) {
            int set1 = get_parent(src[idx[j]]);
            int set2 = get_parent(dst[idx[j]]);
            if(set1 != set2) {
                ans[idx[j]] = 1; // marking initially to tell they will be in "at least one".
                graph[set1].push_back({set2, idx[j]});
                graph[set2].push_back({set1, idx[j]});
            }
        }

        // Now the graph we made in previous step
        for(j = i ; wt[idx[i]] == wt[idx[j]] ; ++j) {
            int v = get_parent(src[idx[j]]);
            if(!visited[v]) {
                kruskal(v, 0, 0);
            }
        }

        // merging two sets
        for(j = i ; wt[idx[i]] == wt[idx[j]] ; ++j) {
            union_set(src[idx[j]], dst[idx[j]]);
        }

        i = j;
    }

    // Printing the corresponding answers.
    for(int i = 1 ; i <= m ; ++i) {
        if(ans[i] == 0) cout << "none" << endl;
        else if(ans[i] == 1) cout << "at least one" << endl;
        else cout << "any" << endl;
    }

    return 0;
} */