#include <bits/stdc++.h>
using namespace std;
#define int long long

void coinBoxes(vector<int> &arr, vector<int> &cnt, vector<int> &dp, int n)
{
    int curr = 0;
    for (int i = 1; i <= n; i++)
    {
        curr += cnt[i];
        arr[i] = curr;
        dp[curr]++;
    }

    for (int i = 1; i <= 1000001; i++)
    {
        dp[i] += dp[i - 1];
    }
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<int> cnt(n + 1);
        for (int i = 0; i < m; i++)
        {
            int s, e;
            cin >> s >> e;
            cnt[s]++, cnt[e + 1]--;
        }
        vector<int> arr(1000001);
        vector<int> dp(1000001);
        coinBoxes(arr, cnt, dp, n);

        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            if (x == 0)
                cout << n << endl;
            else
                cout << n - dp[x - 1] << endl;
        }
    }
    return 0;
}
