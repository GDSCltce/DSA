#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<vector<int>>> &dp, int cnt)
{
    if (n == 0 || m == 0)
        return cnt;
    if (dp[n][m][cnt] != -1)
        return dp[n][m][cnt];
    int same = cnt;
    if (a[n - 1] == b[m - 1])
        same = lcs(a, b, n - 1, m - 1, dp, cnt + 1);

    int ans1 = lcs(a, b, n, m - 1, dp, 0);
    int ans2 = lcs(a, b, n - 1, m, dp, 0);
    return dp[n][m][cnt] = max({ans1, ans2, same});
}

int main()
{
    string a = "abcdgh";
    string b = "abedfhr";
    int n = a.length();
    int m = b.length();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(min(m, n) + 1, -1)));
    cout << lcs(a, b, n, m, dp, 0);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (a[n - i] == b[m - j])
    //             dp[i][j] = 1 + dp[i - 1][j - 1];

    //         else
    //             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    //     }
    // }
    // cout << dp[n][m];
    return 0;
}