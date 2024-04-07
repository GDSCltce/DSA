#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 3 || arr[i] == 4 || arr[i] == 6)
            dp[i] = 1;
        dp[i] += dp[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}