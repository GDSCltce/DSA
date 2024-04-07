#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    vector<int> st;
    // size of DSU
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
            parent.emplace_back(i);

        st.assign(n + 1, 0);
        size.assign(n + 1, 1);
    }
    void make(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    // returns the parent of the given set
    int findParent(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = findParent(parent[v]);
    }
    void merge(int a, int b)
    {
        st[a] += st[b];
    }
    // Combines a, b set into a
    void Union(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            merge(a, b);
            size[a] += size[b];
        }
        return;
    }
};

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);

        int ans = -1;
        DSU ds(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ds.Union(x - 1, y - 1);
        }
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<int>anns(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x = ds.findParent(i);
            anns[x] += a[i];
        }
        

        cout << *max_element(anns.begin(), anns.end()) << endl;
    }
    return 0;
}