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
    int pre = inf; // PRE
    vector<int> tree;
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
            tree[x] = arr[start];
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
            tree[x] = val;
            return;
        }
        int mid = (end + start) / 2;
        if (i > mid) // right
            update(arr, i, val, 2 * x + 1, mid + 1, end);
        else // left
            update(arr, i, val, 2 * x, start, mid);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }
    int query(int start, int end, int x, int left, int right)
    {
        if (start > right || end < left)
            return pre; // RETURN
        if (start >= left && end <= right)
            return tree[x];
        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2 * x, left, right);       // left
        int ans2 = query(mid + 1, end, 2 * x + 1, left, right); // right
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
    int query(int l, int r)
    {
        return query(0, N - 1, 1, l - 1, r - 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
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
            st.update(arr, x, y);
    }

    return 0;
}
    