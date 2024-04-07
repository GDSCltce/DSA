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
    // freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
    cout << fixed << setprecision(6);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
int n;
void bfs(vector<int> graph[], vector<int> &st, bool vis[], int vertex)
{
    queue<int> q;
    q.push(vertex);
    st.emplace_back(vertex);
    vis[vertex] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto &i : graph[curr])
        {
            if (!vis[i])
            {
                st.emplace_back(i);
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

void dfs(vector<int> graph[], vector<int> &ans, bool vis[], int vertex)
{
    ans.emplace_back(vertex);
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            dfs(graph, ans, vis, i);
    }
}

void getCC(vector<int> graph[], vector<vector<int>> &ans, int n)
{
    bool vis[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> stt;
            dfs(graph, stt, vis, i);
            ans.emplace_back(stt);
        }
    }
}

void solve()
{
    int m;
    cin >> n >> m;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];

    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    vector<vector<int>> cc;
    getCC(graph, cc, n);
    bool flag = 1;
    for (auto &vec : cc)
    {
        unordered_set<int> pst, qst;
        for (auto &i : vec)
            pst.insert(p[i]);
        for (auto &i : vec)
            qst.insert(q[i]);
        if (pst != qst)
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
}
