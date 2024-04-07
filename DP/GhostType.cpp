#include <bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> possible[22];
int dp[1 << 22];

int func(int mask, int n)
{
    if (mask == (1 << (n + 1)) - 2)
        return 1;
    if (dp[mask] != -1)
        return dp[mask];
    int ans = 0, x;
    for (int i = 1; i <= n; i++)
    {
        if (!(mask & (1 << i)))
        {
            bool ok = 1;
            for (int j = 0; j < possible[i].size(); j++)
            {
                x = possible[i][j];
                if (!(mask & (1 << x)))
                    ok = 0;
            }
            if (ok)
            {
                ans += func(mask | (1 << i), n);
            }
        }
    }
    return dp[mask] = ans;
}

signed main()
{

    int n;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i < 21; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if ((i & j) == j)
                possible[i].push_back(j);
        }
    }
    cin >> n;
    cout << func(0, n);
    return 0;
}