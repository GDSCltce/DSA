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
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
/*************************************/

inline void solve()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    cin >> k;
    int j;
    for (int i = 0; i <= n - k; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (arr[i + j] < 0)
            {
                cout << arr[i + j] << ' ';
                break;
            }
        }
        if (j == k)
        {
            cout << 0 << ' ';
        }
    }
    cout << "\noptimal\n";
    queue<int> dq;
    int i;
    for (i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            dq.push(i);
    }
    for (; i < n; i++)
    {

        if (!dq.empty())
        {
            cout << arr[dq.front()] << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
        while ((!dq.empty()) && dq.front() < (i - k + 1))
        {
            dq.pop();
        }
        if (arr[i] < 0)
        {
            dq.push(i);
        }
    }
    if (!dq.empty())
    {
        cout << arr[dq.front()] << ' ';
    }
    else
    {
        cout << 0 << ' ';
    }
    cout << "\nO1space\n";

    int fnegi = 0;
    int fnegE = 0;
    for (int i = k - 1; i < n; i++)
    {
        while ((fnegi < i) && (fnegi <= i - k || arr[fnegi] > 0))
        {
            fnegi++;
        }
        if (arr[fnegi] < 0)
        {
            fnegE = arr[fnegi];
        }
        else
        {
            fnegE = 0;
        }
        cout << fnegE << ' ';
    }
    
    cout <<"\n\n";
}
