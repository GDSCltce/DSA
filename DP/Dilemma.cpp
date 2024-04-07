#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[102][1 << 12];
int func(vector<string> &arr, int mask, int pos, int n)
{
    if (__builtin_popcount(mask) == 1)
        return 0;

    if (pos == -1 || mask == 0)
        return 1e9;

    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    
    int mask1 = 0, mask2 = 0, touch = 0;
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1)
        {
            ++touch;
            if (arr[i][pos] == '0')
            {
                mask1 |= (1 << i);
            }
            else
            {
                mask2 |= (1 << i);
            }
        }
    }
    return dp[pos][mask] = min(func(arr, mask1, pos - 1, n) + func(arr, mask2, pos - 1, n) + touch,
     func(arr, mask, pos - 1, n));
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << func(arr, (1 << n) - 1, arr[0].length() - 1, n) << endl;
    }
    return 0;
}
