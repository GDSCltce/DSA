#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);

    int ans1 = lcs(a, b, n, m - 1, dp);
    int ans2 = lcs(a, b, n - 1, m, dp);
    return dp[n][m] = max(ans1, ans2);
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string a; cin >> a;
        string b; cin >> b;
        int n = a.length();
        int m = b.length();
        vector <vector <int> > dp(n+1, vector <int> (m+1, -1));
        cout << lcs(a, b, n, m, dp) << endl;
    }
    return 0;
}