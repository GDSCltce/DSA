#include <bits/stdc++.h>
using namespace std;
#define int long long

int fib(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
        return n;
    if (dp[n])
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

signed main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 3);
    cout << fib(n, dp);
    fill(dp.begin(), dp.end(), 0);
    dp[1] = 1;
    int prev1 = 0, prev2 = 1, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        ans = prev1 + prev2;
        prev1 = prev2;
        prev2 = ans;
    }
    cout << " " << dp[n] << " " << prev2;
    // for (auto &i : dp)
    // {
    //     cout << i << " ";
    // }
    return 0;
}
