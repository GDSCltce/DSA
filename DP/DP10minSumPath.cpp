#include <bits/stdc++.h>
using namespace std;
// #define int long long
// int dp[20][20];
int solve(int si, int sj, int ei, int ej,
          vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (si > ei || sj > ej)
        return 1e9;
    if (si == ei && sj == ej)
        return arr[si][sj];

    if (dp[si][sj] != -1)
        return dp[si][sj];

    int down = 0, right = 0;
    down = arr[si][sj] + solve(si + 1, sj, ei, ej, arr, dp);
    right = arr[si][sj] + solve(si, sj + 1, ei, ej, arr, dp);
    return dp[si][sj] = min(down, right);
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
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // cout << solve(0, 0, n - 1, m - 1, arr, dp) << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = arr[i][j];
                else
                {
                    int up = arr[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9;
                    int left = arr[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left += 1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        cout << dp[n - 1][m - 1] << endl;
    }

    return 0;
}