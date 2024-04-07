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

vector<int> findana(string s, string p)
{
            
}

inline void solve()
{
    string s;
    cin >> s;
    string pat;
    cin >> pat;
    int n = s.length();
    int m = pat.length();
    vector<int> ans = findana(s, pat);
    printArr(ans);
}
