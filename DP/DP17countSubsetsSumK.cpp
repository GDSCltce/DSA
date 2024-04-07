#include <bits/stdc++.h>
using namespace std;

int solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0 || arr[0] == sum)
            return 1;
        return 0;
    }
    if (sum < 0 || i < 0)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int nonpick = solve(i - 1, sum, arr, dp);
    int pick = solve(i - 1, sum - arr[i], arr, dp);

    return dp[i][sum] = pick + nonpick;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int n, sum;
        cin >> n >> sum;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        // cout << solve(n - 1, sum, arr, dp);

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int nonpick = dp[i - 1][j];
                int pick = 0;
                if (arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];

                dp[i][j] = pick + nonpick;
            }
        }
        cout << dp[n - 1][sum];
    }
    return 0;
}