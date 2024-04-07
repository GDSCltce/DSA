#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define lINF 100000000000000000
#define int long long
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
bool pv(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
    return a.second < b.second;
}
/*------------ASIMARIES------------*/
void solve();
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
    cout << fixed << setprecision(6);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}

void solve()
{
    int s, d;
    cin >> s >> d;
    vector<int> arr(d);
    int val = s;
    arr[0] = 1;
    val--;
    for (int i = d - 1; i >= 0; i--)
    {
        if (val == 0)
        break;
        while (arr[i] <9 && val > 0)
        {
            arr[i]++, val--;
        }
    }
    for (auto &i : arr)
    {
        cout << i;
    }
    
    
    
}
