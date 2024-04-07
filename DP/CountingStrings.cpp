#include <bits/stdc++.h>
using namespace std;

#define int long long
int dp[100005];
const int mod = 1e9 + 7;

int modAdd(int n, int m)
{
    return ((n % mod) + (m % mod)) % mod;
}

int solver(string s)
{
    int req = 0, ans = 0, n = s.size();
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = 'Z' - s[i];

    dp[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        req = modAdd(arr[i + 1], (26 * req));
        dp[i] = modAdd(arr[i], (arr[i] * req));
    }

    for (int i = 0; i < n; i++)
        ans += dp[i], ans %= mod;

    return ans;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        memset(dp, 0, sizeof dp);
        cout << solver(s) % mod << endl;
    }
    return 0;
}


 And if there exist multiple values, then we have to consider the largest value of timestamp.
So for this, we will perform a binary search on the array of objects of class ‘DATA’ as pointed by the given value of targetKey and find the required value of timestamp.
In binary search, if the value of timestamp at the middle of the array is equal to the targettimestamp then return the value of ‘VAL’ which is at the location with the value of targettimestamp in the array. If the value of timestamp is greater than the value targettimestamp then reduce the search space from the right by one. Otherwise, increase the search space from left by one.
If no answer is returned from the above step then return the value of ‘VAL’ which is at the last value of mid calculated from the above operation in the array of objects of class ‘DATA’.