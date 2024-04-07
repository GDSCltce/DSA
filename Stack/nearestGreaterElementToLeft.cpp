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
    vector<int> ans(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int temp;
    for (int i = n - 1; i >= 0; i--)
    {
        temp = -1;
        for (int j = i; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[j];
                break;
            }
        }
        ans[i] = temp;
    }
    cout << "Brute: ";
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << "\nStack O(n): ";

    stack<int> s;
    vector<int> anss(n);
    for (int i = 0; i < n; i++)
    {
        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
        }
        anss[i] = (s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    for (auto i : anss)
    {
        cout << i << ' ';
    }
}

// int num;
// cin >> num;
// // int temp = num;
// int n = log10(num) + 1;
// vector<int> arr(n);
// for (int i = n - 1; i >= 0; i--)
// {
//     arr[i] = num % 10;
//     num /= 10;
// }
// for (int i = n - 1; i >= 0; i--)
// {
//     if (arr[i] > arr[n - 1])
//     {
//         swap(arr[i], arr[n - 1]);
//         break;
//     }
// }

// for (int i = 0; i < n; i++)
// {
//     cout << arr[i] << ' ';
// }