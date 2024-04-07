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
/*------------ASIMARIES------------*/
bool comppv(const pair<int, int> &a, const pair<int, int> &b)
{
    // if (a.second == b.second)
    //     return a.first < b.first;
    return a.second < b.second;
}

void solve();

signed main()
{
    // #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //     freopen("out.in", "w", stdout);
    // #endif
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
/*------------ASIMARIES------------*/

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(all(a), comppv);
    int ans = 1;
    int last = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (last <= a[i].first)
        {
            ++ans;
            last = a[i].second;
        }
    }
    cout << ans;
}
