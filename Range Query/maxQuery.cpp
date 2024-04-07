#include <bits/stdc++.h>
using namespace std;
#define inf 100000000000000
#define int long long
int n;
void buildSegTree(vector<int> &arr, vector<int> &tree, int start, int end, int x)
{
    if (start == end)
    {
        tree[x] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegTree(arr, tree, start, mid, 2 * x);
    buildSegTree(arr, tree, mid + 1, end, 2 * x + 1);
    tree[x] = max(tree[2 * x], tree[2 * x + 1]); // FUNCTION
}

int query(vector<int> &tree, int start, int end, int x, int left, int right)
{
    if (start > right || end < left)
        return -inf; // RETURN
    if (start >= left && end <= right)
        return tree[x];
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * x, left, right);       // left
    int ans2 = query(tree, mid + 1, end, 2 * x + 1, left, right); // right
    return max(ans1, ans2);                                // FUNCTION
}

void segTree(vector<int> &arr, vector <int> &tree)
{
    buildSegTree(arr, tree, 0, n - 1, 1);
}
int query(vector <int> &tree,int l, int r)
{
    return query(tree, 0, n - 1, 1, l - 1, r - 1);
}

signed main()
{
    int q;
    cin >> n;
    vector<int> arr(n), tree(4*n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;
    segTree(arr, tree);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << query(tree,x+1, y+1) << endl;
    }

    return 0;
}
        