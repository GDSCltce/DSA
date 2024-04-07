#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &fee, vector<int> &fun, int budget, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (fee[0] <= budget)
            return fun[0];
        return 0;
    }
    if (dp[i][budget] != -1)
        return dp[i][budget];

    int pick = 0;
    if (budget >= fee[i])
        pick = fun[i] + solve(i - 1, fee, fun, budget - fee[i], dp);

    int nonpick = solve(i - 1, fee, fun, budget, dp);

    return dp[i][budget] = max(pick, nonpick);
}

int main()
{
    int n;
    cin >> n;
    vector<int> fee(n);
    vector<int> fun(n);
    for (int i = 0; i < n; i++)
        cin >> fee[i];
    for (int i = 0; i < n; i++)
        cin >> fun[i];
    int budget;
    cin >> budget;

    vector<vector<int>> dp(n, vector<int>(budget + 1, -1));
    for (int i = 0; i <= budget; i++)
    {
        solve(n - 1, fee, fun, i, dp);
    }
    
    int ans = solve(n - 1, fee, fun, budget, dp);
    int currmin = 1e9;
    for (int i = 0; i <= budget; i++)
        if (dp[n - 1][i] == ans)
        {
            currmin = i;
            break;
        }
    cout << currmin << " " << ans << endl;
    return 0;
}