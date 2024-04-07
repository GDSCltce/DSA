#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define int long long
#define mod (int)1000000007
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
int fact[1000000];

void solve();
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
    cout << fixed << setprecision(6);
    fact[0] = 1;
    for (int i = 1; i <= 10000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        // cout << fact[i] << " ";
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}

int dir[8][2] = {{-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}};
bool valid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int getcc(vector<vector<bool>> &graph, vector<vector<bool>> &vis, int i, int j)
{
    vis[i][j] = true;
    int ans = 1;
    for (int k = 0; k < 8; k++)
    {
        int newx = i + dir[k][0];
        int newy = j + dir[k][1];
        if (valid(newx, newy, graph.size(), graph[0].size()) && graph[newx][newy] && !vis[newx][newy])
        {
            ans = (ans + getcc(graph, vis, newx, newy)) % mod;
        }
    }
    return ans % mod;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> graph(n, vector<bool>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x - 1][y - 1] = 1;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && graph[i][j])
            {
                vis[i][j] = 1;
                int val = getcc(graph, vis, i, j);
                ans = (ans * fact[val]) % mod;
            }
        }
    }
    cout << ans << endl;
}
