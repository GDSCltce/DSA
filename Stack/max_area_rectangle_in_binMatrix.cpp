#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
// const int mod = 1e9+7;
inline void solve();

int32_t main()
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

int mah(vector<int> &arr)
{
    int n = arr.size(), curr, res = INT_MIN, tp;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(curr, res);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(curr, res);
    }
    return res;
}

inline void solve()
{
    int n, m, res = INT_MIN;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    vector<int> newarr(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                newarr[j] = 0;
            }
            else
            {
                newarr[j] += arr[i][j];
            }
        }
        // for (int j = 0; j < m; j++)
        // {
        //     cout << newarr[j] << ' ';
        // }
        // cout << endl;
        res = max(res, mah(newarr));
    }

    cout << res;
}
