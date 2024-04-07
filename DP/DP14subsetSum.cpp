#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int n, int sum, vector<int> &arr,
           vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (i >= n || sum < 0)
        return false;

    bool nonpick = solve(i + 1, n, sum, arr, dp);
    bool pick = false;
    if (arr[i] <= sum)
        pick = solve(i + 1, n, sum - arr[i], arr, dp);

    return dp[i][sum] = (pick || nonpick);
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
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        // cout << solve(0, n, sum, arr, dp);
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = 1;
        // for (int i = 0; i < n; i++)
        //     dp[i][0] = true;

        //     dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool nonpick = prev[j];
                bool pick = false;
                if (arr[i] <= j)
                    pick = prev[j - arr[i]];

                curr[j] = pick || nonpick;
            }
            prev = curr;
        }
        cout << prev[sum] << endl;
    }
    return 0;
}