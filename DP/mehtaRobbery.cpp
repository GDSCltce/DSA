#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first;

        for (int i = 0; i < n; i++)
            cin >> arr[i].second;

        sort(arr.begin(), arr.end());

        int prime[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(w + 1, 0)));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[0][i][j] = dp[0][i - 1][j];
                if (j >= arr[i - 1].second)
                    dp[0][i][j] = max({dp[0][i][j], dp[0][i - 1][j - arr[i - 1].second] + arr[i - 1].first});
            }
        }

        int curr = 0;
        for (int p = 1; p <= 10; p++)
        {
            curr = p % 2;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= w; j++)
                {
                    dp[curr][i][j] = dp[curr][i - 1][j];
                    if (j >= arr[i - 1].second)
                    {
                        dp[curr][i][j] = max({dp[curr][i][j], dp[curr][i - 1][j - arr[i - 1].second] + arr[i - 1].first, dp[curr ^ 1][i - 1][j - arr[i - 1].second] + arr[i - 1].first * prime[p]});
                    }
                }
            }
        }

        cout << dp[0][n][w] << endl;
    }

    return 0;
}
