#include <bits/stdc++.h>
using namespace std;
#define int long long

int frogTD(vector<int> &arr, int i, int k, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int jump = INT_MAX;
    for (int j = 1; j <= k; j++)
        if (i - j >= 0)
            jump = min(jump, abs(arr[i] - arr[i - j]) + frogTD(arr, i - j, k, dp));

    return dp[i] = jump;
}

int frogBU(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int jump = INT_MAX;
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
                jump = min(jump, abs(arr[i] - arr[i - j]) + dp[i - j]);

        dp[i] = jump;
    }
    return dp[n - 1];
}

signed main()
{
    // freopen("in.in", "r", stdin);

    int t = 1;
    // cin >> t;
    int n, k, x;
    while (t--)
    {
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.emplace_back(x);
        }
        // vector<int> dp(n + 3, -1);
        // dp[0] = -1;
        cout << frogBU(arr, k) << endl;
    }
    return 0;
}
