#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &temp, int n)
{
    int curr = 0;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr += temp[i];
        if (mx < curr)
            mx = curr;
        if (curr < 0)
            curr = 0;
    }
    return mx;
}

int maxSum(vector<vector<int>> &arr, int n, int m)
{
    int sum = INT_MIN;
    for (int l = 0; l < m; l++)
    {
        vector<int> temp(n, 0);
        for (int r = l; r < m; r++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] += arr[i][r];
            }
            sum = max(sum, kadane(temp, n));
        }
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        cout << maxSum(arr, n, m) << endl;
    }
    return 0;
}