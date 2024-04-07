#include <bits/stdc++.h>
using namespace std;
#define int long long

int minCount1(int n, int sum, vector<int> &dp)
{
    if (sum > n)
    {
        return 0;
    }
    if (sum == n)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += minCount1(n, sum + i * i, dp);
    }
    return ans;
}

int minCount(int n, vector<int> &dp)
{

    if ((int)sqrt(n) * (int)sqrt(n) == n)
        return 1;
    if (n <= 3)
        return n;

    if (dp[n] != -1)
        return dp[n];
    int ans = 10000000000000;
    for (int i = 1; i <= n; i++)
    {
        if (i * i > n)
            break;
        ans = min(ans, 1 + minCount(n - i * i, dp));
    }
    return dp[n] = ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        cout << minCount(n, dp) << endl;
    }
    return 0;
}
