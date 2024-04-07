#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define int long long
vector< int> S(MAX), G(MAX);
vector<int> phi(MAX);
void eulerTotientN()
{
    // phi(n) from 1 to n, where n <= 10^6
    phi[1] = 1;
    for (int i = 2; i < MAX; i += 2)
        phi[i] = i/2;

    for (int i = 3; i < MAX; i += 2)
        if (!phi[i])
        {
            phi[i] = i - 1;
            for (int p = 2 * i; p < MAX; p += i)
            {
                if (!phi[p])
                    phi[p] = p;
                phi[p] = phi[p]/ i * (i - 1);
            }
        }
    return;
}

signed main()
{
    eulerTotientN();
    
        S= phi;
    
    
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 2; j * i < MAX; j++)
        {
            S[i * j] += j * phi[i];
        }
    }
    G[1] = 0;
    for (int i = 2; i < MAX; i++)
    {
        G[i] = G[i - 1] + S[i];
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << G[n] << endl;
    }
    return 0;
}