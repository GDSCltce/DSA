#include <bits/stdc++.h>
using namespace std;

int solve(int si, int sj, int ei, int ej, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (si > ei || sj > ej || arr[si][sj] == -1)
        return 0;
    if (si == ei && sj == ej)
        return 1;
    if (dp[si][sj] != -1)
        return dp[si][sj];
    int down = 0, right = 0;
    down = solve(si + 1, sj, ei, ej, arr, dp);
    right = solve(si, sj + 1, ei, ej, arr, dp);
    return dp[si][sj] = down + right;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));
        // cout << solve(0, 0, n - 1, m - 1, arr, dp) << endl;
        dp[0][0] = 1;
        int up, left;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == -1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }

        cout << dp[n - 1][m - 1] << endl;
    }

    return 0;
}