#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
struct node
{
    int str, coward;
};

class segTree
{
    int func(vector<node> &arr, int a, int b)
    {
        if (arr[a].str > arr[b].str)
        {
            return a;
        }
        if (arr[a].str == arr[b].str)
        {
            if (arr[a].coward == arr[b].coward)
                return (a < b) ? a : b;
            else if (arr[a].coward < arr[b].coward)
                return a;
            else
                return b;
        }
        return b;
    }
    int size, N;
    int pre = inf; // PRE
    vector<int> tree;
    void init(int n)
    {
        N = n;
        size = 4 * N;
        tree.assign(size, pre); // ASSIGN
    }
    void buildSegTree(vector<node> &arr, int start, int end, int x)
    {
        if (start == end)
        {
            tree[x] = start;
            return;
        }
        int mid = (start + end) / 2;
        buildSegTree(arr, start, mid, 2 * x);
        buildSegTree(arr, mid + 1, end, 2 * x + 1);
        tree[x] = func(arr, tree[2 * x], tree[2 * x + 1]); // FUNCTION
    }
    int query(vector<node> &arr, int start, int end, int x, int left, int right)
    {
        if (start > right || end < left)
            return -1; // RETURN
        if (start >= left && end <= right)
            return tree[x];
        int mid = (start + end) / 2;
        int ans1 = query(arr, start, mid, 2 * x, left, right);       // left
        int ans2 = query(arr, mid + 1, end, 2 * x + 1, left, right); // right
        if (ans1 == -1)
            return ans2;
        if (ans2 == -1)
            return ans1;
        return func(arr, ans1, ans2); // FUNCTION
    }

public:
    segTree(int n)
    {
        init(n);
    }
    segTree(vector<node> &arr)
    {
        init(arr.size());
        buildSegTree(arr, 0, N - 1, 1);
    }
    int query(vector<node> &arr, int l, int r)
    {
        return query(arr, 0, N - 1, 1, l - 1, r - 1);
    }
};

int main()
{
    int n, q;
    cin >> n;
    vector<node> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].str;
    for (int i = 0; i < n; i++)
        cin >> arr[i].coward;

    segTree st(arr);
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << st.query(arr, x, y) + 1 << endl;
    }

    return 0;
}
