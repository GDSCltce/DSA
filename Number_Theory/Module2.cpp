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
int main()
{

    return 0;
}