#include <bits/stdc++.h>
using namespace std;
#define int long long

int _LDS(vector<int> &arr, int i, vector<int> &dp)
{
    if (i == (int)arr.size() - 1)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    int n = arr.size();
    for (int j = i; j < n; ++j)
    {
        if (arr[j] < arr[i])
        {
            ans = max(ans, _LDS(arr, j, dp) + 1);
        }
    }
    return dp[i] = ans;
}

int LDS(vector<int> &arr, int n)
{
    vector<int> dp(n + 3, -1);
    dp[n - 1] = 1;
    int mx = INT_MIN;
    for (int i = n - 2; i >= 0; --i)
    {
        mx = max(mx, _LDS(arr, i, dp));
    }
    return mx;
}

int LDSBU(vector<int> &arr, int n)
{
    vector<int> dp(n + 1, -1);
    dp[n - 1] = 1;
    int mx = INT_MIN, ans = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        ans = 1;
        for (int j = i; j < n; ++j)
        {
            if (arr[j] < arr[i])
            {
                ans = max(ans, dp[j] + 1);
            }
        }
        mx = max(mx, ans);
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

        cout << LDSBU(arr, n) << endl;
    }
    return 0;
}
