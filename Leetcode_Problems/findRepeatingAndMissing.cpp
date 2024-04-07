#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
/*************************************/

int miss = -1;
int rep = -1;

int *findTwoElement(vector<int> arr, int n)
{
    int xor1, setBITno, i;
    xor1 = arr[0];
    for (i = 1; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    for (i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }
    setBITno = xor1 & ~(xor1 - 1);
    int *ans = new int[2];
    for (int i = 0; i < 2; i++)
        ans[i] = 0;

    
    for (i = 0; i < n; i++)
    {
        if (arr[i] & setBITno)
            ans[1] ^= arr[i];
        else
            ans[0] ^= arr[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (i & setBITno)
            ans[1] ^= i;
        else
            ans[0] ^= i;
    }
    return ans;
}

void getTwoElementsEQ(const vector<int> arr)
{
    long long n = arr.size();
    long long S = (n * (n + 1)) / 2;
    // dbg(S)
    long long S2 = (n * (n + 1) * (n + n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        S -= arr[i];
        S2 -= (long long)arr[i] * arr[i];
    }
    int xpy = S2 / S;
    // dbg(xpy)
    miss = (xpy + S) / 2;
    rep = xpy - miss;
}

// 64676 61202
inline void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    getTwoElementsEQ(arr);
    cout << miss << space << rep << endl;
    int *ans = findTwoElement(arr, n);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << space;
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
