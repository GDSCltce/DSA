#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000000
vector<vector<int>> table(11, vector<int>(MAX, 0));
void sieve(int n = MAX)
{
    vector<int> sieve(MAX, 0);
    for (int i = 2; i <= MAX; i++)
    {
        if (sieve[i] == 0)
            for (int j = 1; j * i <= MAX; j++)
                sieve[j * i]++;
    }

    for (int i = 0; i < 11; i++)
    {
        table[i][0] = 0;
        table[i][1] = 0;
        for (int j = 2; j <= MAX; j++)
        {
            if (sieve[j] == i)
                table[i][j] = table[i][j - 1] + 1;
            else
                table[i][j] = table[i][j - 1];
        }
    }
}
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if (a == 1 && n == 0)
    {
        cout << 1;
        return;
    }
    cout << table[n][b] - table[n][a - 1];
}

signed main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}