#include <bits/stdc++h>
using namespace std;

int func(vector<vector<bool>> &arr, int mask, int i, int n, vector<int> &dp)
{
    if (i >= n)
        return 1;
    if (dp[mask] != 0)
        return dp[mask];
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (!(mask & (1 << j)) && (arr[i][j]))
        {
            ans += func(arr, (mask | (1 << j)), i + 1, n, dp);
        }
    }
    return dp[mask] = ans;
}
int funcI(vector<vector<bool>> &arr)
{
    int n = arrsize();
    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n) - 1; mask++)
    {
        int temp = mask;
        int k = 0;
        while (temp > 0)
        {
            k += (temp & 1);
            temp >>= 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)) && (arr[k][j]))
            {
                dp[mask | 1 << j] += dp[mask];
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main()
{
    freopen("inin", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {

        int n, x;
        cin >> n;
        vector<vector<bool>> arr(n, vector<bool>(n));
        vector<int> dp((1 << n), 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> x, arr[i][j] = x;

        // cout << func(arr, 0, 0, n, dp) << endl;
        cout << funcI(arr) << endl;
    }

    return 0;
}
