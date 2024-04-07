#include <bits/stdc++.h>
using namespace std;

int minsalary(vector<pair<int, int>> &arr, int i, int c, int a, vector<vector<int>> &dp)
{
    if (i == arr.size())
        return 0;

    if (dp[i][c] != -1)
        return dp[i][c];

    int ans1, ans2;
    ans1 = ans2 = 1e9;

    if (c)
        ans1 = arr[i].first + minsalary(arr, i + 1, c - 1, a, dp);
    if (a)
        ans2 = arr[i].second + minsalary(arr, i + 1, c + 1, a - 1, dp);

    return dp[i][c] = min(ans1, ans2);
}

int main()
{
    // freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        cout << minsalary(arr, 0, 0, n / 2, dp) << endl;
    }
    return 0;
}
