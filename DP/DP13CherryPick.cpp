#include <bits/stdc++.h>
using namespace std;

int solve(int i_level, int j1, int j2, int endn, int endm, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
{
    if (i_level > endn || j1 < 0 || j2 < 0 || j1 > endm || j2 > endm)
        return -1e8;

    if (i_level == endn)
    {
        if (j1 == j2)
            return arr[i_level][j1];
        else
            return arr[i_level][j1] + arr[i_level][j2];
    }

    if (dp[i_level][j1][j2] != -1)
        return dp[i_level][j1][j2];

    int ans = 0;
    int mx = INT_MIN;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            ans = solve(i_level + 1, j1 + i, j2 + j, endn, endm, arr, dp);
            if (j1 == j2)
            {
                ans += arr[i_level][j1];
            }
            else
            {
                ans += arr[i_level][j1] + arr[i_level][j2];
            }
            mx = max(mx, ans);
        }
    }
    return dp[i_level][j1][j2] = mx;
}

int solveBU(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = arr[n - 1][j1];
            else
                dp[n - 1][j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int mx = INT_MIN;
                for (int di = -1; di < 2; di++)
                {
                    for (int dj = -1; dj < 2; dj++)
                    {
                        int ans = 0;
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans = -1e9;
                        else
                            ans = dp[i + 1][j1 + di][j2 + dj];
                        if (j1 == j2)
                        {
                            ans += arr[i][j1];
                        }
                        else
                        {
                            ans += arr[i][j1] + arr[i][j2];
                        }
                        mx = max(mx, ans);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }

    return dp[0][0][m - 1];
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
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // int ans = solve(0, 0, m - 1, n - 1, m - 1, arr, dp);
        // cout << ans << endl;
        /*BOTTOM-UP*/

        cout << solveBU(arr) << endl;
    }

    return 0;
}