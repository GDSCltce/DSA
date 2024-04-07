#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
class segTree
{
    int func(int a, int b)
    {
        return min(a, b);
    }
    int size, N;
    int pre = 0; // PRE
    vector<int> tree, lazy;
    void init(int n)
    {
        N = n;
        size = 3 * N;
        tree.assign(size, pre); // ASSIGN
        lazy.assign(size, pre); // ASSIGN
    }
    void buildSegTree(vector<int> &arr, int start, int end, int x)
    {
        if (start == end)
        {
            tree[x] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        buildSegTree(arr, start, mid, 2 * x);
        buildSegTree(arr, mid + 1, end, 2 * x + 1);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }
    void updateLazy(int start, int end, int left, int right, int x, int val)
    {
        if (start > end)
            return;
        if (lazy[x] != 0)
        {
            tree[x] += lazy[x];
            if (start != end)
            {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
            }
            lazy[x] = 0;
        }

        if (start > right || end < left) // No Overlap
            return;
        if (start >= left && end <= right) // Complete Overlap
        {
            tree[x] += val;
            if (start != end)
            {
                lazy[2 * x] += val;
                lazy[2 * x + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2; // Partial Overlap
        updateLazy(start, mid, left, right, 2 * x, val);
        updateLazy(mid + 1, end, left, right, 2 * x + 1, val);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]);
    }
    int queryLazy(int start, int end, int x, int left, int right)
    {
        if (start > end)
            return inf;
        if (lazy[x] != 0)
        {
            tree[x] += lazy[x];
            if (start != end)
            {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
            }
            lazy[x] = 0;
        }

        if (start > right || end < left) // No Overlap
            return inf;
        if (start >= left && end <= right) // Complete Overlap
            return tree[x];

        int mid = (start + end) / 2;
        int ans1 = queryLazy(start, mid, 2 * x, left, right);       // left
        int ans2 = queryLazy(mid + 1, end, 2 * x + 1, left, right); // right
        return func(ans1, ans2);                                    // FUNCTION
    }

public:
    segTree(vector<int> &arr)
    {
        init(arr.size());
        buildSegTree(arr, 0, N - 1, 1);
    }
    void update(int l, int r, int val)
    {
        updateLazy(0, N - 1, l - 1, r - 1, 1, val);
    }
    int query(int l, int r)
    {
        return queryLazy(0, N - 1, 1, l - 1, r - 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segTree st(arr);
    while (q--)
    {
        char u;
        int x, y;
        cin >> u >> x >> y;
        if (u == 'q')
        {
            cout << st.query(x, y) << endl;
        }
        else
        {
            int val;
            cin >> val;
            st.update(x, y, val);
        }
    }
    return 0;
}
