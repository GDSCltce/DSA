#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr, int i, int buyorsell, int k, vector<vector<vector<int>>> &dp)
{
    if (i >= arr.size() || k == 0)
    {
        return 0;
    }

    if (dp[i][buyorsell][k] != -1)
    {
        return dp[i][buyorsell][k];
    }

    int profit = 0;
    if (buyorsell == 0)
    {
        int buy = maxProfit(arr, i + 1, 1, k, dp) - arr[i];
        int nobuy = maxProfit(arr, i + 1, 0, k, dp);
        profit = max(buy, nobuy);
    }
    else
    {
        int sell = maxProfit(arr, i + 1, 0, k - 1, dp) + arr[i];
        int nosell = maxProfit(arr, i + 1, 1, k, dp);
        profit = max(sell, nosell);
    }
    return dp[i][buyorsell][k] = profit;
}

int main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        cout << maxProfit(arr, 0, 0, k, dp) << endl;
    }
    return 0;
}