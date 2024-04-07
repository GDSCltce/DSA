#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int subsetcnt = (1 << n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < subsetcnt; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                sum += arr[j];
        }
        if (sum == k)
            ans++;
    }
    cout << ans;
    return 0;
}
