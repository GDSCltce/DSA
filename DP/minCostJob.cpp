#include <bits/stdc++.h>
using namespace std;
int memo[101];
int func(vector<vector<int>> &arr, int i, int mask, int n)
{
    if (i == n)
        return 0;

    if (memo[mask] != -1)
        return memo[mask];

    int ans = 1e9;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {
            ans = min(ans, arr[j][i] + func(arr, i + 1,
                                            (mask ^ (1 << j)), n));
        }
    }
    return memo[mask] = ans;
}

int funcI(vector<vector<int>> &arr, int n)
{
    int maskk = (1 << n);
    int dp[maskk];
    memset(dp, INT_MAX, sizeof dp);
    dp[0] = 0;
    for (int mask = 0; mask < (maskk - 1); mask++)
    {
        int temp = mask;
        int k = 0;
        while (temp > 0)
        {
            if ((temp % 2) == 1)
                k++;
            temp /= 2;
        }

        for (int j = 0; j < n; j++)
        {
            if (!(mask & (1 << j)))
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + arr[k][j]);
            }
        }
    }
    return dp[maskk - 1];
}

int main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        memset(memo, -1, sizeof memo);
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        cout << func(arr, 0, (1 << n) - 1, n) << endl;
        cout << funcI(arr, n) << endl;
    }

    return 0;
}
