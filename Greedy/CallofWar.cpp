#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define lINF 100000000000000000
#define int long long
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
bool pv(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
    return a.second < b.second;
}
/*------------ASIMARIES------------*/

int n;
void solve();
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
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

int idx(int i) { return i % n; }

void solve()
{
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int val = min(a[i], b[i - 1]) - min(a[0], b[n - 1]);
        v.push_back({val, i});
    }
    sort(all(v));
    int index = 0;
    if (v.size() > 0 && v[0].first < 0)
        index = v[0].second;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[index];
        int damage = b[index];
        index = idx(index + 1);
        a[index] = max(0LL, a[index] - damage);
    }
    cout << ans;
}
