#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int modAdd(int n, int m)
{
    return ((n % mod) + (m % mod)) % mod;
}
int func(vector<int> &arr, int n)
{
    int ans = 0;
    unordered_map<int, int> mp[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            mp[i][diff] += 1;
            ans = (ans + 1) % mod;
        }
    }

    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            mp[i][diff] = modAdd(mp[i][diff], mp[j][diff]);
            ans = modAdd(ans, mp[j][diff]);
        }
    }
    return ans;
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = n + 1;
        ans += func(arr, n);

        cout << ans << endl;
    }
    return 0;
}