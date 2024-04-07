#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int i, vector<int> &dp, map<int, int> &freq)
{
    if (i >= arr.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int next_index = -1;
    auto index = lower_bound(arr.begin() + i, arr.end(), arr[i] + 2);
    if (index != arr.end())
        next_index = index - arr.begin();

    int a1 = arr[i] * freq[arr[i]] + func(arr, i, dp, freq);
    int a2 = func(arr, i, dp, freq);
    return dp[i] = max(a1, a2);
}

int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    map<int, int> freq;
    for (auto &i : nums)
        freq[i]++;
    return func(nums, 0, dp, freq);
}

int boredom(vector<int> &arr, int n, vector<int> &dp, map<int, int> &freq)
{
    sort(arr.begin(), arr.end());
    dp[0] = 0;
    dp[1] = freq[1];

    for (int i = 2; i <= 1e5; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }
    return dp[n - 1];
}

int main()
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
            cin >> arr[i];

        cout << deleteAndEarn(arr) << endl;
    }

    return 0;
}
