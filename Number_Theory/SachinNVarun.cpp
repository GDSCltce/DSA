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
int modInverse(int a, int m)
{
    int x = exEuclid(a, m).x;
    return (x % m + m) % m;
}

void solve()
{
    int a, b, d;
    cin >> a >> b >> d;
    // int rangea = d / a, rangeb = d / b;
    // for (int x = 0; x <= rangea; x++)
    // {
    //     for (int y = 0; y <= rangeb; y++)
    //     {
    //         if ((a * x + b * y) == d)
    //             ++cnt;
    //     }
    // }
    int g = __gcd(a, b);
    if (d % g)
    {
        cout << 0;
        return;
    }
    if (d == 0)
    {
        cout << 1;
        return;
    }
    a /= g;
    b /= g;
    d /= g;

    int y1 = ((d % a) * modInverse(b, a)) % a;
    int firstValue = d / b;

    if (d < y1 * b)
    {
        cout << 0;
        return;
    }
    int n = (firstValue - y1) / a;
    cout << n + 1;
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