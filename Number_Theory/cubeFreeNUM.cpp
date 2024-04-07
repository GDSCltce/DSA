#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
vector<int> __PRIME;
void __sieve(int n = 1000000)
{
    __PRIME.resize(n + 1, 1);
    __PRIME[0] = 0;
    __PRIME[1] = 1;
    for (int p = 2; p * p * p <= n; p++)
    {
        if (__PRIME[p] == 1)
        {
            for (int i = p * p * p; i <= n; i += p * p * p)
            {
                __PRIME[i] = 0;
            }
        }
    }
    int k = 1;
    for (int i = 0; i < __PRIME.size(); i++)
    {
        if (__PRIME[i] != 0)
        {
            __PRIME[i] = k;
            k++;
        }
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    if (__PRIME[n] != 0)
    {
        cout << __PRIME[n];
    }
    else
    {
        cout << "Not Cube Free";
    }
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
