#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &arr, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n || j < 0 || j >= m)
    {
        return 1e9;
    }
    if (i == n - 1)
    {
        return arr[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int left, right, down;
    left = arr[i][j] + func(arr, i + 1, j - 1, n, m, dp);
    down = arr[i][j] + func(arr, i + 1, j, n, m, dp);
    right = arr[i][j] + func(arr, i + 1, j + 1, n, m, dp);

    return dp[i][j] = min({left, down, right});
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 1e9;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, func(arr, 0, i, n, m, dp));
        }
        cout << ans << endl;
    }
    return 0;
}