#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTree(vector<int> &a) : FenwickTree(a.size())
    {
        for (int i = 0; i < a.size(); i++)
            update(i, a[i]);
    }
    int query(int r)
    {
        int ans = 0;
        for (++r; r > 0; r -= (r & -r))
            ans += bit[r];
        return ans;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
    void update(int i, int x)
    {
        for (++i; i < n; i += i & -i)
            bit[i] += x;
    }
};

signed main()
{
    int n,q;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    FenwickTree FT(arr);
    cin >> q;
    while (q--)
    {
        int qry, x, y;
        cin >> qry >> x >> y;
        if (qry)
            cout << FT.query(x, y) << endl;
        else
            FT.update(x, y - arr[x]);
    }
    return 0;
}
