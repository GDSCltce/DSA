#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

struct node
{
    int pos, l, r, val;
};
vector<node> a;
bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;
    return a.val > b.val;
}

void update(vector<int> &BIT, int n, int i)
{
    for (; i <= n; i += (i & -i))
        BIT[i]++;
}
int query(vector<int> &BIT, int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += BIT[i];

    return ans;
}

int main()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;
    vector<int> ql(n), qr(n), qval(n);
    for (int i = 0; i < q; i++)
    {
        cin >> ql[i] >> qr[i] >> qval[i];
    }
    node a[n + q + 1];
    for (int i = 1; i <= n; i++)
    {
        node temp;
        temp.l = 0, temp.r = i, temp.pos = 0, temp.val = arr[i - 1];
        a[i] = temp;
    }

    for (int i = n + 1; i <= n + q; i++)
    {
        node temp;
        temp.l = ql[i - n - 1];
        temp.r = qr[i - n - 1];
        temp.pos = i - n;
        temp.val = qval[i - n - 1];
        a[i] = temp;
    }
    sort(a + 1, a + n + q + 1, comp);
    vector<int> BIT(n + 1);
    vector<int> ans(q + 1);
    for (int i = 1; i <= n + q; i++)
    {
        if (a[i].pos != 0)
        {
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].pos] = cnt;
        }
        else
            update(BIT, n, a[i].r);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
