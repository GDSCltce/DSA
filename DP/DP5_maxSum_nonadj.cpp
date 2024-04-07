#include <bits/stdc++.h>
using namespace std;
#define int long long

int maxSum(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == 0)
        return nums[i];
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int pick = nums[i] + maxSum(nums, i - 2, dp);
    int nonpick = maxSum(nums, i - 1, dp);

    return dp[i] = max(pick, nonpick);
}

signed main()
{
    freopen("in.in", "r", stdin);

    int t = 1;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n + 3, -1);
        // cout << maxSum(arr, n - 1, dp) << endl;
        // dp[0] = arr[0];
        // for (int i = 1; i < n; i++)
        // {
        //     int pick = arr[i];
        //     if (i > 1)
        //         pick += dp[i - 2];
        //     int nonpick = dp[i - 1];
        //     dp[i] = max(pick, nonpick);
        // }
        int prev2 = arr[0], prev1 = max(arr[0], arr[1]), curr = prev1;
        for (int i = 2; i < n; i++)
        {
            int pick = arr[i] + prev2;
            int nonpick = prev1;
            curr = max(pick, nonpick);
            prev2 = prev1;
            prev1 = curr;
        }

        cout << curr << endl;
    }
    return 0;
}
