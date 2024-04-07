#include <bits/stdc++.h>
using namespace std;

signed main()
{
    freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool nonpick = prev[j];
                bool pick = false;
                if (arr[i] <= j)
                    pick = prev[j - arr[i]];

                curr[j] = pick || nonpick;
            }
            prev = curr;
        }
        int mn = 1e9;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (prev[i] == true)
            {
                mn = min(mn, abs((sum - i) - i));
            }
        }
        cout << mn;
    }

    return 0;
}