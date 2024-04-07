#include <bits/stdc++.h>
using namespace std;

int func(int im, int in, string &m, string &n, vector<vector<int>> &dp)
{
    if (im == m.length())
    {
        return n.length() - in;
    }
    if (in == n.length())
    {
        return m.length() - im;
    }
    if (dp[im][in] != -1)
    {
        return dp[im][in];
    }
    if (m[im] == n[in])
    {
        return dp[im][in] = func(im + 1, in + 1, m, n, dp);
    }
    else
    {
        int sub = func(im + 1, in + 1, m, n, dp);
        int ins = func(im, in + 1, m, n, dp);
        int del = func(im + 1, in, m, n, dp);

        return dp[im][in] = 1 + min({sub, ins, del});
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string m;
        cin >> m;
        string n;
        cin >> n;
        int ml = m.length();
        int nl = n.length();
        vector<vector<int>> dp(ml, vector<int>(nl, -1));
        cout << func(0, 0, m, n, dp) << endl;
    }
    return 0;
}
