#include <bits/stdc++.h>
using namespace std;
#define int long long

int frog1R(vector<int> &arr, int i)
{
    if (i == 0)
        return 0;

    int jump1 = abs(arr[i] - arr[i - 1]) + frog1R(arr, i - 1);
    int jump2 = INT_MAX;
    if (i > 1)
        jump2 = abs(arr[i] - arr[i - 2]) + frog1R(arr, i - 2);
    return min(jump1, jump2);
}

int frog1TD(vector<int> &arr, int i, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int jump1 = abs(arr[i] - arr[i - 1]) + frog1TD(arr, i - 1, dp);
    int jump2 = INT_MAX;
    if (i > 1)
        jump2 = abs(arr[i] - arr[i - 2]) + frog1TD(arr, i - 2, dp);
    return dp[i] = min(jump1, jump2);
}

int frog1BU(vector<int> &arr)
{
    int n = arr.size();
    // vector<int> dp(n + 2, -1);
    // dp[0] = 0;
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = abs(arr[i] - arr[i - 1]) + prev1; // dp[i - 1];
        if (i > 1)
            cost = min(cost, abs(arr[i] - arr[i - 2]) + prev2); // dp[i - 2]);
        prev2 = prev1;
        prev1 = cost;
    }
    return prev1; // dp[n - 1];
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // vector<int> dp(n + 3, -1);
        // cout << frog1TD(arr, n - 1, dp) << endl;
        cout << frog1BU(arr) << endl;
    }
    return 0;
}
