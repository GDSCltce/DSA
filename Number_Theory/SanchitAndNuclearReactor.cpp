#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int m)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        res %= m;
    }
    return res % m;
}

int main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n < m)
        {
            if (m - t == 1)
            {
                cout << 1;
            }
            else
            {
                cout << factorial(n, m);
            }
        }
        else
        {
            int last = n % m;
            int fact = factorial(last, m) % m;
            if ((n / m) % 2 == 0)
            {
                cout << fact;
            }
            else
            {
                cout << ((m - 1) % m * fact % m) % m;
            }
        }
        cout << endl;
    }
    return 0;
}