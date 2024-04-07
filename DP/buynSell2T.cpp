#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            mx += arr[i] - arr[i - 1];
        }
    }
    return mx;
}

int main()
{
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
    }
    return 0;
}