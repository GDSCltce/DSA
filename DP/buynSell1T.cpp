#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
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
        int buy = 0, sell = 0, ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[buy] > arr[i])
            {
                buy = i;
            }
            else
            {
                ans = max(ans, arr[i] - arr[buy]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}