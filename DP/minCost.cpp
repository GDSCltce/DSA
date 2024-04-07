#include <bits/stdc++.h>
using namespace std;
// #define int long long
int func(vector<vector<int>> &arr, int si, int sj, int ei, int ej, vector<vector<int>> &dp)
{
    if (si > ei || sj > ej)
    {
        return INT_MAX;
    }
    if (si == ei && sj == ej)
    {
        return arr[ei][ej];
    }
    if (dp[si][sj] != -1)
        return dp[si][sj];
    int right = func(arr, si, sj + 1, ei, ej, dp);
    // int diagonal = func(arr, si + 1, sj + 1, ei, ej, dp);
    int down = func(arr, si + 1, sj, ei, ej, dp);

    return dp[si][sj] = arr[si][sj] + min(right, down);
}

int minCostPath(vector<vector<int>> &arr, int si, int sj, int ei, int ej)
{
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return func(arr, si, sj, ei, ej, dp);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        cout << minCostPath(arr, 0, 0, n - 1, m - 1) << endl;
    }
    return 0;
}
