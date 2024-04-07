#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int modAdd(int n, int m)
{
    return ((n % mod) + (m % mod)) % mod;
}
int modSubtract(int n, int m)
{
    return ((n % mod) - (m % mod)) % mod;
}
int modMultiple(int n, int m)
{
    return ((n % mod) * (m % mod)) % mod;
}

int rec(string &s, int i, int sum, unordered_map<char, int> &count, vector<int> &dp)
{
    if (i == s.length())
        return 0;
    int cur = (1 + sum - count[s[i]] + mod) % mod;
    sum = (sum + cur) % mod;
    return dp[i-1] = cur;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> count(26, 0);
        vector<int> dp(n + 1);
        int sum = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int index = s[i] - 'A';
        //     int cur = (1 + sum - count[index] + mod) % mod;
        //     sum = (sum + cur) % mod;
        //     count[index] = (count[index] + cur) % mod;
        // }
        // cout << sum + 1 << endl;
        cout << rec(s, 0, sum, count);
    }
    return 0;
}
