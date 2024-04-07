#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
// #define ll long long
#define space ' '
#define read(x) long long x; scanf("%lld", &x);
#define len(x) x.length()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef vector<pii> vpii;
typedef map<int,vector<int>> dil; 
// const int mod = 10e9+7;
/**************************/

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int mini = INT_MAX;
    int a = -1, b = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(arr[i] - arr[i + 1]) < mini)
        {
            mini = abs(arr[i] - arr[i + 1]);
            a = i, b = i + 1;
        }
    }

    if (abs(arr[0] - arr[n-1]) < mini)
    {
        mini = abs(arr[0] - arr[n-1]);
        a = 0, b = n-1;
    }

    cout << a + 1 << " " << b + 1 << ln;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    // read(t)    while(t--)
    {
        solve();
    }
    return 0;
}