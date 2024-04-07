#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
typedef long long ll;
#define all(x) (x).begin(), (x).end()
// const int mod = 1e9+7;
inline void solve();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    // int t;
    // scanf("%d", &t);
    // while (t--)
    {
        solve();
    }
    return 0;
}
/*************************************/

inline void solve()
{
    int n, span;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "brute: ";
    for (int i = 0; i < n; i++)
    {
        span = 0;
        for (int j = i; j >= 0 && arr[i] >= arr[j]; j--)
        {
            span++;
        }
        cout << span << " ";
    }

    cout << "\nOPtimal: ";
    stack<int> s;
    vector<int> ans(n);
    ans[0] = 1;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        ans[i] = (s.empty() ? i+1: i-s.top());
        s.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        // ans[i] = i - ans[i];
        cout << ans[i] << ' ';
    }
}
