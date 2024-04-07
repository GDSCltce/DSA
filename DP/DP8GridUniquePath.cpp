#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][20];
int solve(int si, int sj, int ei, int ej)
{
    if (si > ei || sj > ej)
        return 0;
    if (si == ei && sj == ej)
        return 1;
    if (dp[si][sj] != -1)
        return dp[si][sj];
    int down = solve(si + 1, sj, ei, ej);
    int right = solve(si, sj + 1, ei, ej);
    return dp[si][sj] = down + right;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        // int ans = solve(0, 0, m - 1, n - 1);
        dp[0][0] = 1;
        int up, left;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }

        cout << dp[n - 1][m - 1] << endl;
    }

    return 0;
}