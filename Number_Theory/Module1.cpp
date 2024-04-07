#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a;
    cin >> a;
    string b;
    cin >> b;
    int mod = 0;
    for (int i = 0; i < b.length(); i++)
    {
        mod = (mod * 10 + b[i] - '0');
    }
    cout << __gcd(a, mod);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}