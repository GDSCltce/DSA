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
struct jobs
{
    int start, end, profit;
};
bool pv(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
    return a.second < b.second;
}
bool compare(const jobs &a, const jobs &b)
{
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
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
    int n;
    cin >> n;
    vector<jobs> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].profit;
    }

    sort(all(arr), compare);
    vector<int> dp(n);
    dp[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        int including = arr[i].profit;
        int lNconflict = -1;
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid].end <= arr[i].start)
            {
                if (arr[mid + 1].end <= arr[i].start)
                    low = mid + 1;
                else
                {
                    lNconflict = mid;
                    break;
                }
            }
            else
            {
                high = mid - 1;
            }
        }
        /* for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j].end <= arr[i].start)
            {
                lNconflict = j;
                break;
            }
        } */
        if (lNconflict != -1)
        {
            including += dp[lNconflict];
        }
        dp[i] = max(including, dp[i - 1]);
    }
    cout << dp[n - 1];
}
