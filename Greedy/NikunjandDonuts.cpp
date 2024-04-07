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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(all(arr), gri);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int val = (1<< i);
        ans += (val * arr[i]);
    }
    cout << ans;
}
