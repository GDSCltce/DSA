#include <bits/stdc++.h>
using namespace std;
#define inf 10000000
struct node
{
    int maxsum, sum, prefixsum, suffixsum;
};

class segTree
{
    node func(node a, node b)
    {
        node ans;
        ans.sum = a.sum + b.sum;
        ans.prefixsum = max(a.prefixsum, a.sum + b.prefixsum);
        ans.suffixsum = max(b.suffixsum, b.sum + a.suffixsum);
        ans.maxsum = max({a.maxsum,
                          b.maxsum,
                          a.sum + b.prefixsum,
                          b.sum + a.suffixsum,
                          a.suffixsum + b.prefixsum});
        return ans;
    }
    int size, N;
    const node pre = {-inf, -inf, -inf, -inf}; // PRE
    vector<node> tree;
    void init(int n)
    {
        N = n;
        size = 4 * N;
        tree.assign(size, pre); // ASSIGN
    }
    void buildSegTree(vector<int> &arr, int start, int end, int x)
    {
        if (start == end)
        {
            tree[x].sum = arr[start];
            tree[x].maxsum = arr[start];
            tree[x].prefixsum = arr[start];
            tree[x].suffixsum = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        buildSegTree(arr, start, mid, 2 * x);
        buildSegTree(arr, mid + 1, end, 2 * x + 1);
        tree[x] = func(tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }

    node query(int start, int end, int x, int left, int right)
    {
        if (start > right || end < left)
            return {}; // RETURN
        if (start >= left && end <= right)
            return tree[x];
        int mid = (start + end) / 2;
        node ans1 = query(start, mid, 2 * x, left, right);       // left
        node ans2 = query(mid + 1, end, 2 * x + 1, left, right); // right
        return func(ans1, ans2);                                 // FUNCTION
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
    node query(int l, int r)
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
        cin >> arr[i];
        
    segTree st(arr);
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        node ans = st.query(x, y);
        cout << ans.maxsum << endl;
    }
    return 0;
}
