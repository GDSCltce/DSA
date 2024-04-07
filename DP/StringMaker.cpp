#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[52][52][52];
const int mod = 1e9 + 7;
int solver(string a, string b, string c)
{
    if (c.length() == 0)
        return 1;

    if (a.length() <= 0 && b.length() <= 0)
        return 0;
    
    if (dp[a.length()][b.length()][c.length()] != -1)
        return dp[a.length()][b.length()][c.length()];
    
    int ans = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == c[0])
            ans += solver(a.substr(i + 1), b, c.substr(1)), ans %= mod;
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == c[0])
            ans += solver(a, b.substr(i + 1), c.substr(1)), ans %= mod;
    }
    return dp[a.length()][b.length()][c.length()] = ans % mod;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << solver(a, b, c) % mod << endl;
    }
    return 0;
}
