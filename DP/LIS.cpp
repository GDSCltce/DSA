#include <bits/stdc++.h>
using namespace std;
#define int long long

int _LIS(vector<int> &arr, int i, vector<int> &dp)
{
    if (i == 0)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = i - 1; j >= 0; --j)
    {
        if (arr[j] < arr[i])
        {
            ans = max(ans, _LIS(arr, j, dp) + 1);
        }
    }
    return dp[i] = ans;
}

int LIS(vector<int> &arr, int n)
{
    vector<int> dp(n + 3, -1);
    dp[0] = 1;
    int mx = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, _LIS(arr, i, dp));
    }
    return mx;
}

int LISBU(vector<int> &arr, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    int mx = INT_MIN, ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = 1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] < arr[i])
            {
                ans = max(ans, dp[j] + 1);
            }
        }
        mx = max(ans, mx);
        dp[i] = ans;
    }
    return mx;
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

        cout << LISBU(arr, n) << endl;
    }
    return 0;
}
