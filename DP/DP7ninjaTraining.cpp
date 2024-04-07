#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &points, int index, int last, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
            if (last != i)
                maxi = max(points[0][i], maxi);
        return dp[index][last] = maxi;
    }
    if (dp[index][last] != -1)
        return dp[index][last];

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
        if (last != i)
            maxi = max(points[index][i] + func(points, index - 1, i, dp), maxi);

    return dp[index][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = func(points, n - 1, 3, dp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

int ninjaTrainingBU(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    int ans = INT_MIN, maxi = INT_MIN;
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last <= 3; last++)
        {
            dp[day][last] = 0;
            int maxi = -1;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    dp[day][last] = max(points[day][task] + dp[day - 1][task], dp[day][last]);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> arr[i][j];

        cout << ninjaTrainingBU(n, arr) << endl;
    }

    return 0;
}
