#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
#define MAX 100000

struct coder
{
    int x, y, index;
    coder(){}
    bool operator < (coder X)const{
        if(x != X.x) return x < X.x;
        return y < X.y;
    }
};

vector<int> bit(100001);
vector<int> ans(300000);
int query(int r)
{
    int res = 0;
    for (; r > 0; r -= (r & -r))
        res += bit[r];
    return res;
}
void update(int i)
{
    for (; i <= MAX; i += (i & -i))
        bit[i] += 1;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
    freopen("out.in", "w", stderr);
#endif
    int n, q;
    cin >> n;
    vector<coder> arr(300000);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }
    sort(arr.begin(), arr.begin()+n);
    for (int i = 0; i < n;)
    {
        int e = i;
        while (e < n && arr[i].x == arr[e].x && arr[i].y == arr[e].y)
            e++;

        for (int j = i; j < e;++j)
            ans[arr[j].index] = query(arr[j].y);

        for (int j = i; j < e; ++j)
            update(arr[j].y);
        i = e;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
