#include <bits/stdc++.h>
using namespace std;
// #define int long long
// int dp[20][20];
int solve(int si, int sj, int end,
          vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (si > end)
        return 1e9;
    if (si == end)
        return arr[si][sj];
    if (dp[si][sj] != -1e9)
        return dp[si][sj];
    int down = 0, diag = 0;
    down = arr[si][sj] + solve(si + 1, sj, end, arr, dp);
    diag = arr[si][sj] + solve(si + 1, sj + 1, end, arr, dp);

    return dp[si][sj] = min(down, diag);
}

signed main()
{
    freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n;
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.emplace_back(vector<int>());
            for (int j = 0; j <= i; j++)
            {
                cin >> x;
                arr[i].emplace_back(x);
            }
        }

        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        cout << solve(0, 0, n - 1, arr, dp) << endl;

        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = arr[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        cout << dp[0][0] << endl;
    }

    return 0;
}