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

void clearStack(stack<int> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

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

int maxAreaHistoN2(vector<int> &arr)
{
    int res = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for (int j = i + 1; j < n && arr[i] <= arr[j]; j++)
        {
            curr += arr[i];
        }
        for (int j = i - 1; j >= 0 && arr[i] <= arr[j]; j--)
        {
            curr += arr[i];
        }
        res = max(curr, res);
    }
    return res;
}

inline void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxAreaHistoN2(arr);
    stack<int> s;
    int tp, curr = 0;
    // vector<int> ans(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    cout << endl << res;
}
