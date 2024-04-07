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
    double r1 = 1.0 * a.first/a.second;
    double r2 = 1.0 * b.first/b.second;
    return r1 > r2;
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
/*------------ASIMARIES------------*/

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(all(arr), pv);
    double ans = 0;
    int currW = 0;
    for (int i = 0; i < n; i++)
    {
        if (w == 0)
            break;
        if (w >= currW+arr[i].second)
        {
            ans += arr[i].first;
            currW += arr[i].second;
        }
        else
        {
            int remain = w - currW;
            double val = 1.0 * arr[i].first * ((double)remain / (double)arr[i].second);
            ans += val;
            break;
        }
    }
    cout << ans;
}