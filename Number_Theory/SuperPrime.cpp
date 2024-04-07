#include <bits/stdc++.h>
using namespace std;

vector<bool> __PRIME;
void __sieve(int n = 1000009)
{
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; p++)
        if (__PRIME[p])
            for (int i = p * p; i <= n; i += p)
                __PRIME[i] = false;
    return;
}

vector<int> getDIVISORS(int n)
{
    vector<int> ans;
    int sqt = sqrt(n);
    for (int i = 1; i <= sqt; i++)
        if (n % i == 0)
            if (n / i == i)
                ans.emplace_back(i);
            else
                ans.emplace_back(n / i);

    return ans;
}

signed main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    int cp = 0, cnp = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        if (__PRIME[i])
            ++cp;
        else
            ++cnp;
    }
    cout << min(cp, cnp) << " " << max(cp, cnp) << endl;

    return 0;
}
// def solve(n) : isPrime = [True for i in range(n + 1)] primeCount = [0 for i in range(n + 1)] for i in range(2, n + 1) : if (isPrime[i] == True) : j = 2 while(j * i <= n) : isPrime[i * j] = False primeCount[i * j] += 1 j += 1 ans = 0 for i in range(1, n + 1) : if(primeCount[i] == 2) : ans += 1 return ans
