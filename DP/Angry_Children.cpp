#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> sum(n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    int unfairness = 0, start = 0, end = k - 1;
    for (int i = 1; i <= end; i++)
    {
        unfairness += i * arr[i] - sum[i - 1];
    }
    int currfairness = unfairness;
    start++, end++;
    while (end < n)
    {
        currfairness += (end - start) * arr[end] - sum[end - 1] + sum[start - 1];
        currfairness -= sum[end - 1] - sum[start - 1] - (end - start) * arr[start - 1];

        unfairness = min(currfairness, unfairness);
        start++, end++;
    }

    cout << unfairness << endl;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}