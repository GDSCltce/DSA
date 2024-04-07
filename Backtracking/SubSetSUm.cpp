#include <bits/stdc++.h>
using namespace std;

int generate(vector<int> &arr, int i, int k, int ans)
{
    if (i == (int)arr.size())
    {
        if (k == 0)
        {
            ans++;
        }
        return ans;
    }
    ans = generate(arr, i + 1, k - arr[i], ans);
    ans = generate(arr, i + 1, k, ans);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << generate(arr, 0, k, 0) << endl;
    }
    return 0;
}