#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}
typedef long long ll;
// const int mod = 1e9+7;
inline void solve();

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    int t;
    // scanf("%d", &t); while (t--)
    {
        solve();
    }
    return 0;
}
/*************************************/

inline void solve()
{
    int n;
    cin >> n;
    int k = 4;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0, mx = -1;
    for (int i = 0; i <= n - k; i++)
    {
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += arr[i + j];
        }
        mx = max(mx, sum);
    }
    cout << mx;
    mx = 0;
    sum = 0;
    for (int i = 0; i < k; i++)
    {
        mx += arr[i];
    }
    sum = mx;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        mx = min(sum, mx);
    }
    cout << mx;
}
