#include <bits/stdc++.h>
using namespace std;
#define int long long

double distance(pair<double, double> x, pair<double, double> y)
{
    double a, b;
    a = (y.first - x.first) * (y.first - x.first);
    b = (y.second - x.second) * (y.second - x.second);
    return sqrt(a + b);
}

double hasanNtrip(vector<pair<double, double>> &arr, vector<double> &happy, int n, vector<double> &dp)
{
    if (n == 0)
        return happy[0];
    if (dp[n] != INT_MIN)
        return dp[n];
    double ans = -9034802484938;
    for (int i = 0; i < n; i++)
    {
        double x = distance(arr[i], arr[n]);
        double t = hasanNtrip(arr, happy, i, dp);
        ans = max(ans, t - x);
    }
    return dp[n] = happy[n] + ans;
}

signed main()
{
    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<double, double>> arr(n);
        vector<double> happy(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second >> happy[i];

        vector<double> dp(n, INT_MIN);
        cout << hasanNtrip(arr, happy, n - 1, dp) << endl;
    }
    return 0;
}
/*
void solve(pair<double, double> arr[], double happy[], int n)
{
    double dp[n];
    dp[0] = happy[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = -inf;
        for (int j = 0; j < i; j++)
        {
            double x = dis(arr[i], arr[j]); // Find distance between i and j
            dp[i] = max(dp[i], dp[j] - x);  // Maximize over all possible differences
        }
        dp[i] += happy[i];
    }
    cout << fixed;
    cout << setprecision(6) << dp[n - 1] << endl;
    return;
}*/
