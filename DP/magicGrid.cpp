#include <bits/stdc++.h>
using namespace std;

int magrid(vector<vector<int>> &arr,
           int si, int sj, int ei, int ej,
           vector<vector<int>> &dp)
{
    if (si == ei - 1 && sj == ej - 1)
        return 1;
    if (si >= ei || sj >= ej)
        return INT_MAX;
    if (dp[si][sj] != -1)
        return dp[si][sj];
    int down = magrid(arr, si + 1, sj, ei, ej, dp);
    if (down != INT_MAX)
    {
        down -= arr[si + 1][sj];
    }
    int right = magrid(arr, si, sj + 1, ei, ej, dp);
    if (right != INT_MAX)
    {
        right -= arr[si][sj + 1];
    }
    int ans = min(down, right);
    if (ans <= 0) // if at any point health becomes negative
    {
        return dp[si][sj] = 1;
    }
    return dp[si][sj] = ans;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        cout << magrid(arr, 0, 0, n, m, dp) << endl;
    }

    return 0;
}
