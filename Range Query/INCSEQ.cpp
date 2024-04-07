#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int tree[51][1000010];
const int MOD = 5000000;
int query(int i, int j)
{
    int res = 0;
    for (; i > 0; i -= (i & -i))
    {
        res = (res + tree[j][i]) % MOD;
    }
    return res;
}
void update(int i, int j, int val)
{
    for (; i <= 100005; i += (i & -i))
    {
        tree[j][i] = (tree[j][i] + val) % MOD;
    }
}
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int j = 1; j <= n; j++)
    {
        int a;
        cin >> a;
        a++;
        for (int i = 1; i <= k; i++)
        {
            int p = i == 1 ? 1 : query(a - 1, i - 1);
            update(a, i, p);
            if (i == k)
                ans = (ans + p) % MOD;
        }
    }
    cout << ans;
    return 0;
}
