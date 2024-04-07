#include <bits/stdc++.h>
using namespace std;
#define int long long
#define amx 100001
#define MOD 1000000007

signed main()
{
    int n, x, t, sum1, sum2;
    cin >> n;
    vector<int> dpl(amx), dph(amx), a(amx);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        t = 100000;
        sum1 = 0, sum2 = 0;
        for (; t > 0; t -= (t & -t))
        {
            sum1 = (sum1 + dph[t] + a[t]) % MOD;
        }
        t = x;
        for (; t > 0; t -= (t & -t))
        {
            sum1 = (sum1 - dph[t] - a[t] + MOD) % MOD;
        }
        t = x - 1;
        for (; t > 0; t -= (t & -t))
        {
            sum2 = (sum2 + dpl[t] + a[t]) % MOD;
        }
        t = x;
        for (; t < amx; t += (t & -t))
        {
            dpl[t] = (dpl[t] + sum1) % MOD;
            dph[t] = (dph[t] + sum2) % MOD;
            a[t] += 1;
        }
    }
    int ans = 0;
    sum1 = sum2 = 0;
    t = amx - 1;
    for (; t > 0; t -= (t & -t))
    {
        ans = (ans + dph[t]) % MOD;
        ans = (ans + dpl[t]) % MOD;
    }
    cout << ans;

    return 0;
}
