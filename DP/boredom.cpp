#include <bits/stdc++.h>
using namespace std;
#define int long long
int boredom(vector<int> &arr, int n)
{
    vector<int> dp(100001);
    vector<int> freq(100001);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    dp[1] = freq[1];

    for (int i = 2; i <= 100000; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }
    return dp[100000];
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << boredom(arr, n) << endl;
    }
    return 0;
}
