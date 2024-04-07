#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dpp(100, -1);

int MSO(int n)
{
    // Base Case
    if (n == 1)
        return 0;
    // already computed
    if (dpp[n] != -1)
        return dpp[n];
    int res = MSO(n - 1);
    if (n % 3 == 0)
        res = min(res, MSO(n / 3));
    if (n % 2 == 0)
        res = min(res, MSO(n / 2));

    return dpp[n] = res + 1;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 3);
    cout << MSO(n);
    for (int i = 0; i < n; i++)
        cout << "{" << i << " " << dpp[i] << "} ";
    fill(dp.begin(), dp.end(), 0);
    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {
        int a, b, c;
        a = b = c = INT_MAX;
        c = dp[i - 1];
        if (n % 3 == 0)
            a = dp[i / 3];
        if (n % 2 == 0)
            b = dp[i / 2];
        dp[i] = min({a, b, c}) + 1;
    }
    cout << dp[n];

    return 0;
}
