#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
vector<int> pow2(100001);
void buildpower()
{
    pow2[0] = 1;
    for (int i = 1; i < 100001; i++)
        pow2[i] = (pow2[i - 1] * 2) % 3;
}

class segTree
{
    int size, N;
    vector<int> tree;
    void init(int n)
    {
        N = n;
        size = 4 * N;
        tree.assign(size, 0); // ASSIGN
    }
    void buildSegTree(vector<int> &s, int start, int end, int x)
    {
        if (start == end)
        {
            tree[x] = s[start];
            return;
        }
        int mid = (start + end) / 2;
        buildSegTree(s, start, mid, 2 * x);
        buildSegTree(s, mid + 1, end, 2 * x + 1);
        tree[x] = (tree[2 * x] * pow2[end - mid] + tree[2 * x + 1]) % 3; // FUNCTION
    }
    void update(vector<int> &s, int i, int val, int x, int start, int end)
    {
        if (end == start)
        {
            s[i] = 1;
            tree[x] = 1;
            return;
        }
        int mid = (end + start) / 2;
        if (i > mid) // right
            update(s, i, val, 2 * x + 1, mid + 1, end);
        else // left
            update(s, i, val, 2 * x, start, mid);
        tree[x] = (tree[2 * x] * pow2[end - mid] + tree[2 * x + 1]) % 3; // FUNCTION
    }
    int query(int start, int end, int x, int left, int right)
    {
        if (start > right || end < left)
            return 0; // RETURN

        if (start >= left && end <= right)
            return (tree[x] * pow2[right - end]) % 3;

        int mid = (start + end) / 2;
        int ans1 = query(start, mid, 2 * x, left, right);       // left
        int ans2 = query(mid + 1, end, 2 * x + 1, left, right); // right
        return (ans1 + ans2) % 3;                               // FUNCTION
    }

public:
    segTree(int n)
    {
        init(n);
    }
    segTree(vector<int> &s)
    {
        init(s.size());
        buildSegTree(s, 0, N - 1, 1);
    }
    void update(vector<int> &s, int i, int val)
    {
        update(s, i - 1, val, 1, 0, N - 1);
    }
    int query(int l, int r)
    {
        return query(0, N - 1, 1, l - 1, r - 1);
    }
};

int main()
{
    buildpower();
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = s[i] - '0';
    }

    segTree st(arr);
    while (q--)
    {
        int u;
        int x, y;
        cin >> u;
        if (u == 0)
        {
            cin >> x >> y;
            cout << st.query(x + 1, y + 1) % 3 << endl;
        }
        else
        {
            int indx;
            cin >> indx;
            if(arr[indx]==0)
            st.update(arr, indx + 1, y);
        }
    }

    return 0;
}
