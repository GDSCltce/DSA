#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int MAXN = 1 << 17;
void build(int arr[], int n, pair<int, int> segtree[])
{
    for (int i = 0; i < n; i++)
    {
        segtree[MAXN + i] = make_pair(arr[i], i);
    }
    for (int i = MAXN - 1; i > 0; i--)
    {
        segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
    }
}
int get(int l, int r, pair<int, int> segtree[])
{
    pair<int, int> ans = {-1, -1};
    for (l += MAXN, r += MAXN + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            ans = max(ans, segtree[l++]);
        if (r & 1)
            ans = max(ans, segtree[--r]);
    }
    return ans.second;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        arr[i] -= 1;
    }
    arr[n - 1] = n - 1;
    pair<int, int> segtree[4 * MAXN];
    build(arr, n, segtree);
    ll dp[n];
    ll ans = 0;
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int m = get(i + 1, arr[i], segtree);
        dp[i] = dp[m] - (arr[i] - m) + n - i - 1;

        ans += dp[i];
    }
    cout << ans << endl;
}