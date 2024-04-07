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
    int n;
    cin >> n;
    vector<int> arr(n);
    // vector<int> ans(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    vector<int> anss(n);
    // for (int i = 0; i < n; i++)
    // {
    //     if (!s.empty())
    //     {
    //         while (!s.empty() && s.top() >= arr[i])
    //         {
    //             s.pop();
    //         }
    //     }
    //     anss[i] = (s.empty() ? -1 : s.top());
    //     s.push(arr[i]);
    // }
    // for (auto i : anss)
    // {
    //     cout << i << ' ';
    // }

    cout << "\nNearest Smaller element to right: \n";
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while ((!s.empty()) && s.top() >= arr[i])
        {
            s.pop();
        }

        anss[i] = (s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    for (auto i : anss)
    {
        cout << i << ' ';
    }
}
