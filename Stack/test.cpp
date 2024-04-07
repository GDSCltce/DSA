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
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

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

inline void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        if(arr[i] < 0)
        sum += arr[i];
    }
    cout << abs(sum) << "\n";
}
