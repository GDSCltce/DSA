#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    multiset<int> st;
    // size of DSU
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
            parent.emplace_back(i);
        for (int i = 1; i <= n; i++)
        {
            st.insert(1);
        }
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
        st.erase(st.find(size[a]));
        st.erase(st.find(size[b]));
        st.insert(size[a] + size[b]);
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
    int n, k;
    cin >> n >> k;
    DSU ds(n);
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.Union(u, v);
        if (ds.st.size() == 1)
            cout << 0 << endl;
        else
        {
            int mn = *(ds.st.begin());
            int mx = *(--ds.st.end());
            cout << mx - mn << endl;
        }
    }
    return 0;
}