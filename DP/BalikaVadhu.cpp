#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int kcs(string &a, string &b, int n, int m, int k)
{
    if (n == 0 || m == 0)
    {
        if (k > 0)
            return -1e9;
        return 0;
    }
    if (dp[n][m][k] != -1)
        return dp[n][m][k];
    if (a[n - 1] == b[m - 1])
    {
        int ans1 = kcs(a, b, n - 1, m - 1, k - 1);
        int ans2 = kcs(a, b, n - 1, m, k);
        int ans3 = kcs(a, b, n, m - 1, k);
        if (k > 0)
            return dp[n][m][k] = max({a[n - 1] + ans1, ans2, ans3});
        return 0;
    }
    return dp[n][m][k] = max(kcs(a, b, n - 1, m, k), kcs(a, b, n, m - 1, k));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int k;
        cin >> k;
        int n = a.length();
        int m = b.length();
        memset(dp, -1, sizeof(dp));
        int ans = kcs(a, b, n, m, k);
        cout << max(0, ans) << endl;
    }
    return 0;
}
