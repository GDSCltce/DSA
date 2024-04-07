#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9 + 7;
int dp[500][500][500];
int solve(vector<int> &arr, int idx, int gcd, int prev)
{
    if (idx < 0)
    {
        if (gcd == 1)
            return 1;
        return 0;
    }
    if (dp[idx][gcd][prev] != -1)
        return dp[idx][gcd][prev];
    int ans = 0;
    ans = solve(arr, idx - 1, gcd, prev);
    if (prev == arr.size() || arr[idx] < arr[prev])
    {
        ans = ans + solve(arr, idx - 1, __gcd(gcd, arr[idx]), idx);
    }
    return dp[idx][gcd][prev] = ans % mod;
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(arr, n - 1, 0, n) << endl;
    }
    return 0;
}
/*
int fun(int index, int g, int prev, vector<int> v)
{
    if (index < 0)
    {
        if (g == 1)
            return 1;
        return 0;
    }

    if (dp[index][g][prev] != -1)
        return dp[index][g][prev];
    int ans = 0;
    ans = fun(index - 1, g, prev, v);
    if (prev == v.size() || v[index] < v[prev])
        ans = ans + fun(index - 1, __gcd(g, v[index]), index, v);
    return dp[index][g][prev] = ans % mod;
}

int main()
{
    int num;
    cin >> num;
    vector<int> v(num);
    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << fun(v.size() - 1, 0, v.size(), v) << "\n";
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long mod = pow(10, 9) + 7;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; cin >> a[i++])
        ;
    long long dp[n][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i][a[i]] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
            {
                for (int k = 1; k <= 100; k++)
                {
                    int g = __gcd(a[i], k);
                    dp[i][g] = (dp[i][g] % mod + dp[j][k] % mod) % mod;
                }
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + dp[i][1]) % mod;
    }

    cout << sum;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll dp[501][101][501];

// 3D DP ARRAY BECAUSE to keep track of (index,gcd,previous index) ==> previous index is necessary to ensure the subsequence is increasing

ll fun(ll index, ll g, ll prev, vector<ll> v)
{

    if (index < 0)
    {

        if (g == 1)
            return 1;

        return 0;
    }

    if (dp[index][g][prev] != -1)
        return dp[index][g][prev];

    ll ans = 0;

    ans = fun(index - 1, g, prev, v);

    if (prev == v.size() || v[index] < v[prev])
        ans = ans + fun(index - 1, __gcd(g, v[index]), index, v);

    return dp[index][g][prev] = ans % mod;
}

int main()
{

    ll num;

    cin >> num;
    vector<ll> v(num);

    for (int i = 0; i < num; i++)
    {

        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << fun(v.size() - 1, 0, v.size(), v) << "\n";

    return 0;
}
*/