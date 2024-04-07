#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1000001;
vector<int> prime = {2}, num(MAX);

void __sieve(int n = 1000000)
{
    vector<bool> __PRIME;
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; ++p)
        if (__PRIME[p])
            for (int i = p * p; i <= n; i += p)
                __PRIME[i] = false;

    for (int i = 3; i < __PRIME.size(); i += 2)
        if (__PRIME[i])
            prime.emplace_back(i);
    return;
}
vector<int> phi(MAX);
signed main()
{
    __sieve();
    cout << fixed << setprecision(6);
    int t = 1;
    int l, r, k;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> k;
        if (k == 1)
        {
            cout << 1.0 << endl;
            continue;
        }
        for (int i = l; i <= r; i++)
        {
            phi[i - l] = i;
            num[i - l] = i;
        }
        for (int i = 0; prime[i] * prime[i] <= r; i++)
        {
            int base = l / prime[i] * prime[i];
            while (base < l)
                base += prime[i];
            while (base < prime[i])
                base += prime[i];
            if (base == prime[i])
                base += prime[i];
            for (int j = base; j <= r; j += prime[i])
            {
                while (num[j - l] % prime[i] == 0)
                    num[j - l] /= prime[i];
                phi[j - l] -= phi[j - l] / prime[i];
            }
        }
        for (int i = l; i <= r; i++)
        {
            if (num[i - l] > 1)
                phi[i - l] -= phi[i - l] / num[i - l];
            num[i - l] = 1;
        }
        int c = 0;
        for (int i = l; i <= r; i++)
        {
            if (phi[i - l] % k == 0)
                c++;
        }
        double ans = c;
        ans /= (r - l + 1);
        cout << ans << endl;
    }
    return 0;
}
