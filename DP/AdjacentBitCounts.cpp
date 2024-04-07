#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int dp[101][101][2];

int func(int n, int k, int prev)
{
    if (dp[n][k][prev] != -1)
        return dp[n][k][prev];
    if (1 == n)
    {
        if (k == 0)
        {
            dp[n][k][prev] = 1;
            return 1;
        }
        else
        {
            return dp[n][k][prev] = 0;
            return 0;
        }
    }
    if (k < 0)
    {
        dp[n][k][prev] = 0;
        return 0;
    }
    if (prev)
    {
        int ans1 = func(n - 1, k - 1, 1) % mod;
        int ans2 = func(n - 1, k, 0) % mod;
        dp[n][k][prev] = (ans1 + ans2) % mod;
    }
    else
    {
        int ans1 = func(n - 1, k, 1) % mod;
        int ans2 = func(n - 1, k, 0) % mod;
        dp[n][k][prev] = (ans1 + ans2) % mod;
    }
    return dp[n][k][prev];
}

int solve(int n, int k)
{
    int ans2 = func(n, k, 1) % mod;
    int ans1 = func(n, k, 0) % mod;
    return (ans1 + ans2) % mod;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= 101; i++)
        {
            for (int j = 0; j <= 101; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << solve(n, k) << endl;
    }
    return 0;
}
