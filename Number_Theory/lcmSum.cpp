#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000000
int res[MAX + 3], phi[MAX + 3];

signed main()
{
    int mx = MAX;
    for (int i = 1; i <= mx; i++)
        phi[i] = i;

    for (int i = 2; i <= mx; i++)
        if (phi[i] == i)
        {
            phi[i] /= i, phi[i] *= i - 1;
            for (int p = 2 * i; p <= mx; p += i)
                phi[p] /= i, phi[p] *= (i - 1);
        }

    for (int i = 1; i <= mx; i++)
    {
        for (int j = i; j <= mx; j += i)
            res[j] += phi[i] * i;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = (res[n] - 1) * n;
        ans /= 2;
        cout << ans + n << endl;
    }

    return 0;
}
