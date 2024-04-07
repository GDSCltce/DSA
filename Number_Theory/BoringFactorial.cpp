#include <bits/stdc++.h>
using namespace std;
#define int long long


class Triplet
{
public:
    int x, y, gcd;
    Triplet(int _x, int _y, int _gcd) { x = _x, y = _y, gcd = _gcd; }
};
Triplet exEuclid(int a, int b)
{
    if (b == 0)
    {
        Triplet ans(1, 0, a);
        return ans;
    }
    Triplet dash = exEuclid(b, a % b);
    Triplet ans(dash.y, (dash.x - ((a / b) * dash.y)), dash.gcd);
    return ans;
}
int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}
int modInverse(int a, int m)
{
    int x = exEuclid(a, m).x;
    return (x % m + m) % m;
    // return power(a, m - 2, m);
}

int modfact(int n, int p)
{
    if (p <= n)
        return 0;
    int res = p - 1;
    for (int i = n + 1; i < p; i++)
    {
        res = (res * modInverse(i, p)) % p;
    }
    return res;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        cout << modfact(n, p) << endl;
    }
    return 0;
}