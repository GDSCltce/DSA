#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 750001;
const int mod = 1e9 + 7;

void solve()
{
    int n, mx = -1e9;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(arr[i], mx);
    }
    // sort(arr.begin(), arr.end());
    vector<int> sieve(mx + 1);
    for (int i = 0; i < n; i++)
    {
        sieve[arr[i]] = 1;
    }
    for (int i = 0; i <= mx; i++)
    {
        if (sieve[i] > 0)
            for (int j = 2 * i; j <= mx; j += i)
            {
                if (sieve[j] > 0)
                    sieve[j] = (sieve[j] + sieve[i]) % mod;
            }
    }
    int cnt = 0;
    for (int i = 0; i <= mx; i++)
    {
        cnt = (cnt + sieve[i]) % mod;
    }
    cout << cnt;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}