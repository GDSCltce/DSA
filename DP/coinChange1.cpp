#include <bits/stdc++.h>
using namespace std;
#define int long long

int subset(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for (auto &coin : coins)
        if (amount - coin >= 0)
            ans = min(ans + 0LL, subset(coins, amount - coin, dp) + 1LL);

    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 2, -1);
    int change = subset(coins, amount, dp);
    return change == INT_MAX ? -1 : change;
}

signed main()
{
    freopen("in.in", "r", stdin);
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

        cout << coinChange(arr, 5) << endl;
    }
    return 0;
}
