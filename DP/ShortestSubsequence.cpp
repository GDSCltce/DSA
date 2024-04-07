#include <bits/stdc++.h>
using namespace std;

int shortestSub(string &a, string &b, int m, int n, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        if (m != 0)
            return 1;
        return 1e9;
    }
    if (dp[m][n] != -1)
        return dp[m][n];
    int k;
    for (k = n; k > 0; k--)
        if (a[m - 1] == b[k - 1])
            break;

    if (k == 0)
        return 1;
    int ans1 = 1 + shortestSub(a, b, m - 1, k - 1, dp);
    int ans2 = shortestSub(a, b, m - 1, n, dp);
    return dp[m][n] = min(ans1, ans2);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = shortestSub(a, b, m, n, dp);
        cout << ((min(n, m) <= ans) ? -1 : ans) << endl;
    }
    return 0;
}