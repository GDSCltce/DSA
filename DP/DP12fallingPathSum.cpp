#include <bits/stdc++.h>
using namespace std;

int solve(int si, int sj, int endn, int endm, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (sj < 0 || si > endn || sj > endm)
    {
        return -1e9;
    }
    if (si == endn)
        return arr[si][sj];
    if (dp[si][sj] != -1e9)
        return dp[si][sj];
    int down = arr[si][sj] + solve(si + 1, sj, endn, endm, arr, dp);
    int left = arr[si][sj] + solve(si + 1, sj - 1, endn, endm, arr, dp);
    int right = arr[si][sj] + solve(si + 1, sj + 1, endn, endm, arr, dp);

    return dp[si][sj] = max({down, left, right});
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
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int ans = -1e9;
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, solve(0, i, n - 1, m - 1, arr, dp));
        }
        cout << ans << endl;

        /*BOTTOM-UP*/

        // vector<vector<int>> dp(n, vector<int>(m));
        // dp[0] = arr[0];
        vector<int> prev = arr[0];
        vector<int> curr(m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = arr[i][j] + prev[j];

                int left = arr[i][j];
                if (j - 1 >= 0)
                    left += prev[j - 1];
                else
                    left += -1e9;

                int right = arr[i][j];
                if (j + 1 < m)
                    right += prev[j + 1];
                else
                    right += -1e9;

                curr[j] = max(up, max(left, right));
            }
            prev = curr;
        }
        ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, prev[i]);
        }
        cout << ans << endl;
    }

    return 0;
}