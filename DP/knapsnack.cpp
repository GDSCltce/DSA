#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &weight, vector<int> &value, int maxW, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weight[0] <= maxW)
            return value[0];
        return 0;
    }
    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    int pick = 0;
    if (maxW >= weight[i])
        pick = value[i] + solve(i - 1, weight, value, maxW - weight[i], dp);
    int nonpick = solve(i - 1, weight, value, maxW, dp);

    return dp[i][maxW] = max(pick, nonpick);
}

int main()
{
    freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    int maxW;
    cin >> maxW;

    vector<vector<int>> dp(n, vector<int>(maxW + 1, -1));
    cout << solve(n - 1, weight, value, maxW, dp);

    vector<vector<int>> dp(n, vector<int>(maxW + 1, 0));
    for (int i = weight[0]; i <= maxW; i++)
        dp[0][i] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxW; j++)
        {
            int nonpick = dp[i - 1][j];
            int pick = 0;
            if (j >= weight[i])
                pick = value[i] + dp[i - 1][j - weight[i]];

            dp[i][j] = max(pick, nonpick);
        }
    }
    cout << dp[n - 1][maxW];
    return 0;
}