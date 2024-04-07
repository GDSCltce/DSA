#include <bits/stdc++.h>
using namespace std;
#define int long long

int _LIS(vector<int> &arr, int n, vector<int> &dp)
{
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

int _LDS(vector<int> &arr, int n, vector<int> &dp)
{
    int mx = INT_MIN, ans = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        ans = 1;
        for (int j = n - 1; j > i; j--)
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

int maxbitonic(vector<int> &arr, int n)
{
    if (n == 1)
        return 1;
    vector<int> dplis(n + 3, -1), dplds(n + 3, -1);
    dplis[0] = dplds[n - 1] = 1;

    _LDS(arr, n, dplds);
    _LIS(arr, n, dplis);

    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
        mx = max(mx, dplds[i] + dplis[i] - 1);

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

        cout << maxbitonic(arr, n) << endl;
    }
    return 0;
}
