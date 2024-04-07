#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primes = {2};
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
            primes.emplace_back(i);
    return;
}

void printPrimes(int l, int r)
{
    vector<bool> primesLR(r - l + 1, 1);
    for (int i = 0; primes[i] * primes[i] <= r; i++)
    {
        int currPrime = primes[i];
        int base = (l / currPrime) * currPrime;
        if (base < l)
            base = base + currPrime;

        for (int j = base; j <= r; j += currPrime)
            primesLR[j - l] = false;

        if (base == currPrime)
            primesLR[base - l] = true;
    }
    for (int i = 0; i <= r - l; i++)
    {
        if (primesLR[i])
            cout << i + l << " ";
    }
}

signed main()
{
    __sieve();
    freopen("out.in", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        printPrimes(l, r);
        cout << endl;
    }
    return 0;
}