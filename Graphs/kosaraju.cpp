#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define int long long
#define mod 1000000007
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
#define inarr(x)      \
    for (auto &i : x) \
        cin >> i;
#define printarr(x)   \
    for (auto &i : x) \
        cout << i << ' ';
bool pv(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
    return a.second < b.second;
}
/*------------ASIMARIES------------*/
void solve();
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
    cout << fixed << setprecision(6);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}

void dfs1(vector<int> graph[], int vertex, bool vis[], stack<int> &stk)
{
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            dfs1(graph, i, vis, stk);
    }
    stk.push(vertex);
}

void dfs2(vector<int> graph[], int vertex, bool vis[], vector<int> &stk)
{
    vis[vertex] = true;
    stk.emplace_back(vertex);
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            dfs2(graph, i, vis, stk);
    }
}

void getSCC(vector<int> graph[], vector<int> graphT[], vector<vector<int>> &ans, int n)
{
    bool vis[n] = {0};
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs1(graph, i, vis, stk);
    }
    memset(vis, 0, n);
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        if (!vis[curr])
        {
            vector<int> temp;
            dfs2(graphT, curr, vis, temp);
            ans.emplace_back(temp);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n], graphT[n];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x - 1].emplace_back(y - 1);
        graphT[y - 1].emplace_back(x - 1);
    }
    vector<vector<int>> ans;
    getSCC(graph, graphT, ans, n);

    // print
    for (auto &vec : ans)
    {
        for (auto &i : vec)
            cout << i << " ";
        cout << endl;
    }
}
