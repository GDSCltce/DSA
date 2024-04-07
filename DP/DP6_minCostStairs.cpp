#include <bits/stdc++.h>
using namespace std;
#define int long long

int minCostClimbingStairsHelper(vector<int> &arr, int i, vector<int> &dp)
{
    if (i == 0 || i == 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int jump1 = arr[i - 1] + minCostClimbingStairsHelper(arr, i - 1, dp);
    int jump2 = arr[i - 2] + minCostClimbingStairsHelper(arr, i - 2, dp);

    return dp[i] = min(jump1, jump2);
}

signed main()
{
    freopen("in.in", "r", stdin);   
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n + 3, -1);
        cout << minCostClimbingStairsHelper(arr, n, dp) << endl;
    }
    return 0;
}
