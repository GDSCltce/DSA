#include <bits/stdc++.h>
using namespace std;
vector<int> phi;
void eulerTotientN(int n = 1000000) // phi(n) from 1 to n, where n <= 10^6
{
    for (int i = 0; i <= n; ++i)
        phi.emplace_back(i);

    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
        {
            phi[i] -= 1;
            for (int p = 2 * i; p <= n; p += i)
                phi[p] /= i, phi[p] *= i - 1;
        }
    return;
}

int getCount(int d, int n)
{
    return phi[n / d];
}

int main()
{
    eulerTotientN();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int d1 = i;
                int d2 = n / i;
                res += d1 * getCount(d1, n);
                if (d1 != d2)
                    res += d2 * getCount(d2, n);
            }
        }
        cout << res;
    }
    return 0;
}
