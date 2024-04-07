#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <forward_list>
#include <list>
#include <algorithm>
#include <iterator>
#include <limits>
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

stack<int> s;
stack<int> minS;
void push(int x)
{
    s.push(x);
    if (minS.empty())
    {
        minS.push(x);
    }
    else if (minS.top() < x)
    {
        minS.push(x);
    }
}
void pop()
{
    if (s.top() == minS.top())
    {
        s.pop();
        minS.pop();
    }
    else
    {
        s.pop();
    }
}

int getMIN()
{
    if (minS.empty())
    {
        return -1;
    }
    return minS.top();
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
}
