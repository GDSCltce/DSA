#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
vector<int> primes;
void __sieve(int n = 1000009)
{
    vector<bool> __PRIME;
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; p++)
        if (__PRIME[p])
            for (int i = p * p; i <= n; i += p)
                __PRIME[i] = false;

    for (int i = 0; i < __PRIME.size(); i++)
    {
        if (__PRIME[i])
            primes.emplace_back(i);
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    int res = 1;
    for (int i = 0; primes[i] <= n; i++)
    {
        int k = primes[i];
        int cnt = 0;
        while ((n / k) != 0)
        {
            cnt = (cnt + (n / k)) % MOD;
            k = k * primes[i];
        }
        res = (res * ((cnt + 1) % MOD) % MOD);
    }
    cout << res;
}

signed main()
{
    int t = 1;
    cin >> t;
    __sieve();
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
