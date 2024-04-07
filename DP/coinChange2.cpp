#include <bits/stdc++.h>
using namespace std;
// #define int long long

int func(vector<int> &arr, int n, int amount, vector<vector<int>> &dp)
{
    if (amount < 0 || n == arr.size())
    {
        return 0;
    }
    if (amount == 0)
        return 1;
    if (dp[n][amount] != -1)
        return dp[n][amount];
    int ways = 0;
    for (int j = n; j < arr.size(); j++)
    {
        ways += func(arr, j, amount - arr[j], dp);
    }
    return dp[n][amount] = ways;
}

int coinChange(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int ans = func(arr, 0, amount, dp);
    return ans;
}

int coinChangeBU(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    int ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= amount; j++)
        {
            int x = (j - arr[i - 1] >= 0) ? dp[i][j - arr[i - 1]] : 0;
            int y = dp[i - 1][j];
            dp[i][j] = (x + y);
        }
    }
    return dp[n][amount];
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, amount;
        cin >> n >> amount;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << coinChangeBU(arr, amount) << endl;
    }
    return 0;
}
