#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int a, string b, int mod)
{
    // reverse(b.begin(), b.end());
    int res = 1;
    int i = b.length();
    while (--i > -1)
    {
        if (b[i] == '0')
            ;
        if (b[i] == '1')
            res = (res * a) % mod;
        if (b[i] == '2')
            res = (((res * a) % mod) * a) % mod;

        a = (((a * a) % mod) * a) % mod;
    }
    return res % mod;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, m;
        string b;
        cin >> a >> b >> m;
        int ans = power(a, b, m);
        cout << ans << endl;
    }
    return 0;
}