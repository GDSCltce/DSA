#include <bits/stdc++.h>
using namespace std;
#define int long long

int minChocolate(vector<int> &arr, int n, vector<int> &dp)
{
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; --i)
    {
        if (arr[i + 1] < arr[i] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    int sum = accumulate(dp.begin(), dp.end(), 0);
    return sum;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 1);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minChocolate(arr, n, dp) << endl;
    }
    return 0;
}
