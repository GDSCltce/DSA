#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define pii pair<int, int>
class segTree
{
    pii func(pii left, pii right)
    {
        int mx, mx2;
        mx = mx2 = -inf;
        mx = max(left.first, right.first);
        mx2 = min(max(left.first, right.second), max(right.first, left.second));
        return {mx, mx2};
    }
    int size, N;
    pii pre = {-inf, -inf}; // PRE
    vector<pii> tree;
    void init(int n)
    {
        N = n;
        size = 3 * N;
        tree.assign(size, pre); // ASSIGN
    }
    void buildSegTree(vector<int> &arr, int start, int end, int x)
    {
        if (start == end)
        {
            tree[x] = {arr[start], -inf};
            return;
        }
        int mid = (start + end) / 2;
        buildSegTree(arr, start, mid, 2 * x);
        buildSegTree(arr, mid + 1, end, 2 * x + 1);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }
    void update(vector<int> &arr, int i, int val, int x, int start, int end)
    {
        if (end == start)
        {
            arr[i] = val;
            tree[x] = {val, -inf};
            return;
        }
        int mid = (end + start) / 2;
        if (i > mid) // right
            update(arr, i, val, 2 * x + 1, mid + 1, end);
        else // left
            update(arr, i, val, 2 * x, start, mid);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }
    pii query(int start, int end, int x, int left, int right)
    {
        if (start > right || end < left)
            return pre; // RETURN
        if (start >= left && end <= right)
            return tree[x];
        int mid = (start + end) / 2;
        pii ans1 = query(start, mid, 2 * x, left, right);       // left
        pii ans2 = query(mid + 1, end, 2 * x + 1, left, right); // right
        return func(ans1, ans2);                                // FUNCTION
    }

public:
    segTree(int n)
    {
        init(n);
    }
    segTree(vector<int> &arr)
    {
        init(arr.size());
        buildSegTree(arr, 0, N - 1, 1);
    }
    void update(vector<int> &arr, int i, int val)
    {
        update(arr, i - 1, val, 1, 0, N - 1);
    }
    pii query(int l, int r)
    {
        return query(0, N - 1, 1, l - 1, r - 1);
    }
};

int main()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segTree st(arr);
    cin >> q;
    while (q--)
    {
        char u;
        int x, y;
        cin >> u >> x >> y;
        if (u == 'Q')
        {
            pii ans = st.query(x, y);
            cout << ans.first + ans.second << endl;
        }
        else
            st.update(arr, x, y);
    }

    return 0;
}
