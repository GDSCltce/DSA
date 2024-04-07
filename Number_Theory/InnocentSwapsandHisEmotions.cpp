#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
const int MAX = 1000001;

vector<int> facts(MAX);
int ModExpo(int a, int b, int m = mod)
{
    a %= m;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a, res %= m;
        a *= a, a %= m;
        b >>= 1;
    }
    return res % m;
}

void factorial()
{
    int res = 1;
    for (int i = 1; i < MAX; i++)
    {
        res *= i, res %= mod;
        facts[i] = res;
    }
    return;
}
signed main()
{
    int t = 1;
    cin >> t;
    factorial();
    while (t--)
    {
        int k, n;
        cin >> n >> k;
        // cout <<k << n;
        int ans = facts[n];
        ans = (ans * ModExpo(2, k)) % mod;
        ans = (ans * ModExpo(facts[k], mod - 2)) % mod;
        ans = (ans * ModExpo(facts[n - k], mod - 2)) % mod;

        cout << ans << endl;
    }
    return 0;
}